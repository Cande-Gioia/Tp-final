

#include "allegro.h"

void front_al (void)
{

    ALLEGRO_BITMAP *autobit1= NULL;  //Crea los punteros a los autos
    ALLEGRO_BITMAP *autobit2= NULL;  
    ALLEGRO_BITMAP *autobit3= NULL;  
    ALLEGRO_BITMAP *autobit4= NULL;  
    ALLEGRO_BITMAP *autobit5= NULL;  
    ALLEGRO_BITMAP *autobit6= NULL;  
    ALLEGRO_BITMAP *autobit7= NULL;  
    ALLEGRO_BITMAP *autobit8= NULL; 
    ALLEGRO_BITMAP * ar[CANT_OBJ]={autobit1,autobit2,autobit3,autobit4, autobit5,autobit6,autobit7, autobit8};
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;  //Crea la secuencia de eventos
    ALLEGRO_TIMER *timer = NULL;  // Crea el timer
       bool key_pressed[4] = {false, false, false, false}; //Estado de teclas, true cuando esta apretada
    if (!al_init()) 
    {
        printf( "failed to initialize allegro!\n"); //Incializa allegro
    }
 
    obj_arr_t objetos = init_autos(ar,CANT_OBJ, PASOS_AL);
}



ALLEGRO_BITMAP * init (ALLEGRO_DISPLAY *display,rana_t rana)
{
    ALLEGRO_BITMAP *ranabit= NULL;   //Se crea el puntero a la rana


    ranabit = al_create_bitmap(RANA_W,RANA_W);   //
    if (!ranabit) 
    {
        printf("failed to create cuadradito bitmap!\n");
    }
    landscape(); //Se inicializa el fondo

    

    al_set_target_bitmap(ranabit);  //Rana 
    al_clear_to_color(al_map_rgb(0, 255, 0)); 
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(ranabit, rana.pos_x,rana.pos_y, 0);   //Se dibuja la rana con las coordenadas correspondientes
    return ranabit;
    
}
void landscape(void)

{
    al_draw_filled_rectangle(0, RANA_H , WIDTH , HEIGHT/2-RANA_H, al_color_name("blue"));   //Agua
    al_draw_filled_rectangle(0, HEIGHT/2, WIDTH, HEIGHT, al_color_name("black"));           //Calle 
    al_draw_filled_rectangle(0, HEIGHT - 30 , WIDTH , WIDTH, al_color_name("purple"));      //Descansos
    al_draw_filled_rectangle(0, HEIGHT/2 -30, WIDTH , WIDTH/2, al_color_name("purple"));

}

void init_obj(ALLEGRO_DISPLAY *display,  ALLEGRO_BITMAP *objbit, int16_t x, int16_t y, int16_t width )
{
    objbit = al_create_bitmap(width,OBJ_H);                                           //Se crea el objeto 
    if (!objbit) {
        printf("failed to create cuadradito bitmap!\n");
    }
    al_set_target_bitmap(objbit);
    al_clear_to_color(al_map_rgb(255, 255, 255));  //Agua
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(objbit, x,y, 0);   
    
}