
#include "MainMenuScene.h"
#include "GameplayScene.h"
#include "CCF_SpriteSheet.h"
#include "BubbleButton.h"

using namespace cocos2d;
using namespace SlashSave;
using namespace std;

#pragma region Constants

#define MAIN_MENU_BACKGROUND_IMAGE "sprites/gui/bgMain0.jpg"
#define MAIN_MENU_FLARE_IMAGE "sprites/gui/flare.png"
#define MAIN_MENU_HEX_BALLS_SPRITE_SHEET "sprites/gui/gameElements.png"
#define MAIN_MENU_HEX_BALLS_PLIST_FILE "sprites/gui/gameElements.plist"

#define MAIN_MENU_BACKGROUND_Z_ORDER 0
#define MAIN_MENU_HEX_BALLS_Z_ORDER 1
#define MAIN_MENU_FLARE_Z_ORDER 2
#define MAIN_MENU_BUTTONS_Z_ORDER 3

#define MAIN_MENU_FLARE_ROT_SPEEDS {10, -30, 40}

#define MAIN_MENU_HEX_BALL_MIN_DROP_SPEED 80.0f
#define MAIN_MENU_HEX_BALL_MAX_DROP_SPEED 150.0f
#define MAIN_MENU_HEX_BALL_MIN_ROT_SPEED 20.0f
#define MAIN_MENU_HEX_BALL_MAX_ROT_SPEED 40.0f
#define MAIN_MENU_HEX_BALL_MIN_SCALE 0.5f
#define MAIN_MENU_HEX_BALL_MAX_SCALE 0.8f

#define MAIN_MENU_HEX_BALLS_FRAME_NAMES \
{ \
	"vividRed", \
	"vividPink", \
	"vividViolet1", \
	"vividViolet2", \
	"vividOrange", \
	"vividBlue", \
	"vividGreen" \
}

#pragma endregion

#pragma region Flare class

class Flare : public CCF_Sprite
{
public:
	CCF_CREATE_FUNC(Flare)
	CCF_GAME_OBJECT_CREATE_FUNC(Flare)

	bool Init(cocos2d::Node* parent)
	{
		CCF_Sprite::Init(MAIN_MENU_FLARE_IMAGE, MAIN_MENU_FLARE_Z_ORDER, CCF_ANCHOR_CENTER, parent);

		return true;
	}

	void update(float dt)
	{
		auto rot = this->getRotation();
		rot += m_rotSpeed * dt;
		this->setRotation(rot);
	}

	cocos2d::Node* Clone()
	{
		auto other = Flare::Create();

		CopyTo(other);

		return other;
	}

	void SetRotSpeed(float speed)
	{
		m_rotSpeed = speed;
	}

private:
	float m_rotSpeed;
};

#pragma endregion

#pragma region Hex ball

class HexBall : public CCF_Sprite
{
public:
	CREATE_FUNC(HexBall)
	static HexBall* Create(CCF_SpriteSheet* sheet, const CCF_String& frameName, cocos2d::Node* parent)
	{
		auto pRet = HexBall::create();

		pRet->Init(sheet, frameName, MAIN_MENU_HEX_BALLS_Z_ORDER, CCF_ANCHOR_CENTER, parent);
		pRet->Reset();

		return pRet;
	}

	void update(float dt)
	{
		auto y = getPositionY();
		y -= m_dropSpeed * dt;
		setPositionY(y);

		auto rot = getRotation();
		rot -= m_rotSpeed * dt;
		setRotation(rot);

		if (y < 0)
		{
			Reset();
		}
	}

	void Reset()
	{
		auto visibleSize = Director::getInstance()->getVisibleSize();

		auto pos = CCF_Vec2(RandomHelper::random_real(0.0f, visibleSize.width), 0);
		SetPosition(pos, CCF_ANCHOR_LEFT_TOP);

		m_dropSpeed = RandomHelper::random_real(MAIN_MENU_HEX_BALL_MIN_DROP_SPEED, MAIN_MENU_HEX_BALL_MAX_DROP_SPEED);
		m_rotSpeed = RandomHelper::random_real(MAIN_MENU_HEX_BALL_MIN_ROT_SPEED, MAIN_MENU_HEX_BALL_MAX_ROT_SPEED);

		auto scale= RandomHelper::random_real(MAIN_MENU_HEX_BALL_MIN_SCALE, MAIN_MENU_HEX_BALL_MAX_SCALE);
		setScale(scale);
	}

private:
	float m_dropSpeed;
	float m_rotSpeed;
};

#pragma endregion

bool MainMenuScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	this->scheduleUpdate();

	InitGUIWidgets();

	return true;
}

void MainMenuScene::update(float dt)
{
	
}

void MainMenuScene::OnPlayClicked(cocos2d::Ref* sender)
{
	auto director = Director::getInstance();

	director->replaceScene(GameplayScene::CreateWithPhysics());
}

void MainMenuScene::InitGUIWidgets()
{
	// Background.
	{
		auto sprite = CCF_Sprite::Create(MAIN_MENU_BACKGROUND_IMAGE, MAIN_MENU_BACKGROUND_Z_ORDER, CCF_ANCHOR_CENTER, this);
		sprite->SetPosition(CCF_Vec2(0, 0), CCF_ANCHOR_CENTER);
	}
	
	// Flare.
	{
		vector<float> speeds = MAIN_MENU_FLARE_ROT_SPEEDS;

		auto flare = Flare::Create(this);
		flare->SetRotSpeed(speeds[0]);
		flare->SetPosition(CCF_Vec2(0, 0), CCF_ANCHOR_CENTER);

		for (size_t i = 1; i < speeds.size(); i++)
		{
			auto clone = (Flare*)flare->Clone();
			clone->SetRotSpeed(speeds[i]);
		}
	}

	// Dropping balls.
	{
		vector<CCF_String> frameNames = MAIN_MENU_HEX_BALLS_FRAME_NAMES;
		auto spriteSheet = CCF_SpriteSheet::Create(MAIN_MENU_HEX_BALLS_SPRITE_SHEET, MAIN_MENU_HEX_BALLS_PLIST_FILE, frameNames, MAIN_MENU_HEX_BALLS_Z_ORDER, this);

		for each (auto name in frameNames)
		{
			HexBall::Create(spriteSheet, name, spriteSheet);
		}
	}
	
	// Buttons.
	{
		vector<CCF_String> frameNames = MAIN_MENU_BUTTONS_FRAME_NAMES;
		CCF_SpriteSheet* sheet = CCF_SpriteSheet::Create(MAIN_MENU_BUTTONS_SPRITE_SHEET, MAIN_MENU_BUTTONS_PLIST_FILE, frameNames, 0, nullptr);
		auto sprite = CCF_Sprite::Create(sheet, MAIN_MENU_FRAME_NAME_PLAY_1_BUTTON, 0, CCF_ANCHOR_CENTER, nullptr);
		auto button = BubbleButton::Create(sprite, CC_CALLBACK_1(MainMenuScene::OnPlayClicked, this), MAIN_MENU_BUTTONS_Z_ORDER, this);

		button->SetPosition(CCF_Vec2(0, 0), CCF_ANCHOR_CENTER);
	}
}