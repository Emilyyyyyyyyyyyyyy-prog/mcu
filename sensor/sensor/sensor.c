#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT spi0
#define SENSOR_SCK 6  // GP6 (SPI0_SCK)
#define SENSOR_OUT 4   // GP4 (SPI0_MISO)

void init_spi() {
    spi_init(SPI_PORT, 1000000); // 1 MHz SPI clock
    gpio_set_function(SENSOR_SCK, GPIO_FUNC_SPI);
    gpio_set_function(SENSOR_OUT, GPIO_FUNC_SPI);
}

uint16_t read_sensor() {
    uint8_t rx_buf[2] = {0};
    spi_read_blocking(SPI_PORT, 0, rx_buf, 2); // Read 2 bytes
    return (rx_buf[0] << 8) | rx_buf[1]; // Combine bytes
}

int main()
{
    stdio_init_all();
    init_spi();

    while (true) {
        uint16_t data = read_sensor();
        printf("Sensor value: %u\n", data);
        sleep_ms(250);
    }
}
