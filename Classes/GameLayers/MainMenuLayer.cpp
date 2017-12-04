
#include "MainMenuLayer.h"
#include "CameraGUI.h"
#include "HelloWorldScene.h"

using namespace cocos2d;
using namespace SlashSave;

bool MainMenuLayer::init()
{
	InitGUIWidgets();

	this->setCameraMask((unsigned short)CAMERA_GUI_FLAG, true);

	return LayerColor::init();
}

void MainMenuLayer::InitGUIWidgets()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	// Play button.
	auto playLabel = Label::createWithTTF("Play", MAIN_MENU_TEXT_FONT_NAME, MAIN_MENU_TEXT_SIZE);
	playLabel->setColor(MAIN_MENU_TEXT_COLOR);

	auto playItem = MenuItemLabel::create(playLabel, CC_CALLBACK_1(MainMenuLayer::OnPlayClicked, this));

	auto menu = Menu::create(playItem, nullptr);
	menu->setPosition(CCF_Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));

	this->addChild(menu, 0);
}

void MainMenuLayer::OnPlayClicked(cocos2d::Ref* sender)
{
	HelloWorld::GetInstance()->PlayGame();
}