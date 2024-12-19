#include "ZGBMain.h"
#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "Sound.h"
#include "WinUtils.h"

const UINT8 anim_idle[] = {6,0,0,5,5,5,0};
const UINT8 anim_walk[] = {6, 0,1,2,3,4,5};

extern UINT8 level;

typedef struct {
	UINT8 AppleCount;
	UINT8 BananaCount;
	UINT8 BasilCount;
	UINT8 BroccoliCount;
	UINT8 CheeseCount;
	UINT8 ChilliCount;
	UINT8 CloveCount;
	UINT8 MushroomCount;
	UINT8 PeachCount;
	UINT8 PotatoCount;
} CUSTOM_DATA;



void START() {
	CUSTOM_DATA* inventory = (CUSTOM_DATA*)THIS->custom_data;
	inventory->AppleCount = 0;
	inventory->BananaCount = 0;
	inventory->BasilCount = 0;
	inventory->BroccoliCount = 0;
	inventory->CheeseCount = 0;
	inventory->ChilliCount = 0;
	inventory->CloveCount = 0;
	inventory->MushroomCount = 0;
	inventory->PeachCount = 0;
	inventory->PotatoCount = 0;
}

UINT8 tile_collision;
UINT8 instructed = 0;

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

void wait_few_ticks(){
	UINT8 i;
	for(i = 0; i < (UINT8)40u; i++){
		wait_vbl_done();
	}
}

void UpdateInventory() {
	UINT8 i;
	Sprite* spr;
	CUSTOM_DATA* inventory = (CUSTOM_DATA*)THIS->custom_data;
	SPRITEMANAGER_ITERATE(i, spr) {
	if (CheckCollision(THIS, spr)) {
		switch (spr->type) {
			case Apple:
				print_text("APPLE!!!");
				inventory->AppleCount++;
				SpriteManagerRemoveSprite(spr);
				wait_few_ticks();
				break;
			case Banana:
				print_text("BANANA!!!");
				inventory->BananaCount++;
				SpriteManagerRemoveSprite(spr);
				wait_few_ticks();
				break;
			case Basil:
				print_text("BASIL!!!");
				inventory->BasilCount++;
				SpriteManagerRemoveSprite(spr);
				wait_few_ticks();
				break;
			case Broccoli:
				print_text("BROCCOLI!!!");
				inventory->BroccoliCount++;
				SpriteManagerRemoveSprite(spr);
				wait_few_ticks();
				break;
			case Cheese:
				print_text("CHEESE!!!");
				inventory->CheeseCount++;
				SpriteManagerRemoveSprite(spr);
				wait_few_ticks();
				break;
			case Chilli:
				print_text("CHILLI!!!");
				SpriteManagerRemoveSprite(spr);
				wait_few_ticks();
				inventory->ChilliCount++;
				break;
			case Clove:
				print_text("CLOVE!!!");
				inventory->CloveCount++;
				SpriteManagerRemoveSprite(spr);
				wait_few_ticks();
				break;
			case Mushroom:
				print_text("MUSHROOM!!!");
				inventory->MushroomCount++;
				SpriteManagerRemoveSprite(spr);
				wait_few_ticks();
				break;
			case Peach:
				print_text("PEACH!!!");
				inventory->PeachCount++;
				SpriteManagerRemoveSprite(spr);
				wait_few_ticks();
				break;
			case Potato:
				print_text("POTATO!!!");
				SpriteManagerRemoveSprite(spr);
				wait_few_ticks();
				inventory->PotatoCount++;
				break;
			default:
				break;
		}
	}
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
	UpdateInventory();

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