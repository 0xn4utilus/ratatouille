#include "ZGBMain.h"
#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "Sound.h"
#include "WinUtils.h"
#include "Math.h"

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
	inventory->PeachCount = 1;
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
	for(i = 0; i < (UINT8)50u; i++){
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

void print_inventory(){
    CUSTOM_DATA* inventory = (CUSTOM_DATA*)THIS->custom_data;
    WX_REG = 7; 
    WY_REG = 144 - (12<<3); 
	SHOW_WIN;
    PRINT_POS(0, 0); 
    Printf("     INVENTORY");
    PRINT_POS(0, 1); 
    Printf("--------------------");
    PRINT_POS(4,2);
    Printf("Apple     %d", inventory->AppleCount);
    PRINT_POS(4,3);
	Printf("Banana    %d", inventory->BananaCount);
	PRINT_POS(4,4);
	Printf("Basil     %d", inventory->BasilCount);
	PRINT_POS(4,5);
	Printf("Broccoli  %d", inventory->BroccoliCount);
	PRINT_POS(4,6);
	Printf("Cheese    %d", inventory->CheeseCount);
	PRINT_POS(4,7);
	Printf("Chilli    %d", inventory->ChilliCount);
	PRINT_POS(4,8);
	Printf("Clove     %d", inventory->CloveCount);
	PRINT_POS(4,9);
	Printf("Mushroom  %d", inventory->MushroomCount);
	PRINT_POS(4,10);
	Printf("Peach     %d", inventory->PeachCount);
	PRINT_POS(4,11);
	Printf("Potato    %d", inventory->PotatoCount);
}



void check_ingridients(CUSTOM_DATA* inventory ){
	char flag[] = {120, 33, 56, 85, 25, 122, 27, 62, 78, 117, 37, 32, 52, 28, 95, 104, 66, 57, 88};

	char  items[] = {inventory->AppleCount, inventory->BananaCount, inventory->BasilCount, inventory->BroccoliCount, inventory->CheeseCount, inventory->ChilliCount, inventory->CloveCount, inventory->MushroomCount, inventory->PeachCount, inventory->PotatoCount};
	if(inventory->AppleCount == 8 && inventory->BananaCount == 16 && inventory->BasilCount == 66 && inventory->BroccoliCount == 47 && inventory->CheeseCount == 45 && inventory->ChilliCount  == 9 && inventory->CloveCount == 54 && inventory->MushroomCount == 10 && inventory->PeachCount == 60 && inventory->PotatoCount == 70){
		char result[sizeof(flag)+1];
		for (UINT8 i = 0; i < sizeof(flag); i++) {
			result[i] = flag[i] ^ items[i % sizeof(items)];
		}
		result[sizeof(flag)] = '\0';

		print_text(result);
		wait_few_ticks();
		wait_few_ticks();
		wait_few_ticks();
	}
}

void UPDATE() {
    UINT8 i;
	Sprite* spr;
	UINT8 collision_state = 0;
	CUSTOM_DATA* inventory = (CUSTOM_DATA*)THIS->custom_data;

	Movement();
	
	if(KEY_PRESSED(J_SELECT)){
		print_inventory();
		wait_few_ticks();
		clear_lines(11);	
	}
	
    SPRITEMANAGER_ITERATE(i, spr) {
		if(spr->type == SpriteCook) {
			if(CheckCollision(THIS, spr)) {
				if(inventory->PeachCount > 0) {
					check_ingridients(inventory);
					print_text("A good dish is made with right ingredients in right amount!                     PRESS SELECT to see your inventory");
				} else {
					print_text("BRING PEACH THEN MAYBE I CAN TEACH!!!");
				}
				collision_state = 1;
			}
		}else if (spr->type == SpriteEnemy){
			if(CheckCollision(THIS,spr)) {
				collision_state = 1;
				if(inventory->BananaCount > 0) {
					print_text("BANANA!!!  YOU ARE MY FRIEND NOW!!!             PRESS START");
					wait_few_ticks();
					wait_few_ticks();
					SpriteManagerRemoveSprite(spr);
					inventory->BananaCount--;
				} else {
					print_text("NO BANANA???  DIE!!!     PRESS START");
					wait_for_start_press();
					SetState(StateGame);
				}
			}
		}else if (spr->type == SpriteEnemy2){
			if(CheckCollision(THIS,spr)) {
				collision_state = 1;
				if(inventory->AppleCount > 0) {
					print_text("APPLE!!!  YOU ARE MY FRIEND NOW!!!              PRESS START");
					wait_few_ticks();
					wait_few_ticks();
					SpriteManagerRemoveSprite(spr);
					inventory->AppleCount--;
				} else {
					print_text("NO APPLE???  DIE!!!     PRESS START");
					wait_for_start_press();
					SetState(StateGame);
				}
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
	if(tile_collision == 13){
		print_text("YOU DROWNED!!!      PRESS START");
		wait_for_start_press();
		SetState(StateGame);
		tile_collision  = 0;
	}
}

void DESTROY() {
}