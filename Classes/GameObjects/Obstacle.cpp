
#include "Obstacle.h"
#include "CameraGameplay.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;

bool Obstacle::Init(cocos2d::Node* parent)
{
	CCF_Sprite::Init(OBSTACLE_SPRITE_FILE_NAME, 0, CCF_ANCHOR_CENTER, parent);
	CreateRectangleBody(OBSTACLE_BODY_WIDTH, OBSTACLE_BODY_HEIGHT, false, nullptr, -1, GAME_OBJECT_TAG_OBSTACLE);

	return true;
}

cocos2d::Node* Obstacle::Clone()
{
	auto other = Obstacle::Create();

	CopyTo(other);

	return other;
}