/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.c)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/
/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "colisiones.h"

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
static rana_t reset_life(rana_t rana, int pasos);
static rana_t check_colision(rana_t rana, obj_t objeto, int pasos);
static rana_t movimiento_rana_tronco(rana_t rana, obj_t objeto , int pasos );
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




 rana_t colision (rana_t rana, int pasos, obj_t autos[], obj_t troncos[])
{

	int i;  //Índice
	int conta_colisiones=0;
	if (rana.pos_y <= 7*pasos && rana.pos_y >= 2*pasos)
	{
		for (i=0; i<CANT_TRONCOS; i++)
		{
			rana = check_colision(rana, troncos[i], pasos);
			conta_colisiones += rana.colision;
                        if (rana.colision == 0 )
                        {
                          
                             rana = movimiento_rana_tronco( rana,troncos[i], pasos);
                             i = CANT_TRONCOS;
			
                        }
                        else if (conta_colisiones == CANT_TRONCOS)
                        {

                                rana = reset_life(rana,pasos);
                        }

		}

	}
	else
	{
		for (i=0; i<AL1; i++)
		{
			rana = check_colision(rana, autos[i], pasos); //
			
			if (rana.colision == 1)
			{
				rana = reset_life(rana,pasos);
				i=AL1;
			}
			
			
		} 
	}
	return rana;

}
/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
 
static rana_t reset_life(rana_t rana, int pasos)
{
	--rana.cant_vida;
	if(rana.cant_vida > 0)
	{
		rana.colision = 0;
		rana = reset_rana ( rana, pasos);
	}
	return rana;
}
 static rana_t check_colision(rana_t rana, obj_t objeto, int pasos)
{
	
    if(rana.pos_y == objeto.pos_y)
    {
  
        if( rana.pos_x >= objeto.pos_x && rana.pos_x <= (objeto.pos_x + objeto.width) )
        {
        	
            if (objeto.type_obj == 0)
            {
               rana.colision = 1;
            }
            if (objeto.type_obj ==1)
            {
                rana.colision = 0;
            }
        }
       else if (rana.pos_y <= 7*pasos && rana.pos_y >= 2*pasos)
        {
            
            rana.colision = 1;   
    	}
    }
    else if (rana.pos_y <= 7*pasos && rana.pos_y >= 2*pasos)
    {
    
    	rana.colision = 1;   
    }
    
    return rana;
}


static rana_t movimiento_rana_tronco(rana_t rana, obj_t objeto , int pasos )
{
    --objeto.speed;

    if( ((objeto.pos_y)/pasos) % 2 == 0 )       //El objeto se mueve de izquierda a derecha
    {
        if( objeto.speed == 0 )
        {
            if(rana.pos_x == 15*pasos)          //La rana llega al final de la calle. Reaparece del otro lado
            {
                rana = reset_life(rana, pasos);
            }
            else                                //La rana avanza
            {
                ++rana.pos_x;
                 printf("rana x:   %d rana y:   %d rana colision: %d rana vidas: %d\n", rana.pos_x, rana.pos_y, rana.colision, rana.cant_vida);			
            }

            objeto.speed = objeto.original_speed;
        }
    }
    else                                        // El objeto se mueve de derecha a izquierda
    {
        if( objeto.speed == 0 )
        {
            if(rana.pos_x == 0)                 //La rana llega al final de la calle. Reaparece del otro lado
            {
                //rana.pos_x = 15*pasos;
                rana = reset_life(rana, pasos);
            }
            else                                // La rana  avanza
            {
                --rana.pos_x;   
                printf("rana x:   %d rana y:   %d rana colision: %d rana vidas: %d\n", rana.pos_x, rana.pos_y, rana.colision, rana.cant_vida);			
            }

            objeto.speed = objeto.original_speed;
        }
    }
    return rana;
}






