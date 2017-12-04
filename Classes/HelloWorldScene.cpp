
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "GameplayLayer.h"
#include "HUDLayer.h"
#include "GameEndLayer.h"
#include "MainMenuLayer.h"

#include "CameraGUI.h"
#include "CameraGameplay.h"

USING_NS_CC;
using namespace std;
using namespace SlashSave;

HelloWorld* HelloWorld::s_instance = nullptr;

HelloWorld* HelloWorld::GetInstance()
{
	return s_instance;
}

Scene* HelloWorld::createScene()
{
	return HelloWorld::CreateWithPhysics();
}

HelloWorld* HelloWorld::CreateWithPhysics()
{
	HelloWorld *pRet = new(std::nothrow) HelloWorld();

	if (pRet && pRet->initWithPhysics() && pRet->init())
	{
		if (IS_DEBUG_PHYSICS)
		{
			pRet->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
		}
		
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

HelloWorld::HelloWorld()
{
	s_instance = this;
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	this->scheduleUpdate();

	InitGameObjects();
	InitGameLayers();
	
    return true;
}

void HelloWorld::update(float dt)
{
	// Debug physics drawing uses scene's default camera instead of gameplay camera.
	// So we need to ensure that two cameras have the same position.
	auto camera = getDefaultCamera();
	auto pos = camera->getPosition();
	pos.y -= dt * CAMERA_GAMEPLAY_MOVE_SPEED;
	camera->setPosition(pos);
}

void HelloWorld::InitGameObjects()
{
	m_cameras[CAMERA_GAMEPLAY] = CameraGameplay::Create(this);
	m_cameras[CAMERA_GUI] = CameraGUI::Create(this);
}

void HelloWorld::InitGameLayers()
{
	m_gameLayers[GAME_LAYER_MAIN_MENU] = MainMenuLayer::create();
	m_gameLayers[GAME_LAYER_GAMEPLAY] = GameplayLayer::create();
	m_gameLayers[GAME_LAYER_HUD] = HUDLayer::create();
	m_gameLayers[GAME_LAYER_GAME_END] = GameEndLayer::create();
	
	for (int i = 0; i < NUM_GAME_LAYERS; i++)
	{
		addChild(m_gameLayers[i], i);

		m_gameLayers[i]->setVisible(false);
	}

	m_gameLayers[GAME_LAYER_MAIN_MENU]->setVisible(true);
}

void HelloWorld::PlayGame()
{
	m_gameLayers[GAME_LAYER_MAIN_MENU]->setVisible(false);
	m_gameLayers[GAME_LAYER_GAMEPLAY]->setVisible(true);
	m_gameLayers[GAME_LAYER_HUD]->setVisible(true);
}

void HelloWorld::EndGame()
{
	m_gameLayers[GAME_LAYER_GAME_END]->setVisible(true);
}