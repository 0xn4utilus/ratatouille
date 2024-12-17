#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Music.h"
#include "WinUtils.h"

DECLARE_MUSIC(level);

IMPORT_MAP(map);
IMPORT_FONT(font);

UINT8 collision_tiles_world[] = {1, 13, 14, 0};
UINT8 level;

void START() {
	level=0;
	scroll_target = SpriteManagerAdd(SpritePlayer, 50, 50);
	InitScroll(BANK(map), &map, collision_tiles_world, 0);
	INIT(font);


	// PlayMusic(level,1);
}

void UPDATE() {
}
