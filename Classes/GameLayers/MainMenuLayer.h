
#ifndef __MAIN_MENU_LAYER_H__
#define __MAIN_MENU_LAYER_H__

#include "CCF_Utils.h"

namespace SlashSave
{
#define MAIN_MENU_TEXT_FONT_NAME "fonts/Marker Felt.ttf"
#define MAIN_MENU_TEXT_SIZE 30
#define MAIN_MENU_TEXT_COLOR CCF_Color(255, 215, 0)

	class MainMenuLayer : public cocos2d::LayerColor
	{
	public:
		CREATE_FUNC(MainMenuLayer)

		virtual bool init();

		void OnPlayClicked(cocos2d::Ref* sender);

	private:
		void InitGUIWidgets();
	};
}

#endif