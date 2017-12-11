
#include "Obstacle.h"
#include "CameraGameplay.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;

#define OBSTACLE_SPRITE_FILE_NAME "sprites/gameplay/obstacle_small.png"
#define OBSTACLE_BODY_WIDTH 130
#define OBSTACLE_BODY_HEIGHT 65

bool Obstacle::Init(cocos2d::Node* parent)
{
	CCF_Sprite::Init(OBSTACLE_SPRITE_FILE_NAME, 0, CCF_ANCHOR_CENTER, parent);
	CreateRectangleBody(OBSTACLE_BODY_WIDTH, OBSTACLE_BODY_HEIGHT, false, nullptr, -1, GAME_OBJECT_TAG_OBSTACLE);

	return true;
}