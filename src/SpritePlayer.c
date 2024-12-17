#include "ZGBMain.h"
#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "Sound.h"
#include "WinUtils.h"

const UINT8 anim_idle[] = {6,0,0,5,5,5,0};
const UINT8 anim_walk[] = {6, 0,1,2,3,4,5};

void START() {
}

void UPDATE() {
    UINT8 i;
	Sprite* spr;
	if(KEY_PRESSED(J_UP)) {
		TranslateSprite(THIS, 0, -1<< delta_time);
		SetSpriteAnim(THIS, anim_walk, 15);
	} 
	if(KEY_PRESSED(J_DOWN)) {
		TranslateSprite(THIS, 0, 1<< delta_time);
		SetSpriteAnim(THIS, anim_walk, 15);
	}
	if(KEY_PRESSED(J_LEFT)) {
		TranslateSprite(THIS, -1 << delta_time, 0);
        THIS->mirror = V_MIRROR;
		SetSpriteAnim(THIS, anim_walk, 15);
	}
	if(KEY_PRESSED(J_RIGHT)) {
		TranslateSprite(THIS, 1 << delta_time, 0);
        THIS->mirror = NO_MIRROR;
		SetSpriteAnim(THIS, anim_walk, 15);
	}
	if(keys == 0) {
		SetSpriteAnim(THIS, anim_idle, 15);
	}

    SPRITEMANAGER_ITERATE(i, spr) {
		if(spr->type == SpriteEnemy2) {
			if(CheckCollision(THIS, spr)) {
				PlayFx(CHANNEL_1, 10, 0x4f, 0xc7, 0xf3, 0x73, 0x86);
				// SetState(StateGame);
					print_text_time("yayyay",0,0,15);
			}
		}
	}
}

void DESTROY() {
}