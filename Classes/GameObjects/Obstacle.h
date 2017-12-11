
#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include "CCF_Sprite.h"

namespace SlashSave
{

	class Obstacle : public CCF_Sprite
	{
	public:
		CCF_CREATE_FUNC(Obstacle)
		CCF_GAME_OBJECT_CREATE_FUNC(Obstacle)
		CCF_CLONE_FUNC(Obstacle)
			
		bool Init(cocos2d::Node* parent);
	};

}

#endif