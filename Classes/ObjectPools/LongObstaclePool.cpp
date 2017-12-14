
#include "LongObstaclePool.h"
#include "CameraGameplay.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;

#define LONG_OBSTACLES_POOL_SIZE 5

LongObstaclePool* LongObstaclePool::s_instance = nullptr;

bool LongObstaclePool::Init(cocos2d::Node* parent)
{
	return CCF_ObjectPool<LongObstacle>::Init(GAMEPLAY_LOCAL_Z_GAME_OBJECT, parent, LONG_OBSTACLES_POOL_SIZE);
}

void LongObstaclePool::DoAddObject(LongObstacle* obj)
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
	obj->OnAddObject();
	obj->setVisible(true);
}
