#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "colisiones.h"
#include "obj.h"
#include "rana.h"

#define PASOS 	1
#define NIVEL_1 1
void delay(int number_of_seconds);
int main(void)
{
	//INICIALIZACION OBJETOS Y RANA CHEQUEADOS
	//inicializo rana
	rana_t rana; 
	rana = pos_rana_init(rana, PASOS);
	//printf("rana x: %d\t rana y: %d\t rana colision: %d\t rana vidas: %d\n", rana.pos_x, rana.pos_y, rana.colision, rana.cant_vida);

	//inicializo autos
	obj_t autos[AL1];
	init_autos(autos, PASOS, NIVEL_1);
	/*for (int i = 0; i< AL1; i++)
	{
	
		
		printf("%d --> auto x: %d auto y: %d auto width: %d auto type_obj: %d auto speed: %d auto original : %d\n", i, autos[i].pos_x, autos[i].pos_y, autos[i].width, autos[i].type_obj, 			autos[i].speed, autos[i].original_speed);
	
	
	}*/

	//inicializo troncos
	obj_t troncos[TL1];
	init_troncos(troncos, PASOS, NIVEL_1);
	/*for (int i = 0; i< 17; i++)
	{
	printf("%d --> tronco x: %d tronco y: %d tronco width: %d tronco type_obj: %d tronco speed: %d tronco original : %d\n", i, troncos[i].pos_x, troncos[i].pos_y, troncos[i].width, troncos[i].type_obj, 			troncos[i].speed, troncos[i].original_speed);
	}*/
	//MOVIMIENTO RANA (TODOS LOS CASOS)
	/*rana.pos_x = 15;
	rana.pos_y = 15;
	rana= movimiento_rana('U', rana, PASOS);
	printf("rana x: %d\t rana y: %d\t rana colision: %d\t rana vidas: %d\n", rana.pos_x, rana.pos_y, rana.colision, rana.cant_vida);
	rana= movimiento_rana('D', rana, PASOS);
	printf("rana x: %d\t rana y: %d\t rana colision: %d\t rana vidas: %d\n", rana.pos_x, rana.pos_y, rana.colision, rana.cant_vida);
	rana= movimiento_rana('L', rana, PASOS);
	printf("rana x: %d\t rana y: %d\t rana colision: %d\t rana vidas: %d\n", rana.pos_x, rana.pos_y, rana.colision, rana.cant_vida);
	rana= movimiento_rana('R', rana, PASOS);
	printf("rana x: %d\t rana y: %d\t rana colision: %d\t rana vidas: %d\n", rana.pos_x, rana.pos_y, rana.colision, rana.cant_vida);	*/
	
	//MOVIMIENTOS OBJETOS CHEQUEADO
	/*while (1)
	{ 


		delay (1);
		autos[6] = movimiento_obj( autos[6], PASOS);
		}*/
		
		
		//COLISIONES :  AGUA y AUTOS CHEQUEADO
	rana.pos_x= 6;
	rana.pos_y= 7;
	rana = colision ( rana, PASOS, autos, troncos);
	printf("rana x: %d\t rana y: %d\t rana colision: %d\t rana vidas: %d\n", rana.pos_x, rana.pos_y, rana.colision, rana.cant_vida);
	//COLISIONES :  TRONCO CHEQUEADO
	rana.pos_x= 9;
	rana.pos_y= 7;
	/*rana = colision ( rana, PASOS, autos, troncos);
	printf("rana x: %d\t rana y: %d\t rana colision: %d\t rana vidas: %d\n", rana.pos_x, rana.pos_y, rana.colision, rana.cant_vida);		*/	
	//MOVIMIENTO RANA_TRONCO CHEQUEADO	
        while (rana.cant_vida == 2)
	{ 


		delay (1);
                rana = colision ( rana, PASOS, autos, troncos);
                
		for (int i=0; i<3; i++)
                {
                    troncos[i]= movimiento_obj( troncos[i], PASOS);
                    
                }
	}
        printf("rana x: %d\t rana y: %d\t rana colision: %d\t rana vidas: %d\n", rana.pos_x, rana.pos_y, rana.colision, rana.cant_vida);
		
		


	
	
	return 0;
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

