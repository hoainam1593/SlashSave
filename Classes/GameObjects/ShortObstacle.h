
#ifndef __SHORT_OBSTACLE_H__
#define __SHORT_OBSTACLE_H__

#include "CCF_Sprite.h"

namespace SlashSave
{

#define OBSTACLES_FRAME_NAMES_SHORT_OBSTACLE "short obstacle.png"
#define OBSTACLES_FRAME_NAMES_LONG_OBSTACLE "long obstacle.png"

	class ShortObstacle : public CCF_Sprite
	{
	public:
		CCF_CREATE_FUNC(ShortObstacle)
		CCF_GAME_OBJECT_CREATE_FUNC(ShortObstacle)
		CCF_CLONE_FUNC(ShortObstacle)
			
		bool Init(cocos2d::Node* parent);
		void update(float dt);

		void OnAddObject();

	private:
		float m_rotSpeed;
	};

}

#endif