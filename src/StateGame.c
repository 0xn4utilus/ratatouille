#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Music.h"
#include "WinUtils.h"

DECLARE_MUSIC(level);

IMPORT_MAP(map);
IMPORT_FONT(font);

UINT8 collision_tiles[] = {1, 13, 14, 0};
UINT8 level = 0;
UINT8 initialized_inventory = 0;

void START() {
	
	if(level == 1) {
		level=0;
		scroll_target = SpriteManagerAdd(SpritePlayer, 288, 24);
	}else{
		scroll_target = SpriteManagerAdd(SpritePlayer, 50, 50);
	}

	InitScroll(BANK(map), &map, collision_tiles, 0);
	INIT_FONT(font, PRINT_WIN);

	PlayMusic(level,1);
}

void UPDATE() {
}
