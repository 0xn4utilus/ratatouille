#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Music.h"
#include "WinUtils.h"

DECLARE_MUSIC(level);

IMPORT_MAP(map4);
IMPORT_FONT(font);

extern UINT8 collision_tiles[];
extern UINT8 level;

void START() {
	level = 1 ;
	scroll_target = SpriteManagerAdd(SpritePlayer, 24, 64);
	InitScroll(BANK(map4), &map4, collision_tiles, 0);
	PlayMusic(level,1);
}

void UPDATE() {
}
