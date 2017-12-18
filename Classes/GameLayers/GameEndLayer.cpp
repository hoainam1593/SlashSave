
#include "GameEndLayer.h"
#include "CameraGUI.h"
#include "CCF_SpriteSheet.h"
#include "HUDLayer.h"
#include "Player.h"
#include "BubbleButton.h"
#include "MainMenuScene.h"
#include "GameplayScene.h"

using namespace cocos2d;
using namespace SlashSave;
using namespace std;

#define GAME_END_BACKGROUND_COLOR CCF_ColorA(0, 0, 0, 200)
#define GAME_END_BACKGROUND_SPRITE_FILE_NAME "sprites/gui/popup_backgr.png"

#define GAME_END_TITLE_TEXT_SIZE 30
#define GAME_END_NORMAL_TEXT_SIZE 18
#define GAME_END_TEXT_COLOR CCF_Color(200, 0, 0)
#define GAME_END_TEXT_FONT_NAME "fonts/Marker Felt.ttf"

#define GAME_END_Z_ORDER_BACKGROUND 0
#define GAME_END_Z_ORDER_FOREROUND 1

bool GameEndLayer::init()
{
	m_isSetValue = false;
	InitGUIWidgets();

	this->setCameraMask((unsigned short)CAMERA_GUI_FLAG, true);

	return LayerColor::initWithColor(GAME_END_BACKGROUND_COLOR);
}

void GameEndLayer::InitGUIWidgets()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	{
		// Background image.
		auto sprite = CCF_Sprite::Create(GAME_END_BACKGROUND_SPRITE_FILE_NAME, GAME_END_Z_ORDER_BACKGROUND, CCF_ANCHOR_CENTER, this);
		sprite->SetPosition(CCF_Vec2(0, 0), CCF_ANCHOR_CENTER);
		auto sz = sprite->getContentSize();

		sprite->setScale(visibleSize.width / sz.width);
	}

	// Title label.
	auto titleLabel = CCF_Label::Create("End Game", GAME_END_TEXT_FONT_NAME, GAME_END_TITLE_TEXT_SIZE, GAME_END_TEXT_COLOR, CCF_ANCHOR_CENTER, GAME_END_Z_ORDER_FOREROUND, this);
	titleLabel->SetPosition(CCF_Vec2(0, 100), CCF_ANCHOR_CENTER);

	// Distance label.
	m_labels[LABEL_DISTANCE] = (CCF_Label*)titleLabel->Clone(GAME_END_NORMAL_TEXT_SIZE);
	m_labels[LABEL_DISTANCE]->SetPosition(CCF_Vec2(0, 20), CCF_ANCHOR_CENTER);

	// Coins label.
	m_labels[LABEL_COINS] = (CCF_Label*)m_labels[LABEL_DISTANCE]->Clone();
	m_labels[LABEL_COINS]->SetPosition(CCF_Vec2(0, -30), CCF_ANCHOR_CENTER);

	{
		vector<CCF_String> names = HUD_FRAME_NAMES;
		auto sheet = CCF_SpriteSheet::Create(HUD_SPRITE_FILE_NAME, HUD_PLIST_FILE_NAME, names, 0, nullptr);

		// Distance icon.
		{
			auto sprite = CCF_Sprite::Create(sheet, HUD_FRAME_NAME_DIST_ICON, GAME_END_Z_ORDER_FOREROUND, CCF_ANCHOR_CENTER, this);
			sprite->SetPosition(CCF_Vec2(-30, 20), CCF_ANCHOR_CENTER);
		}

		// Coins icon.
		{
			auto sprite = CCF_Sprite::Create(sheet, HUD_FRAME_NAME_COINS_ICON, GAME_END_Z_ORDER_FOREROUND, CCF_ANCHOR_CENTER, this);
			sprite->SetPosition(CCF_Vec2(-30, -30), CCF_ANCHOR_CENTER);
		}
	}
	
	{
		vector<CCF_String> frameNames = MAIN_MENU_BUTTONS_FRAME_NAMES;
		auto sheet = CCF_SpriteSheet::Create(MAIN_MENU_BUTTONS_SPRITE_SHEET, MAIN_MENU_BUTTONS_PLIST_FILE, frameNames, 0, nullptr);

		{
			// Restart button.
			auto sprite = CCF_Sprite::Create(sheet, MAIN_MENU_FRAME_NAME_PLAY_3_BUTTON, 0, CCF_ANCHOR_CENTER, nullptr);
			auto button = BubbleButton::Create(sprite, CC_CALLBACK_1(GameEndLayer::OnRestartClicked, this), GAME_END_Z_ORDER_FOREROUND, this);

			button->SetPosition(CCF_Vec2(-80, -150), CCF_ANCHOR_CENTER);
		}

		{
			// Main menu button.
			auto sprite = CCF_Sprite::Create(sheet, MAIN_MENU_FRAME_NAME_EXIT_BUTTON, 0, CCF_ANCHOR_CENTER, nullptr);
			auto button = BubbleButton::Create(sprite, CC_CALLBACK_1(GameEndLayer::OnMainMenuClicked, this), GAME_END_Z_ORDER_FOREROUND, this);

			button->SetPosition(CCF_Vec2(80, -150), CCF_ANCHOR_CENTER);
		}
	}
}

void GameEndLayer::setVisible(bool visible)
{
	LayerColor::setVisible(visible);

	if (visible && !m_isSetValue)
	{
		m_labels[LABEL_DISTANCE]->SetFloatText(Player::GetInstance()->GetTravelledDistance(), 3);
		m_labels[LABEL_COINS]->SetIntText(Player::GetInstance()->GetCoins());

		m_isSetValue = true;
	}
}

void GameEndLayer::OnRestartClicked(cocos2d::Ref* sender)
{
	auto director = Director::getInstance();

	director->replaceScene(GameplayScene::CreateWithPhysics());
}

void GameEndLayer::OnMainMenuClicked(cocos2d::Ref* sender)
{
	auto director = Director::getInstance();

	director->replaceScene(MainMenuScene::create());
}