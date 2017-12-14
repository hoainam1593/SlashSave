
#include "ShortObstaclePool.h"
#include "LongObstaclePool.h"
#include "CameraGameplay.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;

#define OBSTACLES_SPAWNING_RATE 2

#define SHORT_OBSTACLES_POOL_SIZE 5
#define SHORT_OBSTACLES_EDGE_MARGIN 90.0f

bool ShortObstaclePool::Init(cocos2d::Node* parent)
{
	this->schedule(schedule_selector(ShortObstaclePool::AddAnObstacle), OBSTACLES_SPAWNING_RATE);

	return CCF_ObjectPool<ShortObstacle>::Init(GAMEPLAY_LOCAL_Z_GAME_OBJECT, parent, SHORT_OBSTACLES_POOL_SIZE);
}

void ShortObstaclePool::DoAddObject(ShortObstacle* obj)
{
	// Calculate position.
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto sz = obj->getContentSize();
	auto pos = CCF_Vec2(RandomHelper::random_real(SHORT_OBSTACLES_EDGE_MARGIN, visibleSize.width - SHORT_OBSTACLES_EDGE_MARGIN), -sz.height);

	// Config sprite.
	obj->SetPosition(CameraGameplay::GetInstance()->ScreenToWorldCoordinate(pos), CCF_ANCHOR_LEFT_BOTTOM);
	obj->OnAddObject();
	obj->setVisible(true);
}

void ShortObstaclePool::AddAnObstacle(float dt)
{
	if (RandomHelper::random_int(0, 2) == 0)
	{
		AddObject();
	}
	else
	{
		LongObstaclePool::GetInstance()->AddObject();
	}
}