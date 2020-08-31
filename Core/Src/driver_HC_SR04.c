/**
  ******************************************************************************
  * File Name          : driver_HC_SR04.c
  * Description        : This file provides code for HC-SR04
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 Alfonso Moreno Sanz.
  * All rights reserved.</center></h2>
  ******************************************************************************
  */

#include "driver_HC_SR04.h"
#include "tim.h"
#include <math.h>

double frequency = 0;
double distanciacm  = 0;
void HC_SR04_Start_trigger(){
	HAL_TIM_Base_Start_IT(&htim7);
	HAL_GPIO_WritePin(TRIG_HC_SR04_GPIO_Port, TRIG_HC_SR04_Pin, GPIO_PIN_SET);
}
void HC_SR04_Stop_trigger(){
	HAL_TIM_Base_Stop_IT(&htim7);
	HAL_GPIO_WritePin(TRIG_HC_SR04_GPIO_Port, TRIG_HC_SR04_Pin, GPIO_PIN_RESET);
	HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
}
double HC_SR04_get_distance(uint16_t diffCapture){
	frequency = 108* pow(10,6)/ (htim3.Instance->PSC + 1);
	frequency = (float) frequency / diffCapture;
	distanciacm = ((1/frequency) * pow(10,6))/58;
	return distanciacm * pow(10,-2);
}
