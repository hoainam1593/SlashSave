
#include "CoinPickup.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;

bool CoinPickup::Init(cocos2d::Node* parent)
{
	CCF_Sprite::Init(COIN_PICKUP_SPRITE_FILE_NAME, 0, CCF_ANCHOR_CENTER, parent);
	CreateCircleBody(COIN_PICKUP_BODY_RADIUS, false, nullptr, 0, GAME_OBJECT_TAG_COIN_PICKUP);

	return true;
}

cocos2d::Node* CoinPickup::Clone()
{
	auto other = CoinPickup::Create();

	CopyTo(other);

	return other;
}

bool CoinPickup::OnCollideWith(cocos2d::PhysicsBody* other)
{
	if (other->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		OnDestroy();
		return false;
	}

	return true;
}

void CoinPickup::OnDestroy()
{
	setVisible(false);
}