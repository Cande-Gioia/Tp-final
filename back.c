

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h> 
#include "info.h"
#include "rana1.h"
#define FPS 10.0
#define DIST 10
static obj_t crear_auto (int16_t x, int16_t y, int16_t width, int speed, ALLEGRO_BITMAP *pointer);
obj_arr_t init_autos(ALLEGRO_BITMAP *arr[], int cant_autos, int pasos)
{
    obj_arr_t autos;
	int i;                                                                      // contador para recorrer los arreglos de punteros y de las estructuras de objetos
	int x, y; 
    int speeds[] = {20,50,100};                                                 // posibles velocidades con la que se mueven los autos
    int widths[] = {pasos, 2*pasos, 3*pasos};                                   // posibles largos para los autos

	for(i=0, x=0, y=14*pasos; i<cant_autos ; ++i, x+=pasos, y-=pasos)
	{
        int car_speed = speeds[rand() % 3];      
        int car_width = widths[rand() % 3];
		autos.arr[i]= crear_auto(x, y, car_width, car_speed, arr[i]);
	}

	return autos;
}

/*
Funcion que le asigna los atributos a cada auto particular de acuerdo a los parametros ingresados
*/
static obj_t crear_auto (int16_t x, int16_t y, int16_t width, int speed, ALLEGRO_BITMAP *pointer)
{
    obj_t obj_aux;
    obj_aux.pos_x=x;
    obj_aux.pos_y=y;
    obj_aux.width = width;
    obj_aux.speed= speed;
    obj_aux.pointer= pointer;
    return obj_aux;
}

rana_t pos_rana_init(rana_t init_pos, int pasos)
{
	init_pos.pos_x = INIT_X * pasos;
	init_pos.pos_y = INIT_Y * pasos;
	init_pos.colision = 0;
	init_pos.cant_vida = 3;
	return init_pos;
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

rana_t reset_colision(rana_t rana, int pasos)
{
	--rana.cant_vida;
	if(rana.cant_vida > 0)
	{
		rana.colision = 0;
		rana.pos_x = INIT_X*pasos;
		rana.pos_y = INIT_Y*pasos;
	}
	return rana;
}

 rana_t check_colision(rana_t rana, obj_t coche)
{
	int hubo_choque = 0;
        rana_t rana_aux =rana;
	/*int i;
	for(i=0; i <= ( sizeof(auto)/sizeof(auto[0]) ); ++i)
	{
		if(rana.pos_y == auto[i].pos_y)
		{
			if( rana.pos_x >= auto[i].pos_x && rana.pos_x <= (auto[i].pos_x + auto[i].width) )
			{
				hubo_choque = 1;
			}
		}
	}
	*/

	if((coche.pos_y >= rana.pos_y && (coche.pos_y <= (rana.pos_y + OBJ_H-1))) || (rana.pos_y >= coche.pos_y && (rana.pos_y <= (coche.pos_y + OBJ_H-1))))
	{
		if(( rana.pos_x >= coche.pos_x && (rana.pos_x <= (coche.pos_x + coche.width-1) )) ||( coche.pos_x >= rana.pos_x && (coche.pos_x <= (rana.pos_x + RANA_W-1)) ))
		{
			hubo_choque = 1;
                        
                        printf("coli\n");
                        printf ("rx: %d, ry: %d, ax: %d, ay: %d\n ", rana.pos_x, rana.pos_y, coche.pos_x, coche.pos_y);
		}
                
	}
                  
         
          if(hubo_choque == 1)
          {
                printf("Hubo colision\n");
                rana_aux = reset_colision(rana, MOVE_RATE_RANA);

          }
	  return rana_aux;
}

 
