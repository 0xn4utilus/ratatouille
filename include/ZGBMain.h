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
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif