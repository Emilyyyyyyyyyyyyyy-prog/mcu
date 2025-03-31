#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/spi.h"
#include "ili9341/include/ili9341.h"
#include "text_message/include/text_message.h"
#include "bme/include/bme.h"


int main() {
    stdio_init_all();
    init_SPI();
    init_display();
    init_drawing();

    gpio_put(13, 1);

    init_bme();
    gpio_put(17, 1);

    int32_t humidity, pressure, temperature;
    while (1) {
        gpio_put(17, 0);
        bme280_read_raw(&humidity, &pressure, &temperature);
        gpio_put(17, 1);

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

        gpio_put(13, 0);
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
        write_message(humi_2, 55, SCREEN_HEIGHT - 140, color, get_buffer());
        
        display_buffer();
        gpio_put(13, 1);
    }
}
