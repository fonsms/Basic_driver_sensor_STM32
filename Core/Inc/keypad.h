/**
  ******************************************************************************
  * File Name          : teclado.h
  * Description        : This file provides code for a 4*4 keypad
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 Alfonso Moreno Sanz.
  * All rights reserved.</center></h2>
  ******************************************************************************
  */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#include "main.h"

#define NUM_COLS 4
#define NUM_ROWS 4

enum columns_values {
	COL_1,
	COL_2,
	COL_3,
	COL_4,
};

enum rows_values {
	ROW_1,
	ROW_2,
	ROW_3,
	ROW_4
};


typedef struct {
	int col;
	int row;
} TipoTecla;
typedef struct {
	int columna_actual;
	TipoTecla teclaPulsada;
} TipoTeclado;

void init_keypad(TipoTeclado *p_keypad);
void next_col(TipoTeclado *p_keypad);
int key_press(TipoTeclado *p_keypad);
void reset_key_press(TipoTeclado *p_keypad);

#endif /* INC_KEYPAD_H_ */
