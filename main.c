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
#define FPS 5.0

auto_t autoo;
rana_t rana = { WIDTH/2 -RANA_W/2,HEIGHT,3 };
ALLEGRO_BITMAP *autobit= NULL;    
void init (ALLEGRO_DISPLAY *display);
void landscape (void);
void init_car(ALLEGRO_DISPLAY *display);
int main(void) 
{


    ALLEGRO_DISPLAY *display = NULL;  //Crea en puntero al display 
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    bool do_exit = false;
    autoo.pos_x = 90.0;
       autoo.pos_y = FILA_H;

    if (!al_init()) {
        printf( "failed to initialize allegro!\n");
    }

    timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        printf("failed to create timer!\n");
      
    }
    
    
    event_queue = al_create_event_queue();
    if (!event_queue) {
        printf("failed to create event_queue!\n");
        al_destroy_timer(timer);

    }
    


    display = al_create_display(HEIGHT, WIDTH); // Intenta crear display de 640x480 de fallar devuelve NULL
    if (!display) {
        printf( "failed to create display!\n");

    }
    if (!al_init_primitives_addon()) {
        printf( "failed to initialize primitives!\n");
    }
  
 

   al_register_event_source(event_queue, al_get_timer_event_source(timer));
   al_register_event_source(event_queue, al_get_display_event_source(display));
    
   init(display);
   al_flip_display();
   al_start_timer(timer);
                

    while (!do_exit) 
    {
      ALLEGRO_EVENT ev;
      if (al_get_next_event(event_queue, &ev)) //Toma un evento de la cola, VER RETURN EN DOCUMENT.
      {
          if (ev.type == ALLEGRO_EVENT_TIMER) {
              if(autoo.pos_x >= WIDTH)
              {
                  
                  autoo.pos_x= -300.0;
                  
              }
              else
              {
                autoo.pos_x = autoo.pos_x + 30.0;
              }

          }
          else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
              do_exit = true;
      }
          if (al_is_event_queue_empty(event_queue)) {
     
          init(display);
          al_flip_display();
        } 

      
    }
    
      
       al_destroy_event_queue(event_queue);  
   al_destroy_display(display); 
    
   return 0; 
}
void init (ALLEGRO_DISPLAY *display)
{
    ALLEGRO_BITMAP *ranabit= NULL; 
    rana.pointer = ranabit;

    ranabit = al_create_bitmap(RANA_W,RANA_W);
    if (!ranabit) {
        printf("failed to create cuadradito bitmap!\n");
    }
    landscape();
     init_car(display); 
    

    al_set_target_bitmap(ranabit);
    al_clear_to_color(al_map_rgb(0, 255, 0));  //Agua
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(ranabit,  WIDTH/2 -RANA_W/2,HEIGHT-RANA_H, 0);   
    
    
}
void landscape(void)

{
    al_draw_filled_rectangle(0, RANA_H , WIDTH , HEIGHT/2-RANA_H, al_color_name("blue"));
    al_draw_filled_rectangle(0, HEIGHT/2, WIDTH, HEIGHT, al_color_name("black"));  //Calle 
    al_draw_filled_rectangle(0, HEIGHT - 30 , WIDTH , WIDTH, al_color_name("purple"));
    al_draw_filled_rectangle(0, HEIGHT/2 -30, WIDTH , WIDTH/2, al_color_name("purple"));

}

void init_car(ALLEGRO_DISPLAY *display)
{

    autoo.pointer = autobit;
     
     
    autobit = al_create_bitmap(RANA_W*2,RANA_H);
    if (!autobit) {
        printf("failed to create cuadradito bitmap!\n");
    }
    al_set_target_bitmap(autobit);
    al_clear_to_color(al_map_rgb(255, 255, 255));  //Agua
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(autobit, autoo.pos_x,autoo.pos_y, 0);   
    
    
}


    
        
