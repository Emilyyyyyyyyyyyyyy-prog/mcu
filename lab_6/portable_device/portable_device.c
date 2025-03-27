 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <math.h>
 #include "pico/stdlib.h"
 #include "pico/binary_info.h"
 #include "hardware/spi.h"
 #include "ili9341.h"
 #include "text_message.h"

 
 #define READ_BIT 0x80
 
 int32_t t_fine;
 
 uint16_t dig_T1;
 int16_t dig_T2, dig_T3;
 uint16_t dig_P1;
 int16_t dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9;
 uint8_t dig_H1, dig_H3;
 int8_t dig_H6;
 int16_t dig_H2, dig_H4, dig_H5;
 
 /* The following compensation functions are required to convert from the raw ADC
 data from the chip to something usable. Each chip has a different set of
 compensation parameters stored on the chip at point of manufacture, which are
 read from the chip at startup and used in these routines.
 */
 int32_t compensate_temp(int32_t adc_T) {
     int32_t var1, var2, T;
     var1 = ((((adc_T >> 3) - ((int32_t) dig_T1 << 1))) * ((int32_t) dig_T2)) >> 11;
     var2 = (((((adc_T >> 4) - ((int32_t) dig_T1)) * ((adc_T >> 4) - ((int32_t) dig_T1))) >> 12) * ((int32_t) dig_T3))
             >> 14;
 
     t_fine = var1 + var2;
     T = (t_fine * 5 + 128) >> 8;
     return T;
 }
 
 uint32_t compensate_pressure(int32_t adc_P) {
     int32_t var1, var2;
     uint32_t p;
     var1 = (((int32_t) t_fine) >> 1) - (int32_t) 64000;
     var2 = (((var1 >> 2) * (var1 >> 2)) >> 11) * ((int32_t) dig_P6);
     var2 = var2 + ((var1 * ((int32_t) dig_P5)) << 1);
     var2 = (var2 >> 2) + (((int32_t) dig_P4) << 16);
     var1 = (((dig_P3 * (((var1 >> 2) * (var1 >> 2)) >> 13)) >> 3) + ((((int32_t) dig_P2) * var1) >> 1)) >> 18;
     var1 = ((((32768 + var1)) * ((int32_t) dig_P1)) >> 15);
     if (var1 == 0)
         return 0;
 
     p = (((uint32_t) (((int32_t) 1048576) - adc_P) - (var2 >> 12))) * 3125;
     if (p < 0x80000000)
         p = (p << 1) / ((uint32_t) var1);
     else
         p = (p / (uint32_t) var1) * 2;
 
     var1 = (((int32_t) dig_P9) * ((int32_t) (((p >> 3) * (p >> 3)) >> 13))) >> 12;
     var2 = (((int32_t) (p >> 2)) * ((int32_t) dig_P8)) >> 13;
     p = (uint32_t) ((int32_t) p + ((var1 + var2 + dig_P7) >> 4));
 
     return p;
 }
 
 uint32_t compensate_humidity(int32_t adc_H) {
     int32_t v_x1_u32r;
     v_x1_u32r = (t_fine - ((int32_t) 76800));
     v_x1_u32r = (((((adc_H << 14) - (((int32_t) dig_H4) << 20) - (((int32_t) dig_H5) * v_x1_u32r)) +
                    ((int32_t) 16384)) >> 15) * (((((((v_x1_u32r * ((int32_t) dig_H6)) >> 10) * (((v_x1_u32r *
                                                                                                   ((int32_t) dig_H3))
             >> 11) + ((int32_t) 32768))) >> 10) + ((int32_t) 2097152)) *
                                                  ((int32_t) dig_H2) + 8192) >> 14));
     v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * ((int32_t) dig_H1)) >> 4));
     v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
     v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);
 
     return (uint32_t) (v_x1_u32r >> 12);
 }
 
 #ifdef PICO_DEFAULT_SPI_CSN_PIN
 static inline void cs_select() {
     asm volatile("nop \n nop \n nop");
     gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 0);  // Active low
     asm volatile("nop \n nop \n nop");
 }
 
 static inline void cs_deselect() {
     asm volatile("nop \n nop \n nop");
     gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 1);
     asm volatile("nop \n nop \n nop");
 }
 #endif
 
 #if defined(spi_default) && defined(PICO_DEFAULT_SPI_CSN_PIN)
 static void write_register(uint8_t reg, uint8_t data) {
     uint8_t buf[2];
     buf[0] = reg & 0x7f;  // remove read bit as this is a write
     buf[1] = data;
     cs_select();
     spi_write_blocking(spi_default, buf, 2);
     cs_deselect();
     sleep_ms(10);
 }
 
 static void read_registers(uint8_t reg, uint8_t *buf, uint16_t len) {
     // For this particular device, we send the device the register we want to read
     // first, then subsequently read from the device. The register is auto incrementing
     // so we don't need to keep sending the register we want, just the first.
     reg |= READ_BIT;
     cs_select();
     spi_write_blocking(spi_default, &reg, 1);
     sleep_ms(10);
     spi_read_blocking(spi_default, 0, buf, len);
     cs_deselect();
     sleep_ms(10);
 }
 
 /* This function reads the manufacturing assigned compensation parameters from the device */
 void read_compensation_parameters() {
     uint8_t buffer[26];
 
     read_registers(0x88, buffer, 26);
 
     dig_T1 = buffer[0] | (buffer[1] << 8);
     dig_T2 = buffer[2] | (buffer[3] << 8);
     dig_T3 = buffer[4] | (buffer[5] << 8);
 
     dig_P1 = buffer[6] | (buffer[7] << 8);
     dig_P2 = buffer[8] | (buffer[9] << 8);
     dig_P3 = buffer[10] | (buffer[11] << 8);
     dig_P4 = buffer[12] | (buffer[13] << 8);
     dig_P5 = buffer[14] | (buffer[15] << 8);
     dig_P6 = buffer[16] | (buffer[17] << 8);
     dig_P7 = buffer[18] | (buffer[19] << 8);
     dig_P8 = buffer[20] | (buffer[21] << 8);
     dig_P9 = buffer[22] | (buffer[23] << 8);
 
     dig_H1 = buffer[25]; // 0xA1
 
     read_registers(0xE1, buffer, 8);
 
     dig_H2 = buffer[0] | (buffer[1] << 8); // 0xE1 | 0xE2
     dig_H3 = (int8_t) buffer[2]; // 0xE3
     dig_H4 = buffer[3] << 4 | (buffer[4] & 0xf); // 0xE4 | 0xE5[3:0]
     dig_H5 = (buffer[4] >> 4) | (buffer[5] << 4); // 0xE5[7:4] | 0xE6
     dig_H6 = (int8_t) buffer[6]; // 0xE7
 }
 
 static void bme280_read_raw(int32_t *humidity, int32_t *pressure, int32_t *temperature) {
     uint8_t buffer[8];
 
     read_registers(0xF7, buffer, 8);
     *pressure = ((uint32_t) buffer[0] << 12) | ((uint32_t) buffer[1] << 4) | (buffer[2] >> 4);
     *temperature = ((uint32_t) buffer[3] << 12) | ((uint32_t) buffer[4] << 4) | (buffer[5] >> 4);
     *humidity = (uint32_t) buffer[6] << 8 | buffer[7];
 }
 #endif

 
#define SPI_PORT spi0
#define PIN_MISO 16
#define PIN_CS   17
#define PIN_SCK  18
#define PIN_MOSI 19

 int main() {
    stdio_init_all();

    init_SPI();
    init_display();
    init_drawing();
 
     spi_init(spi_default, 500 * 1000);
     gpio_set_function(PICO_DEFAULT_SPI_RX_PIN, GPIO_FUNC_SPI);
     gpio_set_function(PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
     gpio_set_function(PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);
     // Make the SPI pins available to picotool
     bi_decl(bi_3pins_with_func(PICO_DEFAULT_SPI_RX_PIN, PICO_DEFAULT_SPI_TX_PIN, PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI));
 
     // Chip select is active-low, so we'll initialise it to a driven-high state
     gpio_init(PICO_DEFAULT_SPI_CSN_PIN);
     gpio_set_dir(PICO_DEFAULT_SPI_CSN_PIN, GPIO_OUT);
     gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 1);

     bi_decl(bi_1pin_with_name(PICO_DEFAULT_SPI_CSN_PIN, "SPI CS"));
 
     uint8_t id;
     read_registers(0xD0, &id, 1);
 
     read_compensation_parameters();
 
     write_register(0xF2, 0x1); // Humidity oversampling register - going for x1
     write_register(0xF4, 0x27);// Set rest of oversampling modes and run mode to normal
 
     int32_t humidity, pressure, temperature;

     while (1) {
        bme280_read_raw(&humidity, &pressure, &temperature);
        humidity = compensate_humidity(humidity) / 1024.0;
        pressure = compensate_pressure(pressure);
        temperature = compensate_temp(temperature) / 100.0;

        char temp_1[2];
        itoa(temperature, temp_1, 10);
        char temp_2[2];
        itoa((temperature-(float)(int)temperature)*100, temp_2, 10);

        char pres[5];
        itoa(pressure, pres, 10);

        char humi_1[2];
        itoa(humidity, humi_1, 10);
        char humi_2[2];
        itoa((humidity-(float)(int)humidity)*100, humi_2, 10);

        
        uint8_t color = 15;

        clear_buffer();
        write_message("ATMOSPHERIC INDICATORS", SCREEN_WIDTH - 40, SCREEN_HEIGHT - 40, color, get_buffer());
        write_message("TEMPERATURE", SCREEN_WIDTH - 40, SCREEN_HEIGHT - 100, color, get_buffer());
        write_message("PRESSURE", SCREEN_WIDTH - 40, SCREEN_HEIGHT - 120, color, get_buffer());
        write_message("HUMIDITY", SCREEN_WIDTH - 40, SCREEN_HEIGHT - 140, color, get_buffer());
        write_message(temp_1, SCREEN_WIDTH - 160, SCREEN_HEIGHT - 100, color, get_buffer());
        write_message(".", 63, SCREEN_HEIGHT - 100, color, get_buffer());
        write_message(temp_2, 55, SCREEN_HEIGHT - 100, color, get_buffer());
        write_message(pres, SCREEN_WIDTH - 160, SCREEN_HEIGHT - 120, color, get_buffer());
        write_message(humi_1, SCREEN_WIDTH - 160, SCREEN_HEIGHT - 140, color, get_buffer());
        write_message(".", 63, SCREEN_HEIGHT - 140, color, get_buffer());
        write_message(humi_2, SCREEN_WIDTH - 100, SCREEN_HEIGHT - 140, color, get_buffer());
        // write_message(h)
        display_buffer();
     }
 }
 