#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Music.h"
#include "WinUtils.h"

DECLARE_MUSIC(level);

IMPORT_MAP(map);
IMPORT_FONT(font);

UINT8 collision_tiles[] = {1, 0};
UINT8 level;

void START() {
	
	scroll_target = SpriteManagerAdd(SpritePlayer, 50, 50);
	InitScroll(BANK(map), &map, collision_tiles, 0);
	INIT(font);
	// INIT_FONT(font, PRINT_WIN); PRINT_POS(0, 0); WX_REG = 7; WY_REG = 136; SHOW_WIN;
	

	print_text("AAA");


	
	PlayMusic(level,1);
}

void UPDATE() {
}
