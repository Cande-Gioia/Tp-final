

#include "level_1.h"

void level_1 (obj_arr_t objetos)

{
    bool key_pressed[4] = {false, false, false, false}; //Estado de teclas, true cuando esta apretada
    bool do_exit = false;
    ALLEGRO_DISPLAY*display = NULL;  //Crea en puntero al display 
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;  //Crea la secuencia de eventos
    ALLEGRO_TIMER *timer = NULL;  // Crea el timer
    timer = al_create_timer(1.0 / FPS);

    if (!timer)                                      
    {
        printf("failed to create timer!\n");
      
    }
    if (!al_install_keyboard()) 
    {
        printf( "failed to initialize the keyboard!\n");
    
    }

    event_queue = al_create_event_queue(); 
    
    if (!event_queue) 
    {
        printf("failed to create event_queue!\n");
        al_destroy_timer(timer);

    }

    display = al_create_display(HEIGHT, WIDTH); // Crea el display
    if (!display) 
    {
        printf( "failed to create display!\n"); //Avisa si hubo error

    }
    if (!al_init_primitives_addon())            //Inicializa las primitivas 
    {
        printf( "failed to initialize primitives!\n"); //Avisa si hubo error
    }
  
 

   al_register_event_source(event_queue, al_get_keyboard_event_source());
   al_register_event_source(event_queue, al_get_display_event_source(display));
   al_register_event_source(event_queue, al_get_timer_event_source(timer));

   rana_t rana = { INIT_X*30 ,INIT_Y*30,0,3 , NULL};    //BACK!!!
   rana.pointer =  init(display,rana);                                              //Se inicializa el escenario y la rana
  
   init_obj(display,objetos.arr[0].pointer, objetos.arr[0].pos_x, objetos.arr[0].pos_y,objetos.arr[0].width);       //Se inicializa el auto
   init_obj(display,objetos.arr[1].pointer, objetos.arr[1].pos_x, objetos.arr[1].pos_y,objetos.arr[1].width);       //Se inicializa el auto
   al_flip_display();                                          //Se muestra en display 
   al_start_timer(timer);
 
                
int i;
while (!do_exit) 
{
  ALLEGRO_EVENT ev;
  if (al_get_next_event(event_queue, &ev)) //Toma un evento de la cola, VER RETURN EN DOCUMENT.
  {
      if (ev.type == ALLEGRO_EVENT_TIMER) 
      {
          if (key_pressed[KEY_UP])
          {
              
          rana = movimiento_rana('U',rana , MOVE_RATE_RANA);
          
          for (i=0; i<CANT_OBJ; i++)
          {
            rana = check_colision(rana, objetos.arr[i]); 
          }
          
          
         

         }
           if (key_pressed[KEY_DOWN])
          {
          rana = movimiento_rana('D',rana , MOVE_RATE_RANA);
          
          for (i=0; i<CANT_OBJ; i++)
          {
            rana = check_colision(rana, objetos.arr[i]); 
          }
          

         }
          if (key_pressed[KEY_LEFT])
          {
          rana = movimiento_rana('L',rana , MOVE_RATE_RANA);
          
          for (i=0; i<CANT_OBJ; i++)
          {
            rana = check_colision(rana, objetos.arr[i]); 
          }
          

         }
          if (key_pressed[KEY_RIGHT])
          {
            rana = movimiento_rana('R',rana , MOVE_RATE_RANA);
          
          for (i=0; i<CANT_OBJ; i++)
          {
            rana = check_colision(rana, objetos.arr[i]); 
          }
          
         

         }
          /*if(autoo.pos_x >= WIDTH )
          {

              autoo.pos_x= -1.0 * autoo.width* 10;

          }
          else if(auto1.pos_x <= -autoo.width)
          {
              auto1.pos_x= autoo.width* 20;
          }
          else
          {
            autoo.pos_x = autoo.pos_x + 10.0;
            auto1.pos_x = auto1.pos_x - 15.0;
          } BACK!!!!!*/  

      
      
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
      if (al_is_event_queue_empty(event_queue)) 
      {

          for (i=0; i<CANT_OBJ; i++)
          {
            rana = check_colision(rana, objetos.arr[i]); 
          }
          

        init(display,rana);
        al_draw_bitmap(rana.pointer, rana.pos_x, rana.pos_y, 0);
             for (i=0; i<CANT_OBJ; i++)
          {
            init_obj(display,objetos.arr[i].pointer, objetos.arr[i].pos_x, objetos.arr[i].pos_y, objetos.arr[i].width);  //Se inicializa el auto
          }
          
        al_flip_display();
      } 


    }
    
      
   al_destroy_event_queue(event_queue);  
   al_destroy_display(display); 
    
    
    
}