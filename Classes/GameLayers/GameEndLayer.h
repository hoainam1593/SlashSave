
#ifndef __GAME_END_LAYER_H__
#define __GAME_END_LAYER_H__

#include "CCF_Utils.h"

namespace SlashSave
{

#define GAME_END_POPUP_BACKGROUND_COLOR CCF_ColorA(0, 0, 0, 200)
#define GAME_END_POPUP_TEXT_SIZE 30
#define GAME_END_POPUP_TEXT_COLOR CCF_Color(255, 215, 0)
#define GAME_END_POPUP_TEXT_FONT_NAME "fonts/Marker Felt.ttf"

	class GameEndLayer : public cocos2d::LayerColor
	{
	public:
		CREATE_FUNC(GameEndLayer)
		virtual bool init();

	private:
		void InitGUIWidgets();
	};
}

#endif