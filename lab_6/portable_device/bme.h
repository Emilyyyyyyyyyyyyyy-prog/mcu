#pragma once

#include <stdint.h>
#include <stdio.h>
#include <string.h>


#define READ_BIT 0x80

int32_t t_fine;

uint16_t dig_T1;
int16_t dig_T2, dig_T3;
uint16_t dig_P1;
int16_t dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9;
uint8_t dig_H1, dig_H3;
int8_t dig_H6;
int16_t dig_H2, dig_H4, dig_H5;

int32_t compensate_temp(int32_t adc_T);
uint32_t compensate_pressure(int32_t adc_P);
uint32_t compensate_humidity(int32_t adc_H);
// #ifdef PICO_DEFAULT_SPI_CSN_PIN
// static inline void cs_select();
// static inline void cs_deselect();
// #endif

static void write_register(uint8_t reg, uint8_t data);
static void read_registers(uint8_t reg, uint8_t *buf, uint16_t len);
void read_compensation_parameters();
static void bme280_read_raw(int32_t *humidity, int32_t *pressure, int32_t *temperature);

