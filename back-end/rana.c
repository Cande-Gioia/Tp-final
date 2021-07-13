/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.c)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/
/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "rana.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/
/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

rana_t pos_rana_init(rana_t init_pos, int pasos)
{
	init_pos.pos_x = INIT_X * pasos;
	init_pos.pos_y = INIT_Y * pasos;
	init_pos.colision = 0;
	init_pos.cant_vida = 3;
    init_pos.nivel = 1;
	return init_pos;
}

rana_t reset_rana(rana_t rana, int pasos)
{
    rana.pos_x = INIT_X*pasos;
    rana.pos_y = INIT_Y*pasos;
    return rana;
}

rana_t movimiento_rana(char tecla, rana_t posicion, int pasos)
{

	if (tecla == 'U')	
	{
		if(posicion.pos_y!=0)
		{
			posicion.pos_y = posicion.pos_y - pasos;							// la rana se mueve un casillero para arriba
		}
	}
	else if (tecla == 'D')
	{
		if(posicion.pos_y != 15*pasos)
		{
			posicion.pos_y = posicion.pos_y + pasos;							// la rana se mueve un casillero para abajo
		}
	}
	else if (tecla == 'L')
	{
		if (posicion.pos_x != 0)
		{
			posicion.pos_x = posicion.pos_x - pasos;							// la rana se mueve un casillero a la izquierda
		}
	}
	else if (tecla == 'R')
	{
		if(posicion.pos_x != 15*pasos)
		{
			posicion.pos_x = posicion.pos_x + pasos;							// la rana se mueve un casillero a la derecha
		}
	}

	return posicion;
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
