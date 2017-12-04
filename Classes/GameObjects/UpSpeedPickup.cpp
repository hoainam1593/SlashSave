
#include "UpSpeedPickup.h"
#include "GameUtils.h"
#include "CameraGameplay.h"

using namespace cocos2d;
using namespace SlashSave;

bool UpSpeedPickup::Init(cocos2d::Node* parent)
{
	CCF_Sprite::Init(UP_SPEED_PICKUP_SPRITE_FILE_NAME, 0, CCF_ANCHOR_CENTER, parent);
	CreateCircleBody(UP_SPEED_PICKUP_BODY_RADIUS, false, nullptr, 0, GAME_OBJECT_TAG_UP_SPEED_PICKUP);

	return true;
}

cocos2d::Node* UpSpeedPickup::Clone()
{
	auto other = UpSpeedPickup::Create();

	CopyTo(other);

	return other;
}

bool UpSpeedPickup::OnCollideWith(cocos2d::PhysicsBody* other)
{
	if (other->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		OnDestroy();
		return false;
	}

	return true;
}

void UpSpeedPickup::OnDestroy()
{
	setVisible(false);
}