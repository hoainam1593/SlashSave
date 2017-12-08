
#include "CoinPickupPool.h"
#include "CameraGameplay.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;

bool CoinPickupPool::Init(cocos2d::Node* parent)
{
	this->schedule(schedule_selector(CoinPickupPool::AddAPickup), COIN_PICKUP_SPAWNING_RATE);

	return CCF_ObjectPool<CoinPickup>::Init(GAMEPLAY_LOCAL_Z_GAME_OBJECT, parent, COIN_PICKUP_POOL_SIZE);
}

void CoinPickupPool::DoAddObject(CoinPickup* obj)
{
	// Calculate position.
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto sz = obj->getContentSize();
	auto pos = CCF_Vec2(RandomHelper::random_real(0.0f, visibleSize.width), -sz.height);

	// Config sprite.
	obj->SetPosition(CameraGameplay::GetInstance()->ScreenToWorldCoordinate(pos), CCF_ANCHOR_LEFT_BOTTOM);
	obj->setVisible(true);
}

void CoinPickupPool::AddAPickup(float dt)
{
	AddObject();
}