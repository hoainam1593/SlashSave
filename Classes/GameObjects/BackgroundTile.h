
#ifndef __BACKGROUND_TILE_H__
#define __BACKGROUND_TILE_H__

#include "CCF_Sprite.h"

namespace SlashSave
{

#define BACKGROUND_TILE_SPRITE_FILE_NAME "sprites/gameplay/background_day.png"

	class BackgroundTile : public CCF_Sprite
	{
	public:
		CCF_CREATE_FUNC(BackgroundTile)
		CCF_GAME_OBJECT_CREATE_FUNC(BackgroundTile)
		CCF_CLONE_FUNC(BackgroundTile)

		bool Init(cocos2d::Node* parent);
	};

}

#endif