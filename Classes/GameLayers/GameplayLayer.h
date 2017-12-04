
#ifndef __GAMEPLAY_LAYER_H__
#define __GAMEPLAY_LAYER_H__

#include "CCF_Utils.h"

namespace SlashSave
{
	class GameplayLayer : public cocos2d::Layer
	{
	public:
		CREATE_FUNC(GameplayLayer)

		virtual bool init();

	private:
		void InitGameObjects();

	private:
		std::vector<cocos2d::Node*> m_gameObjs;
	};
}

#endif