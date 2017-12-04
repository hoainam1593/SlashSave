
#ifndef __OBSTACLE_POOL_H__
#define __OBSTACLE_POOL_H__

#include "CCF_ObjectPool.h"
#include "Obstacle.h"

namespace SlashSave
{

#define OBSTACLES_SPAWNING_RATE 2
#define OBSTACLES_POOL_SIZE 5

	class ObstaclePool : public CCF_ObjectPool<Obstacle>
	{
	public:
		CCF_GAME_OBJECT_CREATE_FUNC(ObstaclePool)
		
		bool Init(cocos2d::Node* parent);

		void DoAddObject(Obstacle* obj);

	private:
		void AddAnObstacle(float dt);

	};

}

#endif