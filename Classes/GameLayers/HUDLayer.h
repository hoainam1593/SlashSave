
#ifndef __HUD_LAYER_H__
#define __HUD_LAYER_H__

#include "CCF_Label.h"

namespace SlashSave
{

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