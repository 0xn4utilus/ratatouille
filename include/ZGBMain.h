#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(StateMenu)\
_STATE(StateGame)\
_STATE(StateWorld)\
STATE_DEF_END

#define SPRITES \
_SPRITE_DMG(SpritePlayer, player)\
_SPRITE_DMG(SpriteCook, cook)\
_SPRITE_DMG(SpriteEnemy, enemy)\
_SPRITE_DMG(SpriteEnemy2, enemy2)\
_SPRITE_DMG(Apple, apple)\
_SPRITE_DMG(Banana, banana)\
_SPRITE_DMG(Basil, basil)\
_SPRITE_DMG(Broccoli, broccoli)\
_SPRITE_DMG(Cheese, cheese)\
_SPRITE_DMG(Chilli, chilli)\
_SPRITE_DMG(Clove, clove)\
_SPRITE_DMG(Mushroom, mushroom)\
_SPRITE_DMG(Peach, peach)\
_SPRITE_DMG(Potato, potato)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif