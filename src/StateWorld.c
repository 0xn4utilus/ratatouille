#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Music.h"
#include "WinUtils.h"

DECLARE_MUSIC(level);

IMPORT_MAP(map2);
IMPORT_FONT(font);

extern UINT8 collision_tiles[];
extern UINT8 level;

void START() {
	level = 1 ;
	scroll_target = SpriteManagerAdd(SpritePlayer, 288, 258);
	InitScroll(BANK(map2), &map2, collision_tiles, 0);
	INIT_FONT(font, PRINT_WIN);


}

void UPDATE() {
}
