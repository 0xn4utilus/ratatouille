#include "Banks/SetAutoBank.h"
#include "main.h"

#include <gb/gb.h>
#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "Music.h"

IMPORT_MAP(splashmap);

extern UINT8 level;

void START() {
	INIT_BKG(splashmap);
	level = 0;

}

void UPDATE() {
	if(KEY_TICKED(J_START)) {
		SetState(StateGame);
	}

}