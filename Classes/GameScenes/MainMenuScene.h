
#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "CCF_Sprite.h"

namespace SlashSave
{

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
