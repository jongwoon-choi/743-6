/*
 * sound.h
 *
 *  Created on: 2021. 8. 9.
 *      Author: hl3xs
 */

#ifndef INC_SOUND_H_
#define INC_SOUND_H_

#include "main.h"

void play(uint8_t Track);
void volume(uint8_t vol);
void playstop(void);
void kend(void);

#define S_Beek  	06
#define S_stop		07
#define S_clear  	 9
#define S_mute		10
#define S_sound  	11
#define S_hand		12
#define S_foot  	13
#define S_setup		14
#define S_calibration	15

#define S_cooling  	01
#define S_stamp		02
#define S_ready  	03
#define S_toning	04
#define S_Boook  	05
#define S_welcome	25
#define S_waring  	16
#define S_total_energy	17
#define S_total_count	18
#define S_12mm  	19
#define S_5mm		20
#define S_put-lens  21
#define S_get		22
#define S_read  	23
#define S_write		24



#endif /* INC_SOUND_H_ */


/*
 * 2:Beek, 3:stop, 4:clear, 5:mute, 6:sound, 7:hand, 8:foot, 9:setup,
 * 10:calibration, 11:cooling, 12:stamp, 13:ready, 14:toning, 15:Bookk,
 * 16:welcome to world of acne 17:waring
 *  18:Total energy  19:total count, 20:12mm  21:5mm, 22: Please put the collimated lens
 *  23:get 24:read, 25:write, 26:welcome to acneworld and ready to use
 */
