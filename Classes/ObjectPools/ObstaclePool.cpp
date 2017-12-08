
#include "ObstaclePool.h"
#include "CameraGameplay.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;

bool ObstaclePool::Init(cocos2d::Node* parent)
{
	this->schedule(schedule_selector(ObstaclePool::AddAnObstacle), OBSTACLES_SPAWNING_RATE);

	return CCF_ObjectPool<Obstacle>::Init(GAMEPLAY_LOCAL_Z_GAME_OBJECT, parent, OBSTACLES_POOL_SIZE);
}

void ObstaclePool::DoAddObject(Obstacle* obj)
{
	// Calculate position.
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto sz = obj->getContentSize();
	auto pos = CCF_Vec2(0, -sz.height);

	if (RandomHelper::random_int(0, 1) == 0)
	{
		pos.x = sz.width / 2.0f;
	}
	else
	{
		pos.x = visibleSize.width - sz.width / 2.0f;
	}

	// Config sprite.
	obj->SetPosition(CameraGameplay::GetInstance()->ScreenToWorldCoordinate(pos), CCF_ANCHOR_LEFT_BOTTOM);
	obj->setVisible(true);
}

void ObstaclePool::AddAnObstacle(float dt)
{
	AddObject();
}