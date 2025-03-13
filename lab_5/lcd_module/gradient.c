#include "gradient.h"
#include "ili9341.h"

// uint16_t colour(uint8_t R, uint8_t G, uint8_t B) {
//     return (((G & 0b00011100) << 3) + ((R & 0b11111000) >> 3) << 8) + (B & 0b11111000) + ((G & 0b11100000) >> 5);
// }

uint16_t colour(uint8_t R, uint8_t G, uint8_t B) {
    uint16_t result;
    result = (uint16_t)(((G & 0b00011100) << 3) + ((R & 0b11111000) >> 3));
    result <<= 8;
    result += (uint16_t)((B & 0b11111000) + ((G & 0b11100000) >> 5));
    return result;
}


void make_gradient(uint8_t color, uint8_t* buffer) 
{
    for (int y = 0; y < SCREEN_HEIGHT; y += (SCREEN_HEIGHT / 6)) 
    {
        // draw_rectangle(0, y, SCREEN_WIDTH, SCREEN_HEIGHT / 6, color, buffer);
        for (int i = y * SCREEN_WIDTH * 2; i < (SCREEN_WIDTH * y * 2) + (SCREEN_HEIGHT / 6 * SCREEN_WIDTH * 2); i+=SCREEN_WIDTH * 2)
        {
            for (int j = 0; j < SCREEN_WIDTH* 2; j+=2)
            {
                buffer[i+j] = color;
                buffer[i+j+1] = color;
            }
        }
        color += 1;
        // color %= 255;
    }
}