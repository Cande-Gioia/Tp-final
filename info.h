
/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.h)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

#ifndef _INFO_H_
#define _INFO_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/



/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

#define WIDTH 480
#define HEIGHT 480
#define AGUA_H 180
#define AGUA_W 480
#define MOVE_RATE_RANA 30.0
#define RANA_H 30
#define RANA_W 30
#define FILA_H 420

typedef struct
{
	int16_t pos_x;
	int16_t pos_y;
        uint8_t cant_vida;
       ALLEGRO_BITMAP *pointer;
         
}rana_t;

typedef struct
{
  int16_t pos_x;   
  int16_t pos_y;
  int16_t width;
  ALLEGRO_BITMAP *pointer;

}auto_t;

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
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
// +ej: char lcd_goto (int fil, int col);+


/*******************************************************************************
 ******************************************************************************/

#endif // _INFO_H_