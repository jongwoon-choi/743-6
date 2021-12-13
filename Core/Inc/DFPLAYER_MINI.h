/*
 * DFPLAYER_MINI.h
 *
 *  Created on: May 16, 2020
 *      Author: controllerstech
 */

#ifndef INC_DFPLAYER_MINI_H_
#define INC_DFPLAYER_MINI_H_


void Send_cmd (uint8_t cmd, uint8_t Parameter1, uint8_t Parameter2);
void DF_PlayFromStart(void);
void DF_Init (uint8_t volume);
void DF_Play (uint16_t num);
void DF_MP3_play (uint16_t num);
void DF_Volume (uint16_t volume);
void DF_EQ (uint16_t eq);
void DF_reset (void);


#endif /* INC_DFPLAYER_MINI_H_ */
