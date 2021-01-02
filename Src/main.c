/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define ESP_Buffer_Boyutu 500

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
char *Basic_inclusion = "<head> Hello World </head>";

char *LED_ON = "<br><a href=\" ?pin=on\"><button type='button'>ON</button></a>";
char *LED_OFF = "<br><a href=\" ?pin=off\"><button type='button'>OFF</button></a>";
char datatosend[2000] = {0};
char TX_Buffer[500];
char RX_Buffer[100];
char Esp_Veri_Buffer[ESP_Buffer_Boyutu];
char ID[] = "Sert25";
char PW[] = "123123asd";
uint16_t Sayac = 0;
int baglanti_sayaci = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */
static void ESP8266_Init(char *SSID, char *PW);
static void Clear_ESP_Buffer(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  ESP8266_Init(ID, PW);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
void ESP8266_Init(char *SSID, char *PW){

	static uint8_t Case = 0;
	switch(Case){
	case 0:
		HAL_UART_Transmit(&huart2,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"AT\r\n"), 1000);
		Case = 1;
		HAL_Delay(2000);
		break;
	case 1:
		if(strstr(Esp_Veri_Buffer,"OK")){
			Clear_ESP_Buffer();
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Module Erisildi!\r\n"), 1000);
			Case = 2;
		}
		else{
			Clear_ESP_Buffer();
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Module Erisilemedi!\r\n"), 1000);
			Case = 0;
		}
		break;
	case 2:
		HAL_UART_Transmit(&huart2, (uint8_t*)TX_Buffer, sprintf(TX_Buffer, "AT+CWMODE?\r\n"), 1000);
		Case = 3;
		HAL_Delay(2000);
		break;
	case 3:
		if(strstr(Esp_Veri_Buffer,"+CWMODE:1")){
			Clear_ESP_Buffer();
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Mod ayari dogru!\r\n"), 1000);
			Case = 4;
	}
		else{
			Clear_ESP_Buffer();
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Mod ayari yanlis!\r\n"), 1000);
			HAL_UART_Transmit(&huart2, (uint8_t*)TX_Buffer, sprintf(TX_Buffer, "AT+CWMODE=1\r\n"), 1000);
			Case = 0;
		}
		break;
	case 4:
		HAL_UART_Transmit(&huart2, (uint8_t*)TX_Buffer, sprintf(TX_Buffer, "AT+CWJAP=\"%s\",\"%s\"\r\n",SSID,PW), 1000);
		HAL_Delay(2000);
		Case = 5;
		break;
	case 5:
		if(strstr(Esp_Veri_Buffer,"OK")){
			Clear_ESP_Buffer();
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Baglanti yapildi!\r\n"), 1000);
			Case = 6;
		}
		else{
			Clear_ESP_Buffer();
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Baglanti yapilamadi! Bekleniyor!!\r\n"), 1000);
			baglanti_sayaci++;
			HAL_Delay(2000);
			if (baglanti_sayaci == 5){
				HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Baglanti basarisiz. Tekrar deneniyor!!!\r\n"), 1000);
				Case = 0;
				baglanti_sayaci = 0;
			}
		}
		break;
	case 6:
		HAL_UART_Transmit(&huart2, (uint8_t*)TX_Buffer, sprintf(TX_Buffer, "AT+CIFSR\r\n"), 1000);
		HAL_Delay(2000);
		Case = 7;
		break;
	case 7:
		if(strstr(Esp_Veri_Buffer,"OK")){
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"IP Alindi!!!\r\n"), 1000);
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Cihaz IP = \r\n"), 1000);
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer, &Esp_Veri_Buffer[11]), 1000);
			Clear_ESP_Buffer();
			Case = 8;
		}
		else{
			Clear_ESP_Buffer();
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"IP Alinamadi!! Tekrar deneniyor!!!\r\n"), 1000);
			Case = 6;
		}
		break;
	case 8:
		HAL_UART_Transmit(&huart2, (uint8_t*)TX_Buffer, sprintf(TX_Buffer, "AT+CIPMUX=1\r\n"), 1000);
		HAL_Delay(2000);
		Case = 9;
		break;
	case 9:
		if(strstr(Esp_Veri_Buffer,"OK")){
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Coklu baglanti dogrulandi!!!!\r\n"), 1000);
			Clear_ESP_Buffer();
			Case = 10;
		}
		else{
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Coklu baglanti dogrulanamadi!!!!\r\n"), 1000);
			Clear_ESP_Buffer();
			Case = 8;
		}
		break;
	case 10:
		HAL_UART_Transmit(&huart2, (uint8_t*)TX_Buffer, sprintf(TX_Buffer, "AT+CIPSERVER=1,80\r\n"), 1000);
		HAL_Delay(2000);
		Case = 11;
		break;
	case 11:
		if(strstr(Esp_Veri_Buffer,"OK")){
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Server basladi!!!\r\n"), 1000);
			Clear_ESP_Buffer();
			Case = 12;
		}
		else{
			HAL_UART_Transmit(&huart3,(uint8_t*)TX_Buffer, sprintf(TX_Buffer,"Server baslamadi\r\n"), 1000);
			Clear_ESP_Buffer();
			Case = 10;
		}
		break;
	case 12:
		if(strstr(Esp_Veri_Buffer,"GET")){
		sprintf(datatosend, Basic_inclusion);
		strcat(datatosend, LED_ON);
		strcat(datatosend, LED_OFF);
		int len = strlen(datatosend);
		HAL_UART_Transmit(&huart2, (uint8_t*)TX_Buffer, sprintf(TX_Buffer, "AT+CIPSEND=%d,%d\r\n",0,len), 1000);
		HAL_Delay(2000);
		if(strstr(Esp_Veri_Buffer,">")){
		HAL_UART_Transmit(&huart2, (uint8_t*)TX_Buffer, sprintf(TX_Buffer, datatosend), 1000);
		HAL_Delay(6000);
		}
		}
//		Case = 13;
		break;


		}

}

void Clear_ESP_Buffer(void){

	uint16_t i;
	for(i= 0; i < ESP_Buffer_Boyutu; i++){
		Esp_Veri_Buffer[i] = 0;
	}
	Sayac = 0;
}



/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
