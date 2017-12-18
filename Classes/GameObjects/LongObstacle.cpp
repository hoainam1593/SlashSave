
#include "LongObstacle.h"
#include "ShortObstacle.h"
#include "CCF_SpriteSheet.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;
using namespace std;

#define LONG_OBSTACLE_BODY_WIDTH 139
#define LONG_OBSTACLE_BODY_HEIGHT 68

#define LONG_OBSTACLE_MIN_MOVE_FREQUENCY 8.0f
#define LONG_OBSTACLE_MAX_MOVE_FREQUENCY 12.0f
#define LONG_OBSTACLE_MIN_MOVE_INTENSITY 5.0f
#define LONG_OBSTACLE_MAX_MOVE_INTENSITY 10.0f

bool LongObstacle::Init(cocos2d::Node* parent)
{
	m_totalTime = 0;

	vector<CCF_String> names = OBSTACLES_FRAME_NAMES;
	auto sheet = CCF_SpriteSheet::Create(OBSTACLES_SPRITE_FILE_NAME, OBSTACLES_PLIST_FILE_NAME, names, 0, nullptr);

	CCF_Sprite::Init(sheet, OBSTACLES_FRAME_NAMES_LONG_OBSTACLE, 0, CCF_ANCHOR_CENTER, parent);
	CreateRectangleBody(LONG_OBSTACLE_BODY_WIDTH, LONG_OBSTACLE_BODY_HEIGHT, false, nullptr, -1, GAME_OBJECT_TAG_OBSTACLE);

	return true;
}

void LongObstacle::update(float dt)
{
	m_totalTime += dt;

	auto t = sinf(m_totalTime * m_moveFrequency) * m_moveIntensity;

	auto pos = getPosition();
	pos.x = m_oriPos.x + t;
	setPosition(pos);
}

void LongObstacle::OnAddObject()
{
	m_oriPos = getPosition();

	m_moveIntensity = RandomHelper::random_real(LONG_OBSTACLE_MIN_MOVE_INTENSITY, LONG_OBSTACLE_MAX_MOVE_INTENSITY);
	m_moveFrequency = RandomHelper::random_real(LONG_OBSTACLE_MIN_MOVE_FREQUENCY, LONG_OBSTACLE_MAX_MOVE_FREQUENCY);
}