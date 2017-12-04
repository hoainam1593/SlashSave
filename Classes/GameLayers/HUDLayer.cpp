
#include "HUDLayer.h"
#include "CameraGUI.h"
#include "Player.h"

using namespace cocos2d;
using namespace SlashSave;

bool HUDLayer::init()
{
	InitGUIWidgets();

	this->setCameraMask((unsigned short)CAMERA_GUI_FLAG, true);
	this->schedule(schedule_selector(HUDLayer::updateText), HUD_UPDATE_TEXT_FREQUENCY);

	return LayerColor::init();
}

void HUDLayer::InitGUIWidgets()
{
	{
		// Coins label.
		m_labels[LABEL_COINS] = CCF_Label::Create("100", HUD_TEXT_FONT_NAME, HUD_TEXT_SIZE, HUD_TEXT_COLOR, CCF_ANCHOR_LEFT_TOP, 0, this);
		m_labels[LABEL_COINS]->SetPosition(CCF_Vec2(HUD_SCREEN_PADDING, -HUD_SCREEN_PADDING), CCF_ANCHOR_LEFT_TOP);
	}

	{
		// Distance label.
		m_labels[LABEL_DISTANCE] = CCF_Label::Create("100", HUD_TEXT_FONT_NAME, HUD_TEXT_SIZE, HUD_TEXT_COLOR, CCF_ANCHOR_RIGHT_TOP, 0, this);
		m_labels[LABEL_DISTANCE]->SetPosition(CCF_Vec2(-HUD_SCREEN_PADDING, -HUD_SCREEN_PADDING), CCF_ANCHOR_RIGHT_TOP);
	}
}

void HUDLayer::updateText(float dt)
{
	m_labels[LABEL_COINS]->SetIntText(Player::GetInstance()->GetCoins());
	m_labels[LABEL_DISTANCE]->SetFloatText(Player::GetInstance()->GetTravelledDistance(), 3);
}