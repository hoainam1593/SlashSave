
#include "CoinPickup.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;
using namespace std;

#define COIN_PICKUP_PLIST_FILE_NAME "sprites/gameplay/coin.plist"
#define COIN_PICKUP_NUMBER_OF_FRAMES 10
#define COIN_PICKUP_ANIM_FPS 10
#define COIN_PICKUP_BODY_RADIUS 21

bool CoinPickup::Init(cocos2d::Node* parent)
{
	vector<CCF_String> names;
	CCF_BuildFrameNames(names, COIN_PICKUP_NUMBER_OF_FRAMES, 0, "", ".png");

	CCF_SpriteAnim::Init(COIN_PICKUP_PLIST_FILE_NAME, names, COIN_PICKUP_ANIM_FPS, 0, CCF_ANCHOR_CENTER, parent);
	CreateCircleBody(COIN_PICKUP_BODY_RADIUS, false, nullptr, 0, GAME_OBJECT_TAG_COIN_PICKUP);

	return true;
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