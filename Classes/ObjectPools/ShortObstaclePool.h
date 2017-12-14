
#ifndef __SHORT_OBSTACLE_POOL_H__
#define __SHORT_OBSTACLE_POOL_H__

#include "CCF_ObjectPool.h"
#include "ShortObstacle.h"

namespace SlashSave
{

	class ShortObstaclePool : public CCF_ObjectPool<ShortObstacle>
	{
	public:
		CCF_GAME_OBJECT_CREATE_FUNC(ShortObstaclePool)
		
		bool Init(cocos2d::Node* parent);

		void DoAddObject(ShortObstacle* obj);

	private:
		void AddAnObstacle(float dt);

	};

}

#endif