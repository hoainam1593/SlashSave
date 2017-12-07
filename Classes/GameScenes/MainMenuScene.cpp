
#include "MainMenuScene.h"
#include "GameplayScene.h"
#include "CCF_SpriteSheet.h"

using namespace cocos2d;
using namespace SlashSave;
using namespace std;

#pragma region Constants

#define MAIN_MENU_BACKGROUND_IMAGE "sprites/gui/bgMain0.jpg"
#define MAIN_MENU_FLARE_IMAGE "sprites/gui/flare.png"
#define MAIN_MENU_BUTTONS_SPRITE_SHEET "sprites/gui/uiButs.png"
#define MAIN_MENU_BUTTONS_PLIST_FILE "sprites/gui/uiButs.plist"
#define MAIN_MENU_HEX_BALLS_SPRITE_SHEET "sprites/gui/gameElements.png"
#define MAIN_MENU_HEX_BALLS_PLIST_FILE "sprites/gui/gameElements.plist"

#define MAIN_MENU_BACKGROUND_Z_ORDER 0
#define MAIN_MENU_HEX_BALLS_Z_ORDER 1
#define MAIN_MENU_FLARE_Z_ORDER 2
#define MAIN_MENU_BUTTONS_Z_ORDER 3

#define MAIN_MENU_FLARE_ROT_SPEEDS {10, -30, 40}
#define MAIN_MENU_BUTTON_SCALE_INTENSITY 0.02f
#define MAIN_MENU_BUTTON_SCALE_FREQUENCY 8.0f

#define MAIN_MENU_HEX_BALL_MIN_DROP_SPEED 80.0f
#define MAIN_MENU_HEX_BALL_MAX_DROP_SPEED 150.0f
#define MAIN_MENU_HEX_BALL_MIN_ROT_SPEED 20.0f
#define MAIN_MENU_HEX_BALL_MAX_ROT_SPEED 40.0f
#define MAIN_MENU_HEX_BALL_MIN_SCALE 0.5f
#define MAIN_MENU_HEX_BALL_MAX_SCALE 0.8f

#define MAIN_MENU_FRAME_NAME_GAME_ICON "game icon"
#define MAIN_MENU_FRAME_NAME_REFRESH_BUTTON "refresh button"
#define MAIN_MENU_FRAME_NAME_MUTE_BUTTON "mute button"
#define MAIN_MENU_FRAME_NAME_SOUND_BUTTON "sound button"
#define MAIN_MENU_FRAME_NAME_BACK_BUTTON "back button"
#define MAIN_MENU_FRAME_NAME_INFO_BUTTON "info button"
#define MAIN_MENU_FRAME_NAME_PLAY_1_BUTTON "play button 1"
#define MAIN_MENU_FRAME_NAME_PLAY_2_BUTTON "play button 2"
#define MAIN_MENU_FRAME_NAME_PLAY_3_BUTTON "play button 3"
#define MAIN_MENU_FRAME_NAME_EXIT_BUTTON "exit button"
#define MAIN_MENU_FRAME_NAME_PAUSE_BUTTON "pause button"
#define MAIN_MENU_FRAME_NAME_EXCHANGE_BUTTON "exchange button"

#define MAIN_MENU_BUTTONS_FRAME_NAMES \
{ \
	MAIN_MENU_FRAME_NAME_GAME_ICON, \
	MAIN_MENU_FRAME_NAME_REFRESH_BUTTON, \
	MAIN_MENU_FRAME_NAME_MUTE_BUTTON, \
	MAIN_MENU_FRAME_NAME_SOUND_BUTTON, \
	MAIN_MENU_FRAME_NAME_BACK_BUTTON, \
	MAIN_MENU_FRAME_NAME_INFO_BUTTON, \
	MAIN_MENU_FRAME_NAME_PLAY_1_BUTTON, \
	MAIN_MENU_FRAME_NAME_PLAY_2_BUTTON, \
	MAIN_MENU_FRAME_NAME_PLAY_3_BUTTON, \
	MAIN_MENU_FRAME_NAME_EXIT_BUTTON, \
	MAIN_MENU_FRAME_NAME_PAUSE_BUTTON, \
	MAIN_MENU_FRAME_NAME_EXCHANGE_BUTTON \
}

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

#pragma region Button item

class ButtonItem : public MenuItemSprite
{
public:
	CREATE_FUNC(ButtonItem)
	static ButtonItem* Create(CCF_Sprite* sprite, const ccMenuCallback& callback)
	{
		auto pRet = ButtonItem::create();

		pRet->initWithNormalSprite(sprite, sprite, sprite, callback);

		return pRet;
	}

	bool init()
	{
		m_totalTime = 0;
		m_originalScale = CCF_Vec2(getScaleX(), getScaleY());

		this->scheduleUpdate();

		return MenuItemSprite::init();
	}

	void update(float dt)
	{
		m_totalTime += dt;

		auto t = sinf(m_totalTime * MAIN_MENU_BUTTON_SCALE_FREQUENCY) * MAIN_MENU_BUTTON_SCALE_INTENSITY;

		auto scale = m_originalScale.x + t;
		setScaleX(scale);

		scale = m_originalScale.y - t;
		setScaleY(scale);
	}

private:
	float m_totalTime;
	CCF_Vec2 m_originalScale;
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
	auto visibleSize = Director::getInstance()->getVisibleSize();

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

		for (int i = 1; i < speeds.size(); i++)
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

		auto spriteSheet = CCF_SpriteSheet::Create(MAIN_MENU_BUTTONS_SPRITE_SHEET, MAIN_MENU_BUTTONS_PLIST_FILE, frameNames, 0, nullptr);
		auto menu = Menu::create();

		// Play button.
		{
			auto sprite = spriteSheet->CloneFrame(MAIN_MENU_FRAME_NAME_PLAY_1_BUTTON, 0, false);
			auto item = ButtonItem::Create(sprite, CC_CALLBACK_1(MainMenuScene::OnPlayClicked, this));

			menu->addChild(item);
		}

		menu->setPosition(CCF_Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
		this->addChild(menu, MAIN_MENU_BUTTONS_Z_ORDER);
	}
}