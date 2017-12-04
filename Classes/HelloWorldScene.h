
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "CCF_OrthoCamera.h"

namespace SlashSave
{

#define IS_DEBUG_PHYSICS 0

	class HelloWorld : public cocos2d::Scene
	{
	private:
		enum
		{
			GAME_LAYER_MAIN_MENU,
			GAME_LAYER_GAMEPLAY,
			GAME_LAYER_HUD,
			GAME_LAYER_GAME_END,
			NUM_GAME_LAYERS
		};

		enum
		{
			CAMERA_GAMEPLAY,
			CAMERA_GUI,
			NUM_CAMERAS
		};

	public:
		static HelloWorld* GetInstance();

		HelloWorld();
		static cocos2d::Scene* createScene();
		static HelloWorld* CreateWithPhysics();

		virtual bool init();
		virtual void update(float dt);

		void PlayGame();
		void EndGame();

	private:
		void InitGameObjects();
		void InitGameLayers();

	private:
		static HelloWorld* s_instance;

		cocos2d::Layer* m_gameLayers[NUM_GAME_LAYERS];
		CCF_OrthoCamera* m_cameras[NUM_CAMERAS];
	};

}

#endif // __HELLOWORLD_SCENE_H__
