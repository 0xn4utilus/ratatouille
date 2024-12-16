#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Music.h"

DECLARE_MUSIC(level);

IMPORT_MAP(map);

UINT8 collision_tiles[] = {1, 0};
UINT8 level;

void START() {
	// NR52_REG = 0x80; //Enables sound, you should always setup this first
	// NR51_REG = 0xFF; //Enables all channels (left and right)
	// NR50_REG = 0x77; //Max volume
	scroll_target = SpriteManagerAdd(SpritePlayer, 50, 50);
	InitScroll(BANK(map), &map, collision_tiles, 0);
	
	// PlayMusic(level,1);
}

void UPDATE() {
}
