
#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "CCF_Utils.h"

namespace SlashSave
{

#define MAIN_MENU_BUTTONS_SPRITE_SHEET "sprites/gui/uiButs.png"
#define MAIN_MENU_BUTTONS_PLIST_FILE "sprites/gui/uiButs.plist"

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

	class MainMenuScene : public cocos2d::Scene
	{
	public:
		CREATE_FUNC(MainMenuScene)

		virtual bool init();
		virtual void update(float dt);

		void OnPlayClicked(cocos2d::Ref* sender);

	private:
		void InitGUIWidgets();

	};

}

#endif
