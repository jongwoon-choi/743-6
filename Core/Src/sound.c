/*
 * sound.c
 *
 *  Created on: 2021. 8. 9.
 *      Author: hl3xs
 */
#include "sound.h"

UART_HandleTypeDef huart3;


void play(uint8_t Track) {
	uint8_t play[6] = { 0xAA, 0x07, 0x02, 0x00, Track, Track + 0xB3 };
	HAL_UART_Transmit(&huart3, play, sizeof(play), 100);
}

void volume(uint8_t vol) {
	uint8_t volume[5] = { 0xAA, 0x13, 0x01, vol, vol + 0xBE };
	HAL_UART_Transmit(&huart3, volume, sizeof(volume), 100);
}

void playstop(void) {
	uint8_t kend[4] = { 0xAA, 0x04, 0x00, 0xAE };
	HAL_UART_Transmit(&huart3, kend, sizeof(kend), 100);
}

void kend(void) {
	uint8_t kend[4] = { 0xAA, 0x10, 0x00, 0xBA };
	HAL_UART_Transmit(&huart3, kend, sizeof(kend), 100);
}

