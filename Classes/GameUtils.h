
#ifndef __GAME_UTILS_H__
#define __GAME_UTILS_H__

#include "CCF_Utils.h"

namespace SlashSave
{
	enum
	{
		GAME_OBJECT_TAG_PLAYER,
		GAME_OBJECT_TAG_BRUSH_DOT,
		GAME_OBJECT_TAG_OBSTACLE,
		GAME_OBJECT_TAG_UP_SPEED_PICKUP,
		GAME_OBJECT_TAG_COIN_PICKUP
	};

	bool IsInScreen(const CCF_Vec2& worldCoord);
}

#endif