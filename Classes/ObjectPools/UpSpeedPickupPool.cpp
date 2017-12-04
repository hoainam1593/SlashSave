
#include "UpSpeedPickupPool.h"
#include "CameraGameplay.h"

using namespace cocos2d;
using namespace SlashSave;

bool UpSpeedPickupPool::Init(cocos2d::Node* parent)
{
	this->schedule(schedule_selector(UpSpeedPickupPool::AddAPickup), UP_SPEED_PICKUP_SPAWNING_RATE);

	return CCF_ObjectPool<UpSpeedPickup>::Init(parent, UP_SPEED_PICKUP_POOL_SIZE);
}

void UpSpeedPickupPool::DoAddObject(UpSpeedPickup* obj)
{
	// Calculate position.
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto sz = obj->getContentSize();
	auto pos = CCF_Vec2(RandomHelper::random_real(0.0f, visibleSize.width), -sz.height);

	// Config sprite.
	obj->SetPosition(CameraGameplay::GetInstance()->ScreenToWorldCoordinate(pos), CCF_ANCHOR_LEFT_BOTTOM);
	obj->setVisible(true);
}

void UpSpeedPickupPool::AddAPickup(float dt)
{
	AddObject();
}