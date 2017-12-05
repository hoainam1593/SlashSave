
#include "MainMenuScene.h"
#include "GameplayScene.h"
#include "CCF_SpriteSheet.h"

using namespace cocos2d;
using namespace SlashSave;
using namespace std;

bool MainMenuScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	InitGUIWidgets();

	return true;
}

void MainMenuScene::OnPlayClicked(cocos2d::Ref* sender)
{
	auto director = Director::getInstance();

	director->replaceScene(GameplayScene::CreateWithPhysics());
}

void MainMenuScene::InitGUIWidgets()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	// Play button.
	auto playLabel = Label::createWithTTF("Play", MAIN_MENU_TEXT_FONT_NAME, MAIN_MENU_TEXT_SIZE);
	playLabel->setColor(MAIN_MENU_TEXT_COLOR);

	auto playItem = MenuItemLabel::create(playLabel, CC_CALLBACK_1(MainMenuScene::OnPlayClicked, this));

	auto menu = Menu::create(playItem, nullptr);
	menu->setPosition(CCF_Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));

	this->addChild(menu, 0);
}