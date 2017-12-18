
#include "ShortObstacle.h"
#include "CCF_SpriteSheet.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;
using namespace std;

#define SHORT_OBSTACLE_BODY_RADIUS 31
#define SHORT_OBSTACLE_MIN_ROT_SPEED 40.0f
#define SHORT_OBSTACLE_MAX_ROT_SPEED 90.0f

bool ShortObstacle::Init(cocos2d::Node* parent)
{
	vector<CCF_String> names = OBSTACLES_FRAME_NAMES;
	auto sheet = CCF_SpriteSheet::Create(OBSTACLES_SPRITE_FILE_NAME, OBSTACLES_PLIST_FILE_NAME, names, 0, nullptr);

	CCF_Sprite::Init(sheet, OBSTACLES_FRAME_NAMES_SHORT_OBSTACLE, 0, CCF_ANCHOR_CENTER, parent);
	CreateCircleBody(SHORT_OBSTACLE_BODY_RADIUS, false, nullptr, -1, GAME_OBJECT_TAG_OBSTACLE);

	return true;
}

void ShortObstacle::update(float dt)
{
	auto rot = this->getRotation();
	rot += m_rotSpeed * dt;
	this->setRotation(rot);
}

void ShortObstacle::OnAddObject()
{
	m_rotSpeed = RandomHelper::random_real(SHORT_OBSTACLE_MIN_ROT_SPEED, SHORT_OBSTACLE_MAX_ROT_SPEED);
	if (RandomHelper::random_int(0, 1) == 0)
	{
		m_rotSpeed *= -1;
	}
}