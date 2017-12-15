
#include "HUDLayer.h"
#include "CameraGUI.h"
#include "Player.h"
#include "CCF_SpriteSheet.h"

using namespace cocos2d;
using namespace SlashSave;
using namespace std;

#define HUD_TEXT_SIZE 20
#define HUD_TEXT_COLOR CCF_Color(255, 215, 0)
#define HUD_TEXT_FONT_NAME "fonts/Marker Felt.ttf"
#define HUD_UPDATE_TEXT_FREQUENCY 0.5f

#define HUD_SPRITE_FILE_NAME "sprites/gui/hud.png"
#define HUD_PLIST_FILE_NAME "sprites/gui/hud.plist"
#define HUD_FRAME_NAME_EMPTY "empty.png"
#define HUD_FRAME_NAME_COINS_ICON "coins.png"
#define HUD_FRAME_NAME_DIST_ICON "dist.png"
#define HUD_FRAME_NAMES {HUD_FRAME_NAME_EMPTY, HUD_FRAME_NAME_COINS_ICON, HUD_FRAME_NAME_DIST_ICON}

#define HUD_BACKGROUND_Z_ORDER 0
#define HUD_FOREGROUND_Z_ORDER 1

#define HUD_EMPTY_SIZE CCF_Size(100, 45)
#define HUD_EMPTY_MARGIN 14
#define HUD_ICON_MARGIN 10

bool HUDLayer::init()
{
	InitGUIWidgets();

	this->setCameraMask((unsigned short)CAMERA_GUI_FLAG, true);
	this->schedule(schedule_selector(HUDLayer::updateText), HUD_UPDATE_TEXT_FREQUENCY);

	return LayerColor::init();
}

void HUDLayer::InitGUIWidgets()
{
	vector<CCF_String> names = HUD_FRAME_NAMES;
	auto sheet = CCF_SpriteSheet::Create(HUD_SPRITE_FILE_NAME, HUD_PLIST_FILE_NAME, names, 0, nullptr);

	{
		// Background
		auto sprite1 = CCF_Sprite::Create(sheet, HUD_FRAME_NAME_EMPTY, HUD_BACKGROUND_Z_ORDER, CCF_ANCHOR_LEFT_TOP, this);
		sprite1->SetPosition(CCF_Vec2(0, -HUD_EMPTY_MARGIN), CCF_ANCHOR_LEFT_TOP);
		sprite1->setContentSize(HUD_EMPTY_SIZE);

		auto sprite2 = (CCF_Sprite*)sprite1->Clone();
		sprite2->setAnchorPoint(CCF_ANCHOR_RIGHT_TOP);
		sprite2->SetPosition(CCF_Vec2(0, -HUD_EMPTY_MARGIN), CCF_ANCHOR_RIGHT_TOP);
	}

	{
		// Coins icon.
		auto sprite = CCF_Sprite::Create(sheet, HUD_FRAME_NAME_COINS_ICON, HUD_FOREGROUND_Z_ORDER, CCF_ANCHOR_LEFT_TOP, this);
		auto sz = sprite->getContentSize();
		auto y = -(HUD_EMPTY_MARGIN + (HUD_EMPTY_SIZE.height - sz.height) / 2);

		sprite->SetPosition(CCF_Vec2(HUD_ICON_MARGIN, y), CCF_ANCHOR_LEFT_TOP);

		{
			// Coins label.
			m_labels[LABEL_COINS] = CCF_Label::Create("100", HUD_TEXT_FONT_NAME, HUD_TEXT_SIZE, HUD_TEXT_COLOR, CCF_ANCHOR_LEFT_TOP, HUD_FOREGROUND_Z_ORDER, this);
			
			auto x = 2 * HUD_ICON_MARGIN + sz.width;
			sz = m_labels[LABEL_COINS]->getContentSize();
			y = -(HUD_EMPTY_MARGIN + (HUD_EMPTY_SIZE.height - sz.height) / 2);

			m_labels[LABEL_COINS]->SetPosition(CCF_Vec2(x, y), CCF_ANCHOR_LEFT_TOP);
		}
	}

	{
		// Distance icon.
		auto sprite = CCF_Sprite::Create(sheet, HUD_FRAME_NAME_DIST_ICON, HUD_FOREGROUND_Z_ORDER, CCF_ANCHOR_RIGHT_TOP, this);
		auto sz = sprite->getContentSize();
		auto y = -(HUD_EMPTY_MARGIN + (HUD_EMPTY_SIZE.height - sz.height) / 2);

		sprite->SetPosition(CCF_Vec2(-HUD_ICON_MARGIN, y), CCF_ANCHOR_RIGHT_TOP);

		{
			// Distance label.
			m_labels[LABEL_DISTANCE] = CCF_Label::Create("100", HUD_TEXT_FONT_NAME, HUD_TEXT_SIZE, HUD_TEXT_COLOR, CCF_ANCHOR_RIGHT_TOP, HUD_FOREGROUND_Z_ORDER, this);

			auto x = 2 * HUD_ICON_MARGIN + sz.width;
			sz = m_labels[LABEL_DISTANCE]->getContentSize();
			y = -(HUD_EMPTY_MARGIN + (HUD_EMPTY_SIZE.height - sz.height) / 2);

			m_labels[LABEL_DISTANCE]->SetPosition(CCF_Vec2(-x, y), CCF_ANCHOR_RIGHT_TOP);
		}
	}
}

void HUDLayer::updateText(float dt)
{
	m_labels[LABEL_COINS]->SetIntText(Player::GetInstance()->GetCoins());
	m_labels[LABEL_DISTANCE]->SetFloatText(Player::GetInstance()->GetTravelledDistance(), 3);
}