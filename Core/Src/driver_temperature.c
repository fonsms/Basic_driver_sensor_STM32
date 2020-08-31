/**
  **********************************************************************************
  * File Name          : driver_temperature.c
  * Description        : This file provides code for the internal temperature sensor
  *
   *********************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 Alfonso Moreno Sanz.
  * All rights reserved.</center></h2>
  **********************************************************************************
  */
#include "driver_HC_SR04.h"
#include "adc.h"
#include <math.h>
uint16_t rawValue;
float temp;
float get_temperature_value(){
	 HAL_ADC_Start(&hadc1);
	 HAL_ADC_PollForConversion(&hadc1, 10);
	 rawValue = HAL_ADC_GetValue(&hadc1);
	 //HAL_ADC_Stop(&hadc1);
	 temp = ((float)rawValue) / (pow(2,12)-1) * 3300;
	 temp = ((temp - 760.0) / 2.5) + 25;
	 return temp;
}
