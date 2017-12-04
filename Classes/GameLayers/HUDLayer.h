
#ifndef __HUD_LAYER_H__
#define __HUD_LAYER_H__

#include "CCF_Label.h"

namespace SlashSave
{

#define HUD_TEXT_SIZE 20
#define HUD_TEXT_COLOR CCF_Color(255, 215, 0)
#define HUD_TEXT_FONT_NAME "fonts/Marker Felt.ttf"
#define HUD_SCREEN_PADDING 20
#define HUD_UPDATE_TEXT_FREQUENCY 0.5f

	class HUDLayer : public cocos2d::LayerColor
	{
	private:
		enum
		{
			LABEL_COINS,
			LABEL_DISTANCE,
			NUMBER_LABELS
		};

	public:
		CREATE_FUNC(HUDLayer)
			
		virtual bool init();
		void updateText(float dt);

	private:
		void InitGUIWidgets();

	private:
		CCF_Label* m_labels[NUMBER_LABELS];
	};
}

#endif