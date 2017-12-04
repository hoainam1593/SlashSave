
#include "GameEndLayer.h"
#include "CameraGUI.h"

using namespace cocos2d;
using namespace SlashSave;

bool GameEndLayer::init()
{
	InitGUIWidgets();

	this->setCameraMask((unsigned short)CAMERA_GUI_FLAG, true);

	return LayerColor::initWithColor(GAME_END_POPUP_BACKGROUND_COLOR);
}

void GameEndLayer::InitGUIWidgets()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	// Label
	auto label = Label::createWithTTF("End Game", GAME_END_POPUP_TEXT_FONT_NAME, GAME_END_POPUP_TEXT_SIZE);
	label->setColor(GAME_END_POPUP_TEXT_COLOR);
	label->setPosition(CCF_Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));

	addChild(label, 0);
}