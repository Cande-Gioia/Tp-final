/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.h)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

#ifndef _OBJ_H_
#define _OBJ_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define AL1 12  // Cantidad de autos en el nivel 1
#define AL2 8
#define AL3 8
#define TL1 17  // Cantidad de troncos en el nivel 1
#define TL2 8
#define TL3 8
#define CANT_TRONCOS 17
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef struct
{
    int16_t pos_x;   
    int16_t pos_y;
    int16_t width;
    uint8_t type_obj;       // 0: auto; 1:tronco
    int speed;              // Contador para controlar la velocidad del objeto
    int original_speed;     // Variable que mantiene el valor original de speed (Mejora posible: sacarlo de la estructura)
} obj_t;

typedef struct
{
    obj_t arr[AL1];
} obj_arr_t;

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief INITAUTOS: inicializa los autos correspondientes a cada nivel
 * @param pasos RaspberryPI: 1; Allegro: 30
 * @param nivel nivel en el que se encuentra la rana
 * @return arreglo de autos ordenado por posiciones de manera decreciente en x e y
*/
void init_autos(obj_t autos[], int pasos, uint8_t nivel);

/**
 * @brief INITTRONCOS: inicializa los troncos correspondientes a cada nivel
 * @param pasos RaspberryPI: 1; Allegro: 30
 * @param nivel nivel en el que se encuentra la rana
 * @return arreglo de troncos ordenado por posiciones de manera decreciente en x e y
*/
void init_troncos(obj_t troncos[], int pasos, uint8_t nivel);


/**
 * @brief MOVIMIENTOOBJ: mueve los objetos
 * @param objeto objeto que va a moverse
 * @param pasos RaspberryPI: 1; Allegro: 30
 * @return estructura del objeto con su nueva posicion
*/
obj_t movimiento_obj(obj_t objeto, int pasos);

/*******************************************************************************
 ******************************************************************************/

#endif // _OBJ_H_
