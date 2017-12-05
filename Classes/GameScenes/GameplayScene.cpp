
#include "GameplayScene.h"
#include "SimpleAudioEngine.h"

#include "GameplayLayer.h"
#include "HUDLayer.h"
#include "GameEndLayer.h"

#include "CameraGUI.h"
#include "CameraGameplay.h"

USING_NS_CC;
using namespace std;
using namespace SlashSave;

GameplayScene* GameplayScene::s_instance = nullptr;

GameplayScene* GameplayScene::GetInstance()
{
	return s_instance;
}

GameplayScene* GameplayScene::CreateWithPhysics()
{
	GameplayScene *pRet = new(std::nothrow) GameplayScene();

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

GameplayScene::GameplayScene()
{
	s_instance = this;
}

bool GameplayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	this->scheduleUpdate();

	InitGameObjects();
	InitGameLayers();

	return true;
}

void GameplayScene::update(float dt)
{
	// Debug physics drawing uses scene's default camera instead of gameplay camera.
	// So we need to ensure that two cameras have the same position.
	auto camera = getDefaultCamera();
	auto pos = camera->getPosition();
	pos.y -= dt * CAMERA_GAMEPLAY_MOVE_SPEED;
	camera->setPosition(pos);
}

void GameplayScene::InitGameObjects()
{
	m_cameras[CAMERA_GAMEPLAY] = CameraGameplay::Create(this);
	m_cameras[CAMERA_GUI] = CameraGUI::Create(this);
}

void GameplayScene::InitGameLayers()
{
	m_gameLayers[GAME_LAYER_GAMEPLAY] = GameplayLayer::create();
	m_gameLayers[GAME_LAYER_HUD] = HUDLayer::create();
	m_gameLayers[GAME_LAYER_GAME_END] = GameEndLayer::create();

	for (int i = 0; i < NUM_GAME_LAYERS; i++)
	{
		addChild(m_gameLayers[i], i);

		m_gameLayers[i]->setVisible(false);
	}

	m_gameLayers[GAME_LAYER_GAMEPLAY]->setVisible(true);
	m_gameLayers[GAME_LAYER_HUD]->setVisible(true);
}

void GameplayScene::EndGame()
{
	m_gameLayers[GAME_LAYER_GAME_END]->setVisible(true);
}