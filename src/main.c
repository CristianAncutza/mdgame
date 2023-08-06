
#include <genesis.h>
#include <resources.h>
#include <music.h>

#define ANIM_STILL 0
#define ANIM_IDLE 1
#define ANIM_WALK 2
#define ANIM_UPPER 3

int attack_timer = 0;
int attack_duration = 56;

Sprite* player;
int player_x = 100;
int player_y = 50;

static void handleInput(){

    //acciones del control
    u16 value = JOY_readJoypad(JOY_1);
    if(value & BUTTON_RIGHT){
        player_x += 1;
        SPR_setAnim(player, ANIM_WALK); //la flecha a la derecha hace que camine
         SPR_setHFlip(player, TRUE); //si esta mirando a la izquierda hace que el sprite gire a la derecha
    }
    else if(value & BUTTON_LEFT){
        player_x -= 1;
        SPR_setAnim(player, ANIM_WALK);//la flecha a la izquiera hace que camine
        SPR_setHFlip(player, FALSE); // si esta mirando a la derecha hace que el sprite gire a la izquierda
    }
    else if(value & BUTTON_UP){
        player_y -= 1;
        SPR_setAnim(player, ANIM_WALK); //movimiento hacia arriba
    }
    else if(value & BUTTON_DOWN){
        player_y += 1;
        SPR_setAnim(player, ANIM_WALK); //movimiento hacia abajo
    }

    if(!(value & BUTTON_DOWN) && !(value & BUTTON_UP) && !(value & BUTTON_LEFT) && !(value & BUTTON_RIGHT)){
        SPR_setAnim(player, ANIM_IDLE); // si no se esta apretando ningun boton se activa la animacion de idle para el personaje
    }

    SPR_setPosition(player, player_x, player_y);
}

static void joyEvent(u16 joy, u16 changed, u16 state){
    if((changed & state & BUTTON_B) && attack_timer == 0){
        SPR_setAnim(player, ANIM_UPPER); //animacion de golpe con boton b
        attack_timer += 1;
    }
}

int main()
{
    
    SPR_init();
    PAL_setPalette(PAL2, our_sprite.palette->data, DMA);
    player = SPR_addSprite(&our_sprite,100,50, TILE_ATTR(PAL2, FALSE, FALSE, TRUE));
    JOY_setEventHandler(joyEvent);

    //seteo el sonido/musica   
    XGM_setLoopNumber(1000);
    SND_startPlay_XGM(soundtrack);
    while(1)
    {
       
        if(attack_timer == 0) handleInput();
        else if(attack_timer > 0 && attack_timer < attack_duration) attack_timer += 1;
        else if(attack_timer == attack_duration) attack_timer = 0;
        
        SPR_update();     
        SYS_doVBlankProcess();
    }
    return (0);
}
