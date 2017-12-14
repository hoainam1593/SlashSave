
#ifndef __LONG_OBSTACLE_POOL_H__
#define __LONG_OBSTACLE_POOL_H__

#include "CCF_ObjectPool.h"
#include "LongObstacle.h"

namespace SlashSave
{

	class LongObstaclePool : public CCF_ObjectPool<LongObstacle>
	{
		CCF_GET_INSTANCE_FUNC(LongObstaclePool)

	public:
		CCF_GAME_OBJECT_CREATE_FUNC(LongObstaclePool)
		
		bool Init(cocos2d::Node* parent);

		void DoAddObject(LongObstacle* obj);

	};

}

#endif