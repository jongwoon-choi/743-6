/*
 * DFPLAYER_MINI.c
 *
 *  Created on: May 16, 2020
 *      Author: controllerstech
 */


#include "main.h"
#include "stdio.h"

#define Source      0x02  // TF CARD


/*************************************** NO CHANGES AFTER THIS *************************************************/

extern UART_HandleTypeDef huart3;
# define Start_Byte 0x7E
# define End_Byte   0xEF
# define Version    0xFF
# define Cmd_Len    0x06
# define Feedback   0x00    //If need for Feedback: 0x01,  No Feedback: 0


void Send_cmd (uint8_t cmd, uint8_t Parameter1, uint8_t Parameter2)
{
	uint16_t Checksum = Version + Cmd_Len + cmd + Feedback + Parameter1 + Parameter2;
	Checksum = 0-Checksum;

	uint8_t CmdSequence[10] = { Start_Byte, Version, Cmd_Len, cmd, Feedback, Parameter1, Parameter2, (Checksum>>8)&0x00ff, (Checksum&0x00ff), End_Byte};

	HAL_UART_Transmit(&huart3, CmdSequence, 10, 100);
}

void DF_PlayFromStart(void)
{
  Send_cmd(0x03,0x00,0x01);
  HAL_Delay(200);
}


void DF_Init (uint8_t volume)
{
	Send_cmd(0x3F, 0x00, Source);
	HAL_Delay(200);
	Send_cmd(0x06, 0x00, volume);
	HAL_Delay(500);
}

void DF_Play (uint16_t num)
{
	Send_cmd(0x03, 0x00, num);
	HAL_Delay(200);
}

//play mp3 file in mp3 folder in your tf card
// This is not working function
void DF_MP3_play (uint16_t num) {
	Send_cmd(0x12, 0x00, num);
	HAL_Delay(200);
}

//0x06 set volume 0-30
void DF_Volume (uint16_t volume) {
	Send_cmd(0x06, 0x00, volume);
	HAL_Delay(200);
}

//0x07 set EQ0/1/2/3/4/5    Normal/Pop/Rock/Jazz/Classic/Bass
void DF_EQ (uint16_t eq) {
	Send_cmd(0x07, 0x00, eq);
	HAL_Delay(200);
}

void DF_reset (void) {
	Send_cmd(0x0c, 0x00, 0x00);
	HAL_Delay(200);
}















