#include "text_message.h"
#include "ili9341.h"
#include <string.h>

static void inline draw_rectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t color, uint8_t* buffer)
{
    for (int i = y * SCREEN_WIDTH * 2; i < (SCREEN_WIDTH * y * 2) + (h * SCREEN_WIDTH * 2); i+=SCREEN_WIDTH * 2)
    {
        for (int j = x * 2; j < (x * 2) + (w * 2); j+=2)
        {
            buffer[i+j] = color;
            buffer[i+j+1] = color;
        }
    }
}

void write_message(char* mes, uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    uint16_t now_x = x, now_y = y;
    for (int i = 0; i < strlen(mes); i++) 
    {
        switch (mes[i])
        {
        case 'A':
            A(now_x, now_y, color, buffer); 
            break;
        case 'B':
            B(now_x, now_y, color, buffer);
            break;    
        case 'C':
            C(now_x, now_y, color, buffer);
            break;
        case 'D':
            D(now_x, now_y, color, buffer);
            break;
        case 'E':
            E(now_x, now_y, color, buffer);
            break;
        case 'F':
            F(now_x, now_y, color, buffer);
            break;
        case 'G':
            G(now_x, now_y, color, buffer);
            break;
        case 'H':
            H(now_x, now_y, color, buffer);
            break;
        case 'I':
            now_x += 5;
            I(now_x, now_y, color, buffer);
            break;
        case 'J':
            now_x += 4;
            J(now_x, now_y, color, buffer);
            break;
        case 'K':
            K(now_x, now_y, color, buffer);
            break;
        case 'L':
            L(now_x, now_y, color, buffer);
            break;
        case 'M':
            M(now_x, now_y, color, buffer);
            break;
        case 'N':
            N(now_x, now_y, color, buffer);
            break;
        case 'O':
            O(now_x, now_y, color, buffer);
            break;
        case 'P':
            now_x += 1;
            P(now_x, now_y, color, buffer);
            break;
        case 'Q':
            now_x--;
            Q(now_x, now_y, color, buffer);
            break;
        case 'R':
            R(now_x, now_y, color, buffer);
            break;
        case 'S':
            S(now_x, now_y, color, buffer);
            break;
        case 'T':
            T(now_x, now_y, color, buffer);
            break;
        case 'U':
            U(now_x, now_y, color, buffer);
            break;
        case 'V':
            V(now_x, now_y, color, buffer);
            break;
        case 'W':
            W(now_x, now_y, color, buffer);
            break;
        case 'X':
            X(now_x, now_y, color, buffer);
            break;
        case 'Y':
            Y(now_x, now_y, color, buffer);
            break;
        case 'Z':
            Z(now_x, now_y, color, buffer);
            break;
        case '1':
            now_x += 4;
            one(now_x, now_y, color, buffer);
            break;
        case '2':
            two(now_x, now_y, color, buffer);
            break;
        case '3':
            now_x += 1;
            three(now_x, now_y, color, buffer);
            break;
        case '4':
            four(now_x, now_y, color, buffer);
            break;
        case '5':
            five(now_x, now_y, color, buffer);
            break;
        case '6':
            six(now_x, now_y, color, buffer);
            break;
        case '7':
            seven(now_x, now_y, color, buffer);
            break;
        case '8':
            eight(now_x, now_y, color, buffer);
            break;
        case '9':
            nine(now_x, now_y, color, buffer);
            break;
        case '0':
            zero(now_x, now_y, color, buffer);
            break;
        case ' ':
            now_x -= 5;
            break;
        case '\n':
            now_y -= 17;
            now_x = x + 9;
            break;
        case '.':
            dot(now_x, now_y, color, buffer);
            break;
        default:
            break;
        }
        now_x -= 9;
        if (now_x <= 0) now_x = x;
    }
}

void A(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+1, 1, 6, color, buffer);
    draw_rectangle(x+1, y, 1, 10, color, buffer);
    draw_rectangle(x+2, y+3, 3, 2, color, buffer);
    draw_rectangle(x+2, y+7, 1, 5, color, buffer);
    draw_rectangle(x+3, y+10, 1, 3, color, buffer);
    draw_rectangle(x+4, y+7, 1, 5, color, buffer);
    draw_rectangle(x+5, y+1, 1, 10, color, buffer);
    draw_rectangle(x+6, y, 1, 7, color, buffer);
}

void B(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+2, y, 3, 1, color, buffer);
    draw_rectangle(x+1, y+1, 5, 1, color, buffer);
    draw_rectangle(x, y+2, 2, 4, color, buffer);
    draw_rectangle(x+1, y+6, 2, 1, color, buffer);
    draw_rectangle(x, y+7, 2, 3, color, buffer);
    draw_rectangle(x+1, y+10, 2, 1, color, buffer);
    draw_rectangle(x+1, y+11, 6, 1, color, buffer);
    draw_rectangle(x+2, y+12, 4, 1, color, buffer);
    draw_rectangle(x+4, y+2, 2, 9, color, buffer);
}

void C(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+2, y, 3, 1, color, buffer);
    draw_rectangle(x, y+1, 7, 1, color, buffer);
    draw_rectangle(x+4, y+2, 3, 1, color, buffer);
    draw_rectangle(x+5, y+3, 2, 8, color, buffer);
    draw_rectangle(x+1, y+9, 1, 1, color, buffer);
    draw_rectangle(x, y+10, 2, 1, color, buffer);
    draw_rectangle(x, y+11, 7, 1, color, buffer);
    draw_rectangle(x+1, y+12, 3, 1, color, buffer);
}

void D(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+2, y, 4, 1, color, buffer);
    draw_rectangle(x+1, y+1, 6, 1, color, buffer);
    draw_rectangle(x, y+2, 2, 8, color, buffer);
    draw_rectangle(x+5, y+2, 2, 9, color, buffer);
    draw_rectangle(x+1, y+10, 2, 1, color, buffer);
    draw_rectangle(x+1, y+11, 7, 1, color, buffer);
    draw_rectangle(x+2, y+12, 5, 1, color, buffer);
}

void E(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+1, y, 6, 1, color, buffer);
    draw_rectangle(x, y+1, 6, 1, color, buffer);
    draw_rectangle(x+4, y+2, 2, 9, color, buffer);
    draw_rectangle(x+1, y+6, 6, 1, color, buffer);
    draw_rectangle(x, y+7, 6, 1, color, buffer);
    draw_rectangle(x+1, y+11, 6, 1, color, buffer);
    draw_rectangle(x, y+12, 6, 1, color, buffer);
}

void F(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+4, y, 2, 11, color, buffer);
    draw_rectangle(x+1, y+6, 6, 1, color, buffer);
    draw_rectangle(x, y+7, 4, 1, color, buffer);
    draw_rectangle(x+1, y+11, 6, 1, color, buffer);
    draw_rectangle(x, y+12, 6, 1, color, buffer);
}

void G(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+2, y, 3, 1, color, buffer);
    draw_rectangle(x+1, y+1, 5, 1, color, buffer);
    draw_rectangle(x, y+2, 2, 3, color, buffer);
    draw_rectangle(x+1, y+5, 2, 1, color, buffer);
    draw_rectangle(x+4, y+2, 2, 1, color, buffer);
    draw_rectangle(x+5, y+3, 2, 7, color, buffer);
    draw_rectangle(x+1, y+8, 1, 1, color, buffer);
    draw_rectangle(x, y+9, 2, 1, color, buffer);
    draw_rectangle(x, y+10, 6, 1, color, buffer);
    draw_rectangle(x+1, y+11, 3, 1, color, buffer);
}

void H(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+1, 1, 11, color, buffer);
    draw_rectangle(x+1, y, 1, 11, color, buffer);
    draw_rectangle(x+2, y+10, 1, 1, color, buffer);
    draw_rectangle(x+4, y+1, 1, 11, color, buffer);
    draw_rectangle(x+5, y, 1, 11, color, buffer);
    draw_rectangle(x+2, y+5, 5, 1, color, buffer);
    draw_rectangle(x+2, y+6, 2, 1, color, buffer);
    draw_rectangle(x+6, y+10, 1, 1, color, buffer);
}

void I(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+1, 1, 11, color, buffer);
    draw_rectangle(x+1, y, 1, 11, color, buffer);
    draw_rectangle(x+2, y+10, 1, 1, color, buffer);
}

void J(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y, 1, 12, color, buffer);
    draw_rectangle(x+1, y-1, 1, 12, color, buffer);
    draw_rectangle(x+1, y-1, 2, 1, color, buffer);
    draw_rectangle(x+2, y-2, 2, 1, color, buffer);
    draw_rectangle(x+2, y+10, 2, 1, color, buffer);
}

void K(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y, 1, 2, color, buffer);
    draw_rectangle(x+1, y+1, 1, 3, color, buffer);
    draw_rectangle(x+2, y+3, 1, 3, color, buffer);
    draw_rectangle(x+3, y+5, 1, 2, color, buffer);
    draw_rectangle(x+2, y+7, 1, 1, color, buffer);
    draw_rectangle(x+1, y+8, 1, 1, color, buffer);
    draw_rectangle(x, y+9, 1, 1, color, buffer);
    draw_rectangle(x, y+10, 3, 1, color, buffer);
    draw_rectangle(x+1, y+11, 1, 1, color, buffer);
    draw_rectangle(x+3, y, 3, 1, color, buffer);
    draw_rectangle(x+4, y+1, 2, 10, color, buffer);
    draw_rectangle(x+4, y+11, 1, 1, color, buffer);
    draw_rectangle(x+6, y+10, 1, 1, color, buffer);
}

void L(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+1, y, 6, 1, color, buffer);
    draw_rectangle(x, y+1, 7, 1, color, buffer);
    draw_rectangle(x+5, y+2, 2, 9, color, buffer);
    draw_rectangle(x+7, y+10, 1, 1, color, buffer);
    draw_rectangle(x+5, y+11, 1, 1, color, buffer);
}

void M(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y, 1, 6, color, buffer);
    draw_rectangle(x+1, y+1, 1, 11, color, buffer);
    draw_rectangle(x, y+10, 1, 2, color, buffer);
    draw_rectangle(x+2, y+6, 1, 4, color, buffer);
    draw_rectangle(x+3, y+4, 1, 3, color, buffer);
    draw_rectangle(x+6, y, 1, 6, color, buffer);
    draw_rectangle(x+5, y+1, 1, 11, color, buffer);
    draw_rectangle(x+6, y+10, 1, 2, color, buffer);
    draw_rectangle(x+4, y+6, 1, 4, color, buffer);
}

void N(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y, 1, 13, color, buffer);
    draw_rectangle(x+1, y+2, 1, 10, color, buffer);
    draw_rectangle(x+2, y+4, 1, 5, color, buffer);
    draw_rectangle(x+3, y+6, 1, 5, color, buffer);
    draw_rectangle(x+4, y+1, 1, 12, color, buffer);
    draw_rectangle(x+5, y, 1, 13, color, buffer);
    draw_rectangle(x+6, y+11, 1, 2, color, buffer);
}

void O(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+2, 1, 8, color, buffer);
    draw_rectangle(x+1, y+1, 1, 11, color, buffer);
    draw_rectangle(x+1, y+1, 6, 1, color, buffer);
    draw_rectangle(x+4, y, 2, 1, color, buffer);
    draw_rectangle(x+2, y+10, 1, 3, color, buffer);
    draw_rectangle(x+3, y+11, 3, 2, color, buffer);
    draw_rectangle(x+6, y+12, 1, 1, color, buffer);
    draw_rectangle(x+5, y+2, 2, 1, color, buffer);
    draw_rectangle(x+6, y+3, 1, 7, color, buffer);
    draw_rectangle(x+7, y+3, 1, 6, color, buffer);
}

void P(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+6, 1, 4, color, buffer);
    draw_rectangle(x+1, y+5, 1, 7, color, buffer);
    draw_rectangle(x+2, y+5, 1, 1, color, buffer);
    draw_rectangle(x+2, y+10, 1, 3, color, buffer);
    draw_rectangle(x+3, y+11, 1, 2, color, buffer);
    draw_rectangle(x+4, y+1, 1, 12, color, buffer);
    draw_rectangle(x+5, y, 1, 13, color, buffer);
    draw_rectangle(x+6, y+11, 1, 1, color, buffer);
}

void Q(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+1, y-1, 2, 1, color, buffer);
    draw_rectangle(x, y, 7, 1, color, buffer);
    draw_rectangle(x+4, y+1, 4, 1, color, buffer);
    draw_rectangle(x+6, y+2, 2, 1, color, buffer);
    draw_rectangle(x+7, y+3, 2, 8, color, buffer);
    draw_rectangle(x, y+5, 1, 7, color, buffer);
    draw_rectangle(x+1, y+2, 1, 10, color, buffer);
    draw_rectangle(x+2, y+10, 1, 3, color, buffer);
    draw_rectangle(x+3, y+11, 3, 2, color, buffer);
    draw_rectangle(x+6, y+11, 2, 1, color, buffer);
}

void R(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+1, 1, 5, color, buffer);
    draw_rectangle(x+1, y, 1, 12, color, buffer);
    draw_rectangle(x, y+7, 1, 3, color, buffer);
    draw_rectangle(x+1, y+6, 2, 1, color, buffer);
    draw_rectangle(x+4, y+1, 1, 12, color, buffer);
    draw_rectangle(x+5, y, 1, 13, color, buffer);
    draw_rectangle(x+2, y+11, 2, 2, color, buffer);
    draw_rectangle(x+6, y+11, 1, 1, color, buffer);
}

void S(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+2, 1, 3, color, buffer);
    draw_rectangle(x+1, y+1, 1, 5, color, buffer);
    draw_rectangle(x+3, y, 3, 1, color, buffer);
    draw_rectangle(x+2, y+1, 6, 1, color, buffer);
    draw_rectangle(x+5, y+2, 1, 1, color, buffer);
    draw_rectangle(x+2, y+4, 1, 3, color, buffer);
    draw_rectangle(x+3, y+5, 1, 3, color, buffer);
    draw_rectangle(x+4, y+6, 1, 3, color, buffer);
    draw_rectangle(x+5, y+7, 1, 5, color, buffer);
    draw_rectangle(x+6, y+8, 1, 3, color, buffer);
    draw_rectangle(x+1, y+11, 4, 1, color, buffer);
    draw_rectangle(x+2, y+10, 1, 1, color, buffer);
    draw_rectangle(x+2, y+12, 3, 1, color, buffer);
}

void T(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+3, y+1, 1, 10, color, buffer);
    draw_rectangle(x+4, y, 1, 10, color, buffer);
    draw_rectangle(x, y+12, 6, 1, color, buffer);
    draw_rectangle(x+1, y+11, 6, 1, color, buffer);
}

void U(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+1, 7, 1, color, buffer);
    draw_rectangle(x+1, y+1, 1, 12, color, buffer);
    draw_rectangle(x+2, y, 1, 12, color, buffer);
    draw_rectangle(x+4, y, 2, 1, color, buffer);
    draw_rectangle(x+5, y+2, 1, 11, color, buffer);
    draw_rectangle(x+6, y+2, 1, 10, color, buffer);
}

void V(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+7, 1, 6, color, buffer);
    draw_rectangle(x+1, y+3, 1, 9, color, buffer);
    draw_rectangle(x+2, y+1, 1, 6, color, buffer);
    draw_rectangle(x+3, y, 1, 3, color, buffer);
    draw_rectangle(x+4, y+1, 1, 6, color, buffer);
    draw_rectangle(x+5, y+3, 1, 10, color, buffer);
    draw_rectangle(x+6, y+7, 1, 5, color, buffer);
}

void W(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+4, 1, 9, color, buffer);
    draw_rectangle(x+1, y, 1, 4, color, buffer);
    draw_rectangle(x+2, y+1, 1, 12, color, buffer);
    draw_rectangle(x+3, y+4, 1, 8, color, buffer);
    draw_rectangle(x+4, y, 1, 4, color, buffer);
    draw_rectangle(x+5, y+1, 1, 12, color, buffer);
    draw_rectangle(x+6, y+4, 1, 8, color, buffer);
}

void X(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+1, 1, 1, color, buffer);
    draw_rectangle(x+1, y, 1, 4, color, buffer);
    draw_rectangle(x+2, y+1, 1, 5, color, buffer);
    draw_rectangle(x+3, y+4, 1, 4, color, buffer);
    draw_rectangle(x, y+11, 1, 1, color, buffer);
    draw_rectangle(x+1, y+9, 1, 3, color, buffer);
    draw_rectangle(x+2, y+7, 1, 2, color, buffer);
    draw_rectangle(x+4, y+5, 1, 4, color, buffer);
    draw_rectangle(x+5, y, 1, 1, color, buffer);
    draw_rectangle(x+6, y, 1, 3, color, buffer);
    draw_rectangle(x+5, y+3, 1, 2, color, buffer);
    draw_rectangle(x+5, y+7, 1, 5, color, buffer);
    draw_rectangle(x+6, y+9, 1, 3, color, buffer);
}

void Y(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+9, 1, 3, color, buffer);
    draw_rectangle(x+1, y+6, 1, 3, color, buffer);
    draw_rectangle(x+1, y+11, 1, 2, color, buffer);
    draw_rectangle(x+2, y+11, 1, 1, color, buffer);
    draw_rectangle(x+2, y+1, 1, 5, color, buffer);
    draw_rectangle(x+3, y, 1, 7, color, buffer);
    draw_rectangle(x+4, y+4, 1, 7, color, buffer);
    draw_rectangle(x+5, y+7, 1, 6, color, buffer);
    draw_rectangle(x+6, y+11, 1, 2, color, buffer);
}

void Z(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+1, y, 5, 1, color, buffer);
    draw_rectangle(x, y+1, 7, 1, color, buffer);
    draw_rectangle(x+5, y+2, 1, 2, color, buffer);
    draw_rectangle(x+4, y+3, 1, 3, color, buffer);
    draw_rectangle(x+3, y+5, 1, 3, color, buffer);
    draw_rectangle(x+2, y+7, 1, 5, color, buffer);
    draw_rectangle(x+1, y+9, 1, 3, color, buffer);
    draw_rectangle(x, y+11, 1, 1, color, buffer);
    draw_rectangle(x, y+11, 7, 1, color, buffer);
    draw_rectangle(x+1, y+10, 5, 1, color, buffer);
    draw_rectangle(x+6, y+12, 1, 1, color, buffer);
}

void one(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+1, 1, 12, color, buffer);
    draw_rectangle(x+1, y, 1, 12, color, buffer);
    draw_rectangle(x+2, y+12, 1, 1, color, buffer);
}

void two(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+1, y, 6, 1, color, buffer);
    draw_rectangle(x, y+1, 7, 1, color, buffer);
    draw_rectangle(x+4, y+2, 2, 1, color, buffer);
    draw_rectangle(x+3, y+3, 2, 1, color, buffer);
    draw_rectangle(x+2, y+4, 2, 1, color, buffer);
    draw_rectangle(x+1, y+5, 2, 1, color, buffer);
    draw_rectangle(x+1, y+6, 1, 1, color, buffer);
    draw_rectangle(x, y+7, 2, 3, color, buffer);
    draw_rectangle(x+1, y+10, 2, 2, color, buffer);
    draw_rectangle(x+2, y+12, 2, 1, color, buffer);
    draw_rectangle(x+3, y+11, 3, 1, color, buffer);
    draw_rectangle(x+5, y+9, 2, 2, color, buffer);
    draw_rectangle(x+6, y+8, 1, 1, color, buffer);
}

void three(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+3, 1, 4, color, buffer);
    draw_rectangle(x, y+10, 1, 2, color, buffer);
    draw_rectangle(x+1, y+2, 1, 6, color, buffer);
    draw_rectangle(x+1, y+9, 1, 4, color, buffer);
    draw_rectangle(x+2, y+1, 1, 2, color, buffer);
    draw_rectangle(x+2, y+6, 1, 3, color, buffer);
    draw_rectangle(x+2, y+11, 1, 2, color, buffer);
    draw_rectangle(x+3, y, 1, 2, color, buffer);
    draw_rectangle(x+4, y, 1, 1, color, buffer);
    draw_rectangle(x+3, y+6, 1, 2, color, buffer);
    draw_rectangle(x+4, y+6, 1, 1, color, buffer);
    draw_rectangle(x+3, y+12, 2, 1, color, buffer);
    draw_rectangle(x+5, y+11, 1, 1, color, buffer);
}

void four(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+1, 1, 8, color, buffer);
    draw_rectangle(x+1, y, 1, 8, color, buffer);
    draw_rectangle(x+2, y+5, 4, 1, color, buffer);
    draw_rectangle(x+4, y+6, 2, 2, color, buffer);
    draw_rectangle(x+3, y+8, 2, 2, color, buffer);
    draw_rectangle(x+2, y+10, 2, 1, color, buffer);
    draw_rectangle(x+1, y+11, 2, 1, color, buffer);
    draw_rectangle(x, y+12, 2, 1, color, buffer);
}

void five(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+3, 1, 3, color, buffer);
    draw_rectangle(x+1, y+2, 1, 5, color, buffer);
    draw_rectangle(x+2, y+1, 1, 2, color, buffer);
    draw_rectangle(x+3, y, 1, 2, color, buffer);
    draw_rectangle(x+4, y, 1, 1, color, buffer);
    draw_rectangle(x+2, y+6, 1, 2, color, buffer);
    draw_rectangle(x+3, y+7, 4, 2, color, buffer);
    draw_rectangle(x+6, y+7, 1, 4, color, buffer);
    draw_rectangle(x+2, y+11, 4, 1, color, buffer);
    draw_rectangle(x+1, y+12, 5, 1, color, buffer);
}

void six(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+2, 1, 6, color, buffer);
    draw_rectangle(x+1, y+1, 1, 8, color, buffer);
    draw_rectangle(x+2, y+1, 4, 1, color, buffer);
    draw_rectangle(x+3, y, 2, 1, color, buffer);
    draw_rectangle(x+2, y+7, 1, 2, color, buffer);
    draw_rectangle(x+3, y+8, 1, 1, color, buffer);
    draw_rectangle(x+5, y+2, 2, 8, color, buffer);
    draw_rectangle(x+4, y+10, 2, 1, color, buffer);
    draw_rectangle(x+3, y+11, 2, 1, color, buffer);
    draw_rectangle(x+2, y+12, 2, 1, color, buffer);
}

void seven(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+10, 1, 3, color, buffer);
    draw_rectangle(x+1, y+8, 1, 5, color, buffer);
    draw_rectangle(x+2, y+6, 1, 4, color, buffer);
    draw_rectangle(x+2, y+11, 4, 2, color, buffer);
    draw_rectangle(x+6, y+12, 1, 1, color, buffer);
    draw_rectangle(x+4, y+13, 1, 1, color, buffer);
    draw_rectangle(x+3, y+2, 1, 6, color, buffer);
    draw_rectangle(x+4, y+1, 1, 5, color, buffer);
    draw_rectangle(x+5, y, 1, 3, color, buffer);
}

void eight(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+2, 1, 3, color, buffer);
    draw_rectangle(x, y+8, 1, 4, color, buffer);
    draw_rectangle(x+1, y+1, 1, 5, color, buffer);
    draw_rectangle(x+1, y+7, 1, 6, color, buffer);
    draw_rectangle(x+2, y, 3, 1, color, buffer);
    draw_rectangle(x+2, y+4, 1, 4, color, buffer);
    draw_rectangle(x+2, y+11, 1, 2, color, buffer);
    draw_rectangle(x+3, y+11, 1, 1, color, buffer);
    draw_rectangle(x+3, y+5, 1, 3, color, buffer);
    draw_rectangle(x+4, y+5, 1, 4, color, buffer);
    draw_rectangle(x+5, y+1, 1, 5, color, buffer);
    draw_rectangle(x+5, y+7, 1, 5, color, buffer);
    draw_rectangle(x+6, y+2, 1, 3, color, buffer);
    draw_rectangle(x+6, y+8, 1, 3, color, buffer);
}

void nine(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+4, 1, 6, color, buffer);
    draw_rectangle(x+1, y+3, 1, 9, color, buffer);
    draw_rectangle(x+2, y+2, 1, 2, color, buffer);
    draw_rectangle(x+3, y+1, 1, 2, color, buffer);
    draw_rectangle(x+4, y, 1, 2, color, buffer);
    draw_rectangle(x+5, y, 1, 1, color, buffer);
    draw_rectangle(x+2, y+10, 1, 3, color, buffer);
    draw_rectangle(x+3, y+11, 1, 2, color, buffer);
    draw_rectangle(x+4, y+11, 2, 1, color, buffer);
    draw_rectangle(x+5, y+7, 2, 4, color, buffer);
    draw_rectangle(x+4, y+7, 1, 1, color, buffer);
    draw_rectangle(x+3, y+6, 3, 1, color, buffer);
}

void zero(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x, y+2, 1, 8, color, buffer);
    draw_rectangle(x+1, y+1, 1, 11, color, buffer);
    draw_rectangle(x+1, y+1, 5, 1, color, buffer);
    draw_rectangle(x+3, y, 2, 1, color, buffer);
    draw_rectangle(x+4, y+2, 2, 1, color, buffer);
    draw_rectangle(x+5, y+3, 1, 7, color, buffer);
    draw_rectangle(x+6, y+3, 1, 6, color, buffer);
    draw_rectangle(x+2, y+10, 1, 3, color, buffer);
    draw_rectangle(x+3, y+11, 2, 2, color, buffer);
    draw_rectangle(x+5, y+11, 1, 1, color, buffer);
}

void dot(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer) 
{
    draw_rectangle(x+4, y, 2, 2, color, buffer);
}