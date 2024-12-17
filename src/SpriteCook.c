#include "Banks/SetAutoBank.h"

#include "SpriteManager.h"
#include "Sound.h"

UINT8 anim_idle_cook[]= {10,0,0,0,0,0,1,1,1,1,1};

void START() {

}

void UPDATE() {
    SetSpriteAnim(THIS,anim_idle_cook,15);

}

void DESTROY() {
}