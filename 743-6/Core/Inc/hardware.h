/*
 * haredware.h
 *
 *  Created on: 2021. 10. 21.
 *  Author: hl3xs
 */

#ifndef INC_HARDWARE_H_
#define INC_HARDWARE_H_

#define CS_high  GPIOB, GPIO_PIN_5, GPIO_PIN_SET

// Task delay time allocation
#define Delay_task01		500  	// 초기화 후에 suspend
#define Delay_task02		5   	// GUI 키기능 해석 및 응답(UART1송신)
#define Delay_task03		1  		// HP값(UART4수신), DWIN 출력값(UART1수신)
#define Delay_task04		200  	//= 에너지 연산 후 화면표시(UART1송신)
#define Delay_task05		200  	//== ADC 처리후 GUI3 표시(UART1송신)
#define Delay_task06		10   	// foot/hand 스위치 읽고, DAC출력 레이저동작
#define Delay_task07		400  	//= GUI 화면 온도표시(UART1송신)
#define Delay_task08		100  	//
#define Delay_task09		100  	//
#define GUI_save_delay		1


#define Toning_ON			 80
#define threshold            490  	//Threshold of Temp. for 'Boook' beep


//EEPROM address table
#define Last_mode			 0x00
#define Last_sound			 0x01
#define Last_Count_energy	 0x02

#define Last_parameter 		 0x20  	// Parameter start address
#define Last_power_high  	 0x20
#define Last_power_low  	 0x21
#define Last_on_time_high    0x22
#define Last_on_time_low  	 0x23
#define Last_off_time_high   0x24
#define Last_off_time_low    0x25
#define Last_pulse  		 0x26
#define Last_repeat  		 0x27
#define Last_energy_high  	 0x28
#define Last_energy_low  	 0x29
#define Last_Hand_foot	     0x2A

#define Last_energy_high_t 	 0x2B
#define Last_energy_low_t  	 0x2C
#define Last_frequency  	 0x2D
#define Last_power_high_t    0x2E
#define Last_power_low_t   	 0x2F


#define Last_tcount_high	 0x30
#define Last_tcount_low	 	 0x31
#define Last_tenergy_high	 0x32
#define Last_tenergy_low	 0x33

// Still not used
#define Last_mon_power_high  	 0x34
#define Last_mon_power_low  	 0x35
#define Last_time_3  		 0x36
#define Last_time_4  		 0x37
#define Last_time_5  		 0x38
#define Last_time_6  		 0x39


// Used Parameter memory address
#define S1 					0x40 		// Memory start address
#define S1_power_high  	    S1+0x00
#define S1_power_low  		S1+0x01
#define S1_on_time_high  	S1+0x02
#define S1_on_time_low  	S1+0x03
#define S1_off_time_high 	S1+0x04
#define S1_off_time_low  	S1+0x05
#define S1_pulse  			S1+0x06
#define S1_repeat  			S1+0x07
#define S1_energy_high   	S1+0x08
#define S1_energy_low   	S1+0x09
#define S1_Hand_foot   		S1+0x0A

#define T1_energy_high_t   	S1+0x0B
#define T1_energy_low_t   	S1+0x0C
#define T1_frequency		S1+0x0D
#define T1_power_high_t   	S1+0x0E
#define T1_power_low_t   	S1+0x0F

#define S2 					S1+0x10
#define S2_power_high  	    S2+0x00
#define S2_power_low  		S2+0x01
#define S2_on_time_high  	S2+0x02
#define S2_on_time_low  	S2+0x03
#define S2_off_time_high 	S2+0x04
#define S2_off_time_low  	S2+0x05
#define S2_pulse  			S2+0x06
#define S2_repeat  			S2+0x07
#define S2_energy_high   	S2+0x08
#define S2_energy_low   	S2+0x09
#define S2_Hand_foot   		S2+0x0A

#define T2_energy_high_t   	S2+0x0B
#define T2_energy_low_t   	S2+0x0C
#define T2_frequency		S2+0x0D
#define T2_power_high_t   	S2+0x0E
#define T2_power_low_t   	S2+0x0F

#define S3 					S2+0x10
#define S3_power_high  	    S3+0x00
#define S3_power_low  		S3+0x01
#define S3_on_time_high  	S3+0x02
#define S3_on_time_low  	S3+0x03
#define S3_off_time_high 	S3+0x04
#define S3_off_time_low  	S3+0x05
#define S3_pulse  			S3+0x06
#define S3_repeat  			S3+0x07
#define S3_energy_high   	S3+0x08
#define S3_energy_low   	S3+0x09
#define S3_Hand_foot   		S3+0x0A

#define T3_energy_high_t   	S3+0x0B
#define T3_energy_low_t   	S3+0x0C
#define T3_frequency		S3+0x0D
#define T3_power_high_t   	S3+0x0E
#define T3_power_low_t   	S3+0x0F

#define S4 					S3+0x10
#define S4_power_high  	    S4+0x00
#define S4_power_low  		S4+0x01
#define S4_on_time_high  	S4+0x02
#define S4_on_time_low  	S4+0x03
#define S4_off_time_high 	S4+0x04
#define S4_off_time_low  	S4+0x05
#define S4_pulse  			S4+0x06
#define S4_repeat  			S4+0x07
#define S4_energy_high   	S4+0x08
#define S4_energy_low   	S4+0x09
#define S4_Hand_foot   		S4+0x0A

#define T4_energy_high_t   	S4+0x0B
#define T4_energy_low_t   	S4+0x0C
#define T4_frequency		S4+0x0D
#define T4_power_high_t   	S4+0x0E
#define T4_power_low_t   	S4+0x0F

#endif /* INC_HARDWARE_H_ */
