/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "lwip.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string>
#include <MyBlinker.h>
#include <MySensor.h>
#include <MyOled.h>
#include <MyButton.h>
#include <MyMeasurements.h>
#include <MyMqtt.h>

#include "dht.h"

//mqtt
#include <mqtt.h>
#include <MyMqtt.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

//mqtt
ip_addr_t ip_addr;
mqtt_client_t *client;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */



extern struct netif gnetif;

static bool ready_flag = false;
static bool mesurement_flag = false;
//static bool ethernet_flag = false;



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */



MyBlinker mb = MyBlinker();  // TODO constructor get pin
MyOled my_oled = MyOled();
MyButton my_btn = MyButton(USR_BTN_GPIO_Port, USR_BTN_Pin);
MySensor ms;
DHT_sensor dht_22;



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

  /* USER CODE END Inoled_testingit */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM6_Init();
  MX_I2C2_Init();
  MX_SPI6_Init();
  MX_LWIP_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */



  // dht11
  dht_22 = { DHT11_1_wire_GPIO_Port, DHT11_1_wire_Pin, DHT22, 0 };

  // bmp280/bme280
  ms = MySensor();
  ms.set_bmp( &hi2c2 );
  ms.set_dht( &dht_22 );

  // 0.96" OLED display init and test
  my_oled.init();
  my_oled.hello();

  // measurements
  MyMeasurements arr = MyMeasurements();



  HAL_TIM_Base_Start_IT(&htim6);



  // mqtt
  static const char mqtt_server[13] ={'1','9','2', '.', '1','6','8' , '.' , '0' , '.' , '1','0','4'};

  client = mqtt_client_new();
  ipaddr_aton(mqtt_server,&ip_addr);

  if(client != NULL) {
	MX_LWIP_Process();  // ??
	example_do_connect(client);
    MX_LWIP_Process();  // ??
  }


  ready_flag = true;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

	MX_LWIP_Process();

	if (mesurement_flag)
	{
		mesurement_flag = false;

		mb.blue_toggle();
		mb.red_on();

		ms.get_data();
		my_oled.set_tph( ms.temperature, ms.pressure, ms.humidity_dht );
		my_oled.display();

//		if ( ! mqtt_client_is_connected( client ) ){
//			MX_LWIP_Process();
//			example_do_connect(client);
//			MX_LWIP_Process();
//		}
		MX_LWIP_Process();
		example_publish(client, NULL, &ms.temperature, &ms.pressure, &ms.humidity_dht );
		MX_LWIP_Process();

		example_do_connect(client);
		MX_LWIP_Process();



		mb.red_off();
	}

    /* USER CODE BEGIN 3 */
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
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* EXTI15_10_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 3, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	my_btn.catch_click();

	if ( ready_flag && my_btn.is_Click() ){  // ready_flag false until super circle


		if ( my_btn.is_Short() )
		{
			my_oled.next_display();
		}
		else if ( my_btn.is_Middle() )
		{
			my_oled.prev_display();
		}
		else if ( my_btn.is_Long() )
		{
			if ( my_oled.get_display() == 3 ){
				my_oled.oled_testing();
			}
		}

		my_btn.clean();
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM6) //check if the interrupt comes from TIM1
	{
		mesurement_flag = true;
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGINrror_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
    for( int i = 0 ; i < 2700000 ; i+=2 ){
        i--;
    }
    mb.red_toggle();

  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

