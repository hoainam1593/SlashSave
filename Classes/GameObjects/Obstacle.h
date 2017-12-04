
#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include "CCF_Sprite.h"

namespace SlashSave
{

#define OBSTACLE_SPRITE_FILE_NAME "obstacle.png"
#define OBSTACLE_BODY_WIDTH 200
#define OBSTACLE_BODY_HEIGHT 25

	class Obstacle : public CCF_Sprite
	{
	public:
		CCF_CREATE_FUNC(Obstacle)
		CCF_GAME_OBJECT_CREATE_FUNC(Obstacle)
			
		bool Init(cocos2d::Node* parent);
		cocos2d::Node* Clone();
	};

}

#endif