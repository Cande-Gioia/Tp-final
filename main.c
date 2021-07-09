/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cande
 *
 * Created on 9 de julio de 2021, 08:08
 */

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h> // NO OLVIDAR AGREGAR EN EL LINKER DEL PROYECTO
#define HEIGHT 480
#define WIDTH 480
#define MOVE_RATE  30.0
enum MYKEYS {
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT //arrow keys
};
/*
 * 
 */
int main(void) 
{
    float rana_x = 240.0;
    float rana_y= 450.0;
    ALLEGRO_DISPLAY * display = NULL;  //Crea en puntero al display 
    ALLEGRO_BITMAP *cuadradito = NULL;
    ALLEGRO_BITMAP *rana= NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    bool key_pressed[4] = {false, false, false, false}; //Estado de teclas, true cuando esta apretada
    bool redraw = false;
    bool do_exit = false;
    if (!al_init()) { //Primera funcion a llamar antes de empezar a usar allegro.
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }
        if (!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }

    if (!al_init_primitives_addon()) {
        fprintf(stderr, "failed to initialize primitives!\n");
        return -1;
    }
    display = al_create_display(480, 480);
    if (!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }
        cuadradito = al_create_bitmap(50, 30);
        rana = al_create_bitmap(30,30);
    if (!cuadradito) {
        fprintf(stderr, "failed to create cuadradito bitmap!\n");
        al_destroy_timer(timer);
        return -1;
    }
        
    timer = al_create_timer(1.0 / 5.0);
    if (!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }
    
    event_queue = al_create_event_queue();
    if (!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_bitmap(cuadradito);
        al_destroy_timer(timer);
        return -1;
    }
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source()); //REGISTRAMOS EL TECLADO
    
    
    
    
    
    al_start_timer(timer);
    
       

    
 
   
    al_draw_filled_rectangle(0, 480/2, 480 , 480, al_color_name("black"));
    al_draw_filled_rectangle(0, 450, 480 , 480, al_color_name("purple"));
    al_draw_filled_rectangle(0, 480/2 -30, 480 , 480/2, al_color_name("purple"));
    al_draw_filled_rectangle(0, 0, 480 , 480/2-30, al_color_name("blue"));
    al_draw_filled_rectangle(0, 0, 480 , 30, al_color_name("green"));
    al_set_target_bitmap(cuadradito);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(cuadradito, 200, 400, 0);
    al_set_target_bitmap(rana);
    al_clear_to_color(al_map_rgb(255, 255, 0));
    al_set_target_bitmap(al_get_backbuffer(display));
    al_flip_display();



    
    while (!do_exit) {
        ALLEGRO_EVENT ev;
        if (al_get_next_event(event_queue, &ev)) //Toma un evento de la cola, VER RETURN EN DOCUMENT.
        {
            if (ev.type == ALLEGRO_EVENT_TIMER) {
                if (key_pressed[KEY_UP] && rana_y >= MOVE_RATE)
                    rana_y -= MOVE_RATE;

                if (key_pressed[KEY_DOWN] && rana_y<= 480.0 - 30.0 - MOVE_RATE)
                   rana_y += MOVE_RATE;

                if (key_pressed[KEY_LEFT] && rana_x >= MOVE_RATE)
                    rana_x -= MOVE_RATE;

                if (key_pressed[KEY_RIGHT] && rana_x<= 480.0 -30.0  - MOVE_RATE)
                   rana_x += MOVE_RATE;

                redraw = true;
            }
            else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                do_exit = true;

            else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (ev.keyboard.keycode) {
                    case ALLEGRO_KEY_UP:
                        key_pressed[KEY_UP] = true;
                        break;

                    case ALLEGRO_KEY_DOWN:
                        key_pressed[KEY_DOWN] = true;
                        break;

                    case ALLEGRO_KEY_LEFT:
                        key_pressed[KEY_LEFT] = true;
                        break;

                    case ALLEGRO_KEY_RIGHT:
                        key_pressed[KEY_RIGHT] = true;
                        break;
                }
            }
            else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
                switch (ev.keyboard.keycode) {
                    case ALLEGRO_KEY_UP:
                        key_pressed[KEY_UP] = false;
                        break;

                    case ALLEGRO_KEY_DOWN:
                        key_pressed[KEY_DOWN] = false;
                        break;

                    case ALLEGRO_KEY_LEFT:
                        key_pressed[KEY_LEFT] = false;
                        break;

                    case ALLEGRO_KEY_RIGHT:
                        key_pressed[KEY_RIGHT] = false;
                        break;

                    case ALLEGRO_KEY_ESCAPE:
                        do_exit = true;
                        break;
                }
            }
        }

        if (redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
              
            al_draw_filled_rectangle(0, 480/2, 480 , 480, al_color_name("black"));
            al_draw_filled_rectangle(0, 450, 480 , 480, al_color_name("purple"));
            al_draw_filled_rectangle(0, 480/2 -30, 480 , 480/2, al_color_name("purple"));
            al_draw_filled_rectangle(0, 0, 480 , 480/2-30, al_color_name("blue"));
            al_draw_filled_rectangle(0, 0, 480 , 30, al_color_name("green"));
              al_draw_bitmap(cuadradito, 200, 400, 0);
            al_draw_bitmap(rana, rana_x, rana_y, 0);
            al_flip_display();
        }
    }
    
    
    al_destroy_bitmap(rana);
    al_destroy_bitmap(cuadradito);
    al_destroy_timer(timer);

    al_destroy_display(display); //IMPORTANTE: Destruir recursor empleados
    
    return 0;
    
    
    
    
}

//            al_draw_bitmap(cuadradito,240, 400, 0);