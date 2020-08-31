/**
  ******************************************************************************
  * File Name          : teclado.c
  * Description        : This file provides code for a 4*4 keypad
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 Alfonso Moreno Sanz.
  * All rights reserved.</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

#include "keypad.h"
#include "tim.h"
/* Declaration ------------------------------------------------------------------*/
int press = 0;
/* Functions ------------------------------------------------------------------*/


void init_keypad(TipoTeclado *p_keypad){

	// Inicialmente no hay tecla pulsada
	p_keypad->teclaPulsada.col = -1;
	p_keypad->teclaPulsada.row = -1;
	// Comenzamos excitacion por primera columna
	p_keypad->columna_actual = COL_1;
	p_keypad->teclaPulsada.col = COL_1;
	HAL_GPIO_WritePin(COL1_GPIO_Port,COL1_Pin , GPIO_PIN_SET);
	HAL_GPIO_WritePin(COL2_GPIO_Port, COL2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(COL3_GPIO_Port, COL3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(COL4_GPIO_Port, COL4_Pin, GPIO_PIN_RESET);
	HAL_TIM_Base_Start_IT(&htim6);
}

void next_col(TipoTeclado *p_keypad){
	if (p_keypad->columna_actual == COL_1) {
		HAL_GPIO_TogglePin(COL1_GPIO_Port, COL1_Pin);
		HAL_GPIO_TogglePin(COL2_GPIO_Port, COL2_Pin);
		p_keypad->columna_actual = COL_2;
		p_keypad->teclaPulsada.col = COL_2;
	} else if (p_keypad->columna_actual == COL_2){
		HAL_GPIO_TogglePin(COL2_GPIO_Port, COL2_Pin);
		HAL_GPIO_TogglePin(COL3_GPIO_Port, COL3_Pin);
		p_keypad->columna_actual = COL_3;
		p_keypad->teclaPulsada.col = COL_3;
	}else if (p_keypad->columna_actual == COL_3){
		HAL_GPIO_TogglePin(COL3_GPIO_Port, COL3_Pin);
		HAL_GPIO_TogglePin(COL4_GPIO_Port, COL4_Pin);
		p_keypad->columna_actual = COL_4;
		p_keypad->teclaPulsada.col = COL_4;
	}else if (p_keypad->columna_actual == COL_4){
		HAL_GPIO_TogglePin(COL4_GPIO_Port, COL4_Pin);
		HAL_GPIO_TogglePin(COL1_GPIO_Port, COL1_Pin);
		p_keypad->columna_actual = COL_1;
		p_keypad->teclaPulsada.col = COL_1;
	}
}
int key_press(TipoTeclado *p_keypad){
	press = 0;
	if (p_keypad->teclaPulsada.row > -1) {
		press = 1;
	}
	return press;
}
void reset_key_press(TipoTeclado *p_keypad){
  	p_keypad->teclaPulsada.col = -1;
	p_keypad->teclaPulsada.row = -1;
}
