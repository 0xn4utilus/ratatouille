#include "ZGBMain.h"
#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "Sound.h"
#include "WinUtils.h"

const UINT8 anim_idle[] = {6,0,0,5,5,5,0};
const UINT8 anim_walk[] = {6, 0,1,2,3,4,5};

extern UINT8 level;

void START() {
}
UINT8 tile_collision;

void wait_for_start_press(){
	while (1){	
		UPDATE_KEYS();
		if(KEY_PRESSED(J_START)){
			break;
		}
	}
}

void Movement() {
	if(KEY_PRESSED(J_UP)) {
		tile_collision = TranslateSprite(THIS, 0, -1<< delta_time);
		SetSpriteAnim(THIS, anim_walk, 15);
	} 
	if(KEY_PRESSED(J_DOWN)) {
		tile_collision = TranslateSprite(THIS, 0, 1<< delta_time);
		SetSpriteAnim(THIS, anim_walk, 15);
	}
	if(KEY_PRESSED(J_LEFT)) {
		tile_collision = TranslateSprite(THIS, -1 << delta_time, 0);
        THIS->mirror = V_MIRROR;
		SetSpriteAnim(THIS, anim_walk, 15);
	}
	if(KEY_PRESSED(J_RIGHT)) {
		tile_collision = TranslateSprite(THIS, 1 << delta_time, 0);
        THIS->mirror = NO_MIRROR;
		SetSpriteAnim(THIS, anim_walk, 15);
	}
	if(keys == 0) {
		SetSpriteAnim(THIS, anim_idle, 15);
	}
}

void UPDATE() {
    UINT8 i;
	Sprite* spr;
	UINT8 collision_state = 0;
	Movement();

    SPRITEMANAGER_ITERATE(i, spr) {
		if(spr->type == SpriteCook) {
			if(CheckCollision(THIS, spr)) {
				print_text("GIMME PEACH THEN MAYBE I TEACH!!!");
				collision_state = 1;
			}
		}else if (spr->type == SpriteEnemy){
			if(CheckCollision(THIS,spr)) {
				print_text("NO BANANA???  DIE!!!     PRESS START");
				collision_state = 1;
				wait_for_start_press();
				SetState(StateGame);
				
				
			}
		}
	}

	if(collision_state == 0){
		clear_text();
	}

	
	if(tile_collision == 14){
		if(level == 0)SetState(StateWorld);
		else SetState(StateGame);
		tile_collision  = 0;
	}
}

void DESTROY() {
}