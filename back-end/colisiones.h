/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.h)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

#ifndef _COLISIONES_H_
#define _COLISIONES_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
 #include <stdio.h>
#include <stdlib.h>
#include "rana.h"
#include "obj.h"
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief RESETCOLISION: devuelve a la rana a la posicion de inicio y le quita una vida despues de una colision
 * @param rana estructura de la rana
 * @param pasos RaspberryPI: 1; Allegro: 30
 * @return devuelve la estructura de la rana
*/

rana_t colision (rana_t rana, int pasos, obj_t autos[], obj_t troncos[]);

/*******************************************************************************
 ******************************************************************************/

#endif // _COLISIONES_H_
