
#ifndef __HUD_LAYER_H__
#define __HUD_LAYER_H__

#include "CCF_Label.h"

namespace SlashSave
{

#define HUD_FRAME_NAME_EMPTY "empty.png"
#define HUD_FRAME_NAME_COINS_ICON "coins.png"
#define HUD_FRAME_NAME_DIST_ICON "dist.png"

#define HUD_SPRITE_FILE_NAME "sprites/gui/hud.png"
#define HUD_PLIST_FILE_NAME "sprites/gui/hud.plist"
#define HUD_FRAME_NAMES {HUD_FRAME_NAME_EMPTY, HUD_FRAME_NAME_COINS_ICON, HUD_FRAME_NAME_DIST_ICON}

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