/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "rtc.h"
#include "usart.h"
#include "parameter.h"
#include "hardware.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
	uint8_t text[20];
	RTC_DateTypeDef sdatestructureget  ;
	RTC_TimeTypeDef stimestructureget  ;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

	void push(uart_t *u, uint8_t data);
	uint8_t pop(uart_t *u);
	uint8_t isEmpty(uart_t *u);
	float ttt;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId myTask02Handle;
osThreadId myTask03Handle;
osThreadId myTask04Handle;
osThreadId myTask05Handle;
osThreadId myTask06Handle;
osThreadId myTask07Handle;
osThreadId myTask08Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

static void RTC_CalendarShow(RTC_DateTypeDef *sdatestructureget,RTC_TimeTypeDef *stimestructureget)
{
   /* Both time and date must be obtained or RTC cannot be read next time */
  /* Get the RTC current Time */
  HAL_RTC_GetTime(&hrtc, stimestructureget, RTC_FORMAT_BIN);
  /* Get the RTC current Date */
  HAL_RTC_GetDate(&hrtc, sdatestructureget, RTC_FORMAT_BIN);
}
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);
void StartTask03(void const * argument);
void StartTask04(void const * argument);
void StartTask05(void const * argument);
void StartTask06(void const * argument);
void StartTask07(void const * argument);
void StartTask08(void const * argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}


/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myTask02 */
  osThreadDef(myTask02, StartTask02, osPriorityNormal, 0, 256);
  myTask02Handle = osThreadCreate(osThread(myTask02), NULL);

  /* definition and creation of myTask03 */
  osThreadDef(myTask03, StartTask03, osPriorityNormal, 0, 128);
  myTask03Handle = osThreadCreate(osThread(myTask03), NULL);

  /* definition and creation of myTask04 */
  osThreadDef(myTask04, StartTask04, osPriorityNormal, 0, 128);
  myTask04Handle = osThreadCreate(osThread(myTask04), NULL);

  /* definition and creation of myTask05 */
  osThreadDef(myTask05, StartTask05, osPriorityNormal, 0, 128);
  myTask05Handle = osThreadCreate(osThread(myTask05), NULL);

  /* definition and creation of myTask06 */
  osThreadDef(myTask06, StartTask06, osPriorityNormal, 0, 128);
  myTask06Handle = osThreadCreate(osThread(myTask06), NULL);

  /* definition and creation of myTask07 */
  osThreadDef(myTask07, StartTask07, osPriorityNormal, 0, 128);
  myTask07Handle = osThreadCreate(osThread(myTask07), NULL);

  /* definition and creation of myTask08 */
  osThreadDef(myTask08, StartTask08, osPriorityNormal, 0, 128);
  myTask08Handle = osThreadCreate(osThread(myTask08), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
		 HAL_GPIO_TogglePin( GPIOB, GPIO_PIN_12);
		 HAL_GPIO_TogglePin( GPIOE, GPIO_PIN_3);


	//	 HAL_UART_Transmit(&huart4, GUI_sum_mode,sizeof(GUI_sum_mode), 100);

    osDelay(50);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
	/* Infinite loop */
	uint8_t Key_memo;
	//	bool count_energy;
	uint16_t Dwin_mess;

	while (1)
	{

		if (Rx_recv)   //DWIN string is get completely
		{
			Rx_recv = 0;   //confirmed Rx_rec
			GUI_boot = true;

			Dwin_mess = (Rx1_Buffer[4] << 8) + Rx1_Buffer[5];

			switch (Dwin_mess)
			{
			//Take VP from receive data

			case (0x0F):     // Check LCD power on?
								GUI_boot = true;
			break;

			case (0x0014): //Read no of page on work
								page = Rx1_Buffer[8];
			break;

			case (0x1400):  //STOP, READY  Variable GUI
				if (!Ready)
				{ //STOP
					Ready = 1;
					// play(S_ready);  //Ready
					osDelay(200);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET); //Interloc
					HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET); // AKELA pointer
					HAL_UART_Transmit(&huart1, GUI_stop, sizeof(GUI_stop), 100);
				}
				else if (Ready)
				{ //READY
					Ready = 0;
					// play(S_stop);  //Stop
					osDelay(200);
	//				// GUI_ready2stop();
				}
			break;

			case (0x1240):  //TONING Page switching
			Stamp = 0;
			// play(S_toning); //Toning sound
			//  EEPROM_Read(Last_mode); //save current mode
			// // show_parameter_toning();
			//  show_ST_key_value();
			// // GUI_ready2stop();
			break;

			case (0x1250):  //STAMP page switching
			Stamp = 1;
			// play(S_stamp);  //Stamp
			//  EEPROM_Read(Last_mode);  //save current mode
			// show_parameter_stamp();
			//  show_ST_key_value();
			// // GUI_ready2stop();
			break;

			// ===  Jump to Stamp mode from Monitor mode
			case (0x1296):
			// play(S_Beek);
			Monitor = 0;

			Stamp = 1;
			// play(S_stamp);  //Stamp
			//  EEPROM_Read(Last_mode);  //save current mode
			// show_parameter_stamp();
			//  show_ST_key_value();
			// // GUI_ready2stop(); // clear "ready" state

			GUI_mon_Laser_ON[7] = 1; //Laser OFF
			HAL_UART_Transmit(&huart1, GUI_mon_Laser_ON, sizeof(GUI_mon_Laser_ON), 100);

			// Stop "Laser ON" over Monitor mode
		//	HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 0);
		//	HAL_DAC_Stop(&hdac, DAC_CHANNEL_1);
			HAL_GPIO_WritePin( GPIOB, GPIO_PIN_14, GPIO_PIN_SET); // Interlock stop
			HAL_GPIO_WritePin( GPIOA, GPIO_PIN_7, GPIO_PIN_RESET); // Enable Stop
			HAL_GPIO_WritePin( GPIOB, GPIO_PIN_2, GPIO_PIN_RESET); //Fire lamp Off

			GUI_sum_mode[7] = 1;
			HAL_UART_Transmit(&huart1, GUI_sum_mode,sizeof(GUI_sum_mode), 100);

			vTaskSuspend(myTask05Handle);	 // STOP DefaultTask
			break;


			// ===  Move to Monitor mode
			case (0x1298):
			// play(S_Beek);
			Monitor = true;
			// // GUI_ready2stop(); // clear "ready" state

			GUI_mon_Laser_ON[7] = 1;  //Laser OFF
			HAL_UART_Transmit(&huart1, GUI_mon_Laser_ON, sizeof(GUI_mon_Laser_ON), 100);

			GUI_mon_power[6] = 0;     //Start monitor page with Power = 0
			GUI_mon_power[7] = 0;
			HAL_UART_Transmit(&huart1, GUI_mon_power, sizeof(GUI_mon_power),100);//show power0~6

			// Stop "Laser ON" over Monitor mode
	//		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 0);
	//		HAL_DAC_Stop(&hdac, DAC_CHANNEL_1);
			HAL_GPIO_WritePin( GPIOB, GPIO_PIN_14, GPIO_PIN_SET); // Interlock stop
			HAL_GPIO_WritePin( GPIOA, GPIO_PIN_7, GPIO_PIN_RESET); // Enable Stop
			HAL_GPIO_WritePin( GPIOB, GPIO_PIN_2, GPIO_PIN_RESET); //Fire lamp Off

			vTaskResume(myTask05Handle);   // Strat Monitoring Task(5)
			break;



			// ===  Laser ON at Monitor mode
			case (0x1340):
				if (!Laser_ON)
				{
					Laser_ON = 1;
					// play(S_ready);  //Ready
					osDelay(200);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET); //Interloc
					HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET); // AKELA pointer
					GUI_mon_Laser_ON[7] = 0;
					HAL_UART_Transmit(&huart1, GUI_mon_Laser_ON, sizeof(GUI_mon_Laser_ON), 100);
				}
				else
				{
					Laser_ON = 0;
					// play(S_stop);  //Stop
					osDelay(200);
					GUI_mon_Laser_ON[7] = 1;
					HAL_UART_Transmit(&huart1, GUI_mon_Laser_ON, sizeof(GUI_mon_Laser_ON), 100);
					HAL_GPIO_WritePin( GPIOB, GPIO_PIN_14, GPIO_PIN_SET); //Interlock on
					HAL_GPIO_WritePin( GPIOA, GPIO_PIN_7, 0); // Enable stop
					HAL_GPIO_WritePin( GPIOC, GPIO_PIN_0, 0); // AKELA pointer Off
				}
			break;



			// ===  Increament & decrement adjustment at Monitoring
			case (0x1345):
			// play(S_Beek);
			// 5*330 = 1650:?????? DAC ????, ?????????????? HP????????????????????? CW???? 5 W ?????????????, 330?? Cut&Try???? ????????? ????
			Power_DAC = ((Rx1_Buffer[7] << 8) + Rx1_Buffer[8])*330;  //0~2100
			GUI_mon_power[6] = Rx1_Buffer[7];  //Last_mpower_high
			GUI_mon_power[7] = Rx1_Buffer[8];  //Last_mpower_low (real)
		//	HAL_UART_Transmit(&huart1, GUI_mon_power, sizeof(GUI_mon_power),100);//show power0~5

			//  EEPROM_Write(Last_mon_power_high, GUI_mon_power[6]);
			//  EEPROM_Write(Last_mon_power_low, GUI_mon_power[7]);

			break;

			///////////////////
			case (0x1300):  //  Increament & decrement adjustment at STAMP
			// play(S_Beek);
			//  EEPROM_Write( Last_power_high, Rx1_Buffer[7]);
			//  EEPROM_Write( Last_power_low, Rx1_Buffer[8]);
			Power_DAC = (Rx1_Buffer[7] << 8) + Rx1_Buffer[8];  ///////
			// // GUI_ready2stop();
			break;

			case (0x1305):  // Increament & decrement adjustment at Toning
			// play(S_Beek);
			//  EEPROM_Write( Last_power_high_t, Rx1_Buffer[7]);
			//  EEPROM_Write( Last_power_low_t, Rx1_Buffer[8]);
			Power_DAC_t = (Rx1_Buffer[7] << 8) + Rx1_Buffer[8];  ///////
			// // GUI_ready2stop();
			break;

			case (0x1614):  //save On_time value to eeprom
								//  EEPROM_Write( Last_on_time_high, Rx1_Buffer[7]);
			//  EEPROM_Write( Last_on_time_low, Rx1_Buffer[8]);
			On_Time = (Rx1_Buffer[7] << 8) + Rx1_Buffer[8]; ///////
			// // GUI_ready2stop();
			break;

			case (0x1615):  //save Off_time value to eeprom
								//  EEPROM_Write( Last_off_time_high, Rx1_Buffer[7]);
			//  EEPROM_Write( Last_off_time_low, Rx1_Buffer[8]);
			Off_Time = (Rx1_Buffer[7] << 8) + Rx1_Buffer[8]; ///////
			// // GUI_ready2stop();
			break;

			case (0x1260):  //Pulse value to eeprom
			//  EEPROM_Write( Last_pulse, Rx1_Buffer[8]);
			Pulse = Rx1_Buffer[8];  ///////
			// GUI_ready2stop();
			break;

			case (0x1605):  //Repeat value to eeprom
			//  EEPROM_Write( Last_repeat, Rx1_Buffer[8]);
			Repeat = Rx1_Buffer[8];
			// GUI_ready2stop();
			break;

			case (0x1280):  //Frequency value to eeprom
			//  EEPROM_Write( Last_frequency, Rx1_Buffer[8]);
			Freq = Rx1_Buffer[8];  ///////
			// GUI_ready2stop();
			break;

			case (0x1600):  //Total count value to eeprom
			//  EEPROM_Write( Last_tcount_high, Rx1_Buffer[7]);
			//  EEPROM_Write( Last_tcount_low, Rx1_Buffer[8]);
			break;

			case (0x1602):  //SOUND, MUTE Variable GUI
				if (Sound)
				{
					Sound = 0;
					// play(S_sound);  //sound
					//  EEPROM_Write( Last_sound, Sound);
					GUI_sound[7] = 0;
					HAL_UART_Transmit(&huart1, GUI_sound, sizeof(GUI_sound),100);
					volume(19);
				}
				else
				{
					Sound = true;
					// play(S_mute);  //mute
					//  EEPROM_Write( Last_sound, Sound);
					GUI_sound[7] = 1;
					HAL_UART_Transmit(&huart1, GUI_sound, sizeof(GUI_sound),100);
					volume(0);
				}
			//  EEPROM_Write( Last_sound, Sound);  //save current mode
			break;


			case (0x1603):  //FOOT, HAND Variable GUI
				if (Hand_foot)
				{
					Hand_foot = 0;
					// play(S_hand);  //hand
					GUI_foot[7] = 0;
					HAL_UART_Transmit(&huart1, GUI_foot, sizeof(GUI_foot), 100);
					//  EEPROM_Write( Last_Hand_foot, Hand_foot);
				}
				else
				{
					Hand_foot = true;
					// play(S_foot); //foot
					GUI_foot[7] = 1;
					HAL_UART_Transmit(&huart1, GUI_foot, sizeof(GUI_foot), 100);
					//  EEPROM_Write( Last_Hand_foot, Hand_foot);
				}
			break;

			//======  Select Total counter & energy  ============
			case (0x1606):  //Select between Toggle counts and Energy
				if (Count_energy)
				{
			    	Count_energy = 0;
					// play(S_total_energy);
					GUI_sum_mode[7] = 0;
					HAL_UART_Transmit(&huart1, GUI_sum_mode,sizeof(GUI_sum_mode), 100);
					//  EEPROM_Write( Last_Count_energy, Count_energy);
				}
				else
				{
					Count_energy = 1;
					// play(S_total_count);
					GUI_sum_mode[7] = 1;
					HAL_UART_Transmit(&huart1, GUI_sum_mode,sizeof(GUI_sum_mode), 100);
					//  EEPROM_Write( Last_Count_energy, Count_energy);
				}
			break;

			//======  Clear Total counter value     ============
			case (0x1608):  // Clear Total counter value
								Key_memo++;
			if (Key_memo == GUI_save_delay)
			{
				// play(S_clear);   //sound 'clear'
				sum_count = 0;
				sum_count_t = 0;
				sum_energy = 0;
				sum_energy_t = 0;
				HAL_UART_Transmit(&huart1, GUI_sum_value,sizeof(GUI_sum_value), 100);
			}
			break;
			case (0x1609): // save last parameter to EEPROM, show value on S2 key
				if (Key_memo >= GUI_save_delay)
						;
				else
						;
			Key_memo = 0;
			break;



			default:
				;   // do nothing
			}  //end of switch
			//================== End of Memory process ======================

		}   //if Rx_recv is received, it will be work.

		osDelay(Delay_task02);
	}  //for(1) loop
  /* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void const * argument)
{
  /* USER CODE BEGIN StartTask03 */
	/* Infinite loop */
	static uint8_t Rx_len, Rx_indx, data, Rx4_indx;

	while (1)
	{
		//============= UART-4: Hand piece ==============
		if (isEmpty(&uart_4) == 0)
		{
			data = pop(&uart_4);

			if (data != 10)   // Line feed? new line
			{
				Rx4_Buffer[Rx4_indx++] = data;
			}
			else
			{
				Rx4_Buffer[0] = 0x30; // # -> 0 clear
				HP_lens = atoi(strtok(Rx4_Buffer, " ")); //Lens 1,2,3
				HP_Temp = atoi(strtok(NULL, " ")); //Temp. sensor data
				HP_Fire = atoi(strtok(NULL, " ")); //HP switch detect

				Rx4_indx = 0;   // HP data is received
			}   //else

			if (HP_Fire)
			{
				 HAL_GPIO_WritePin( GPIOC, GPIO_PIN_7,GPIO_PIN_RESET);
			}
			else
				 HAL_GPIO_WritePin( GPIOC, GPIO_PIN_7,GPIO_PIN_SET);

    	}  //if

		//============= UART-1: DWIN LCD ==============
		if (isEmpty(&uart_1) == 0)
		{  /////Ring buffer check and get all

			data = pop(&uart_1);

			if (data == 0x5A)
			{			//Find head of string 0x5A/90
				Rx1_Buffer[0] = data;
				Rx_recv = 0;
			}
			else if (data == 0xA5)
			{	//head of string  0xA5/165
				Rx1_Buffer[1] = data;
				Rx_len = 1;			//Ready to get length of string
			}

			else if (Rx_len == 1)
			{	//Is it a length of string
				Rx1_Buffer[2] = data;
				Rx_len = 0;
				Rx_indx = 3;
			}

			else
			{
				if (Rx1_Buffer[2] > Rx_indx)
					Rx1_Buffer[Rx_indx++] = data;
				else
				{
					Rx1_Buffer[Rx_indx++] = data; //already get length of string
					Rx_recv = 1;
				}

			} //else
		}
		osDelay(Delay_task03);
	} // While(1)
  /* USER CODE END StartTask03 */
}

/* USER CODE BEGIN Header_StartTask04 */
/**
* @brief Function implementing the myTask04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask04 */
void StartTask04(void const * argument)
{
  /* USER CODE BEGIN StartTask04 */
  /* Infinite loop */
  for(;;)
  {
	     ttt = (float)HP_Temp/10;
	//     HAL_UART_Transmit(&huart4,  HP_Temp ,sizeof(3), 100);
	    printf("Temp = %d \r\n", HP_Temp);
    osDelay(200);
  }
  /* USER CODE END StartTask04 */
}

/* USER CODE BEGIN Header_StartTask05 */
/**
* @brief Function implementing the myTask05 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask05 */
void StartTask05(void const * argument)
{
  /* USER CODE BEGIN StartTask05 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask05 */
}

/* USER CODE BEGIN Header_StartTask06 */
/**
* @brief Function implementing the myTask06 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask06 */
void StartTask06(void const * argument)
{
  /* USER CODE BEGIN StartTask06 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask06 */
}

/* USER CODE BEGIN Header_StartTask07 */
/**
* @brief Function implementing the myTask07 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask07 */
void StartTask07(void const * argument)
{
	/* USER CODE BEGIN StartTask07 */
	/* Infinite loop */
	uint8_t first, second;

	//=============  Temperature  ===============
	for (;;)
	{   // HP temperature detection
		first = HP_Temp >> 8;
		second = HP_Temp & 0x00FF;
		GUI_temp[6] = first;  // Disp temperature and show it on LCD
		GUI_temp[7] = second;
		HAL_UART_Transmit(&huart1, GUI_temp, sizeof(GUI_temp), 100);

		//=============  Total energy & count value ===============
		if (Count_energy)
		{
			if (Stamp)
			{
				GUI_sum_value[6] =  (sum_count) >> 24;
				GUI_sum_value[7] =  ((sum_count) >> 16) & 0xFF;
				GUI_sum_value[8] =  ((sum_count) >> 8) & 0xFF;
				GUI_sum_value[9] =  (sum_count) & 0xFF;
				HAL_UART_Transmit(&huart1, GUI_sum_value, sizeof(GUI_sum_value),
						100);
			}
			else
			{
				GUI_sum_value[6] = (sum_count_t) >> 24;
				GUI_sum_value[7] = ((sum_count_t) >> 16) & 0xFF;
				GUI_sum_value[8] = ((sum_count_t) >> 8) & 0xFF;
				GUI_sum_value[9] = (sum_count_t) & 0xFF;
				HAL_UART_Transmit(&huart1, GUI_sum_value, sizeof(GUI_sum_value),
						100);
			}
		}
		else
		{
			if (Stamp)
			{
				GUI_sum_value[6] = (sum_energy/10) >> 24;
				GUI_sum_value[7] = ((sum_energy/10) >> 16) & 0xFF;
				GUI_sum_value[8] = ((sum_energy/10) >> 8) & 0xFF;
				GUI_sum_value[9] = (sum_energy/10) & 0xFF;
				HAL_UART_Transmit(&huart1, GUI_sum_value, sizeof(GUI_sum_value),
						100);
			}
			else
			{
				GUI_sum_value[6] = (sum_energy_t/10) >> 24;
				GUI_sum_value[7] = ((sum_energy_t/10) >> 16) & 0xFF;
				GUI_sum_value[8] = ((sum_energy_t/10) >> 8) & 0xFF;
				GUI_sum_value[9] = (sum_energy_t/10) & 0xFF;
				HAL_UART_Transmit(&huart1, GUI_sum_value, sizeof(GUI_sum_value),
						100);
			}
		}

		osDelay(Delay_task07);  //500ms
	}
	/* USER CODE END StartTask07 */
}

/* USER CODE BEGIN Header_StartTask08 */
/**
* @brief Function implementing the myTask08 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask08 */
void StartTask08(void const * argument)
{
  /* USER CODE BEGIN StartTask08 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask08 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
//=============== Ring buffer =====================


void push(uart_t *u, uint8_t data)
{
	u->buffer[u->head] = data;
	u->head++;
	if (u->head >= MAX_BUFFER_SIZE)
	{
		u->head = 0;
	}
}

uint8_t pop(uart_t *u)
{
	uint8_t data = u->buffer[u->tail];
	u->tail++;
	if (u->tail >= MAX_BUFFER_SIZE)
	{
		u->tail = 0;
	}
	return data;
}

uint8_t isEmpty(uart_t *u)
{
	return u->head == u->tail;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	if (huart->Instance == USART1)
	{
		push(&uart_1, rx1_data);  //save data to Ring buffer
		HAL_UART_Receive_IT(&huart1, &rx1_data, 1);
	}

	if (huart->Instance == UART4)
	{
		push(&uart_4, rx4_data);  //save data to Ring buffer
		HAL_UART_Receive_IT(&huart4, &rx4_data, 1);
	}

}

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
