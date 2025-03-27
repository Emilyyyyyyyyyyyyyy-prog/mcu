#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "square-swarm.h"
#include "ili9341.h"
#include "gradient.h"
#include "ant-lab.h"
#include "text_message.h"

// SPI Defines
// We are going to use SPI 0, and allocate it to the following GPIO pins
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define SPI_PORT spi0
#define PIN_MISO 16
#define PIN_CS   17
#define PIN_SCK  18
#define PIN_MOSI 19


int main()
{
    stdio_init_all();

    init_SPI();
    init_display();
    init_drawing();

    // while (true)
    // {
    //     clear_buffer();
    //     write_message("ABCDEF/GHIJKLM/NOPQRS/TUVWXYZ/1234567890", 40, SCREEN_WIDTH/2 + 20, SCREEN_HEIGHT/2 + 50, 20, get_buffer());
    //     display_buffer();
    // }
    

    // while (true)
    // {
    //     clear_buffer();
    //     draw_antlab(get_buffer());
    //     display_buffer();
    // }
    

    // while (true)
    // {
    //     clear_buffer();
    //     make_gradient(50, get_buffer());
    //     display_buffer();
    // }
    

    // uint32_t playerCount = 50;

    // struct Square player[playerCount];

    // for (int i = 0; i < playerCount; i++)
    // {
    //     player[i].x = rand() % 209;
    //     player[i].y = rand() % 289;
    //     player[i].w = 15;
    //     player[i].h = 15;
    //     player[i].xVelocity = rand() % 4 - 2;
    //     player[i].yVelocity = rand() % 4 - 2;

    //     if (player[i].xVelocity == 0 && player[i].yVelocity == 0)
    //     {
    //         player[i].xVelocity = 3;
    //         player[i].yVelocity = 3;
    //     }

    //     player[i].color = rand() % 255;
    // }

    // while (true) {
    //     clear_buffer();
    //     handle_square_swarm(player, playerCount, get_buffer());
    //     display_buffer();
    //     // display_external_buffer(get_antlab_image_buffer());
    // }
}


// int main()
// {
//     stdio_init_all();

//     // SPI initialisation. This example will use SPI at 1MHz.
//     spi_init(SPI_PORT, 1000*1000);
//     gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
//     gpio_set_function(PIN_CS,   GPIO_FUNC_SIO);
//     gpio_set_function(PIN_SCK,  GPIO_FUNC_SPI);
//     gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
    
//     // Chip select is active-low, so we'll initialise it to a driven-high state
//     gpio_set_dir(PIN_CS, GPIO_OUT);
//     gpio_put(PIN_CS, 1);
//     // For more examples of SPI use see https://github.com/raspberrypi/pico-examples/tree/master/spi

//     while (true) {
//         printf("Hello, world!\n");
//         sleep_ms(1000);
//     }
// }
