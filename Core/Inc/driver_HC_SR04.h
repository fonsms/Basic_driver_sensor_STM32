/**
  ******************************************************************************
  * File Name          : driver_HC_SR04.h
  * Description        : This file provides code for HC-SR04
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 Alfonso Moreno Sanz.
  * All rights reserved.</center></h2>
  ******************************************************************************
  */

#ifndef INC_DRIVER_HC_SR04_H_
#define INC_DRIVER_HC_SR04_H_

#include "main.h"

void HC_SR04_Start_trigger();
void HC_SR04_Stop_trigger();
double HC_SR04_get_distance(uint16_t diffCapture);


#endif /* INC_DRIVER_HC_SR04_H_ */
