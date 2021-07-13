/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.h)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

#ifndef _RANA_H_
#define _RANA_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdint.h>


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define LEFT    'L'
#define RIGHT   'R'
#define UP      'U'
#define DOWN    'D'
#define PASOS   30
#define INIT_X  7
#define INIT_Y  15

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
//estructura que indica la posicion de la rana
typedef struct
{
	int16_t pos_x;
	int16_t pos_y;
        uint8_t cant_vida;
        int colision;
        ALLEGRO_BITMAP *pointer;
         
}rana_t;

typedef struct
{
  int16_t pos_x;   
  int16_t pos_y;
  int16_t width;
  ALLEGRO_BITMAP *pointer;
  int speed;

}obj_t;


typedef struct
{
    obj_t arr[CANT_OBJ];
}obj_arr_t;

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: extern unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
void pos_rana(int16_t pos_x, int16_t pos_y);
rana_t reset_colision(rana_t rana, int pasos);
rana_t pos_rana_init(rana_t init_pos, int pasos);
//rana_t movimiento_rana(char tecla, rana_t posicion, int pasos, auto_t autos[]);
 rana_t check_colision(rana_t rana, obj_t coche);
rana_t movimiento_rana(char tecla, rana_t posicion, int pasos);
obj_arr_t init_autos(ALLEGRO_BITMAP *arr[], int cant_autos, int pasos);

/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
// +ej: char lcd_goto (int fil, int col);+


/*******************************************************************************
 ******************************************************************************/

#endif // _RANA_H_
