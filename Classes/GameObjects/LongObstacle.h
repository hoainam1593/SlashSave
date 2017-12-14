
#ifndef __LONG_OBSTACLE_H__
#define __LONG_OBSTACLE_H__

#include "CCF_Sprite.h"

namespace SlashSave
{

	class LongObstacle : public CCF_Sprite
	{
	public:
		CCF_CREATE_FUNC(LongObstacle)
		CCF_GAME_OBJECT_CREATE_FUNC(LongObstacle)
		CCF_CLONE_FUNC(LongObstacle)
			
		bool Init(cocos2d::Node* parent);
		void update(float dt);

		void OnAddObject();

	private:
		float m_totalTime;
		CCF_Vec2 m_oriPos;
		float m_moveIntensity, m_moveFrequency;
	};

}

#endif