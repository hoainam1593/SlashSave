
#ifndef __GAME_END_LAYER_H__
#define __GAME_END_LAYER_H__

#include "CCF_Label.h"

namespace SlashSave
{

	class GameEndLayer : public cocos2d::LayerColor
	{
	private:
		enum
		{
			LABEL_COINS,
			LABEL_DISTANCE,
			NUMBER_LABELS
		};

	public:
		CREATE_FUNC(GameEndLayer)
		virtual bool init();
		virtual void setVisible(bool visible);

		void OnRestartClicked(cocos2d::Ref* sender);
		void OnMainMenuClicked(cocos2d::Ref* sender);

	private:
		void InitGUIWidgets();

	private:
		CCF_Label* m_labels[NUMBER_LABELS];
		bool m_isSetValue;
	};
}

#endif