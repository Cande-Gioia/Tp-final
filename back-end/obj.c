/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.c)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/
/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "obj.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/
// +ej: unsigned int anio_actual;+
/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
// +ej: static void falta_envido (int);+
/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
// +ej: static const int temperaturas_medias[4] = {23, 26, 24, 29};+
/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
// +ej: static int temperaturas_actuales[4];+
/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void init_autos(obj_t autos[], int pasos, uint8_t nivel)
{
    
    switch(nivel)
    {
        case 1:;
            obj_t auto1 = {pasos, 14*pasos, pasos, 0, 100, 100};
            obj_t auto2 = {10*pasos, 14*pasos, pasos, 0, 100, 100 };
            obj_t auto3 = {15*pasos, 14*pasos, pasos, 0, 100, 100 };
            obj_t auto4 = {0, 12*pasos, pasos, 0, 100, 100 };
            obj_t auto5 = {6*pasos, 12*pasos, pasos, 0, 100, 100 };
            obj_t auto6 = {13*pasos, 12*pasos, pasos, 0, 100, 100 };
            obj_t auto7 = {pasos, 11*pasos, 2*pasos, 0, 100, 100 };
            obj_t auto8 = {11*pasos, 11*pasos, 2*pasos, 0, 100, 100 };
            obj_t auto9 = {5*pasos, 10*pasos, pasos, 0, 100, 100 };
            obj_t auto10 = {9*pasos, 10*pasos, pasos, 0, 100, 100 };
            obj_t auto11 = {4*pasos, 9*pasos, 2*pasos, 0, 100, 100 };
            obj_t auto12 = {13*pasos, 9*pasos, 2*pasos, 0, 100, 100 };
            autos[0] = auto1;
            autos[1] = auto2;
            autos[2] = auto3;
            autos[3] = auto4;
            autos[4] =  auto5;
            autos[5] =  auto6;
            autos[6] =  auto7;
            autos[7] = auto8;
            autos[8] =  auto9;
            autos[9] =  auto10;
            autos[10] =  auto11;
            autos[11] =  auto12;
            break;
        case 2:
            //NIVEL 2
            break;
        case 3:
            //NIVEL 3
            break;
    }
}

void init_troncos(obj_t troncos[], int pasos, uint8_t nivel)
{
    switch(nivel)
    {
        case 1:;
            obj_t tronco1 = {2*pasos, 7*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco2 = {8*pasos, 7*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco3 = {14*pasos, 7*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco4 = {pasos, 6*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco5 = {9*pasos, 6*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco6 = {12*pasos, 6*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco7 = {0, 5*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco8 = {5*pasos, 5*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco9 = {9*pasos, 5*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco10 = {pasos, 4*pasos, 3*pasos, 1, 100, 100};
            obj_t tronco11 = {9*pasos, 4*pasos, 3*pasos, 1, 100, 100};
            obj_t tronco12 = {4*pasos, 3*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco13 = {8*pasos, 3*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco14 = {12*pasos, 3*pasos, 2*pasos, 1, 100, 100};
            obj_t tronco15 = {-pasos, 2*pasos, 3*pasos, 1, 100, 100};
            obj_t tronco16 = {4*pasos, 2*pasos, 3*pasos, 1, 100, 100};
            obj_t tronco17 = {10*pasos, 2*pasos, 3*pasos, 1, 100, 100};
            troncos[0] = tronco1;
            troncos[1] = tronco2;
            troncos[2] =  tronco3;
            troncos[3] =  tronco4;
            troncos[4] =  tronco5;
            troncos[5] =  tronco6;
            troncos[6] = tronco7;
            troncos[7] =  tronco8;
            troncos[8] =  tronco9;
            troncos[9] =  tronco10;
            troncos[10] =  tronco11;
            troncos[11] =  tronco12;
            troncos[12] = tronco13;
            troncos[13] =  tronco14;
            troncos[14] =  tronco15;
            troncos[15] =  tronco16;
            troncos[16] =  tronco17;
            break;
        case 2:
            //NIVEL 2
            break;
        case 3:
            //NIVEL 3
            break;
    }
}


// RECIBE AUTO QUE DESEA MOVERSE. DEVUELVE AUTO CON NUEVA POSICION
obj_t movimiento_obj(obj_t objeto, int pasos)
{
    -- objeto.speed;

    if( objeto.speed == 0 )
    {
        if( ((objeto.pos_y)/pasos) % 2 == 0 )           // El objeto se mueve de izquierda a derecha
        {
            if(objeto.pos_x == 15*pasos)                // El objeto llega al final de la calle. Reaparece del otro lado
            {
                objeto.pos_x = 0;
            }
            else                                        // El objeto avanza
            {
                ++objeto.pos_x;
                printf("tronco x: %d tronco y: %d tronco width:  %d tronco type_obj: %d tronco speed: %d tronco original : %d\n", objeto.pos_x, objeto.pos_y,objeto.width, objeto.type_obj, objeto.speed, objeto.original_speed);
                		
            }
            
            objeto.speed = objeto.original_speed;
        }
        else
        {
            if(objeto.pos_x == 0)                       // El objeto llega al final de la calle. Reaparece del otro lado
            {
                objeto.pos_x = 15*pasos;
            }
            else                                        // El objeto avanza
            {
                --objeto.pos_x;   
                printf("tronco x: %d tronco y: %d tronco width:  %d tronco type_obj: %d tronco speed: %d tronco original : %d\n", objeto.pos_x, objeto.pos_y,objeto.width, objeto.type_obj, objeto.speed, objeto.original_speed);
                
                		
            }

            objeto.speed = objeto.original_speed;
        }
    }

    return objeto;
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
