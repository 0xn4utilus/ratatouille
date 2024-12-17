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

void UPDATE() {
    UINT8 i;
	Sprite* spr;
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

    SPRITEMANAGER_ITERATE(i, spr) {
		if(spr->type == SpriteCook) {
			if(CheckCollision(THIS, spr)) {
				print_text("yayyay");
			}
		}
	}

	print_text("");
	Printf("%d",tile_collision);
	if(tile_collision == 0) {
		CLEAR;
	}
	if(tile_collision == 14){
		SetState(StateWorld);
		tile_collision  =0;
	}
}

void DESTROY() {
}