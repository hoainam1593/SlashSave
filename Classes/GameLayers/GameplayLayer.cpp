
#include "GameplayLayer.h"

#include "Player.h"
#include "Brush.h"
#include "BackgroundTilePool.h"
#include "UpSpeedPickupPool.h"
#include "CoinPickupPool.h"
#include "ObstaclePool.h"

#include "CameraGameplay.h"

using namespace cocos2d;
using namespace SlashSave;

bool GameplayLayer::init()
{
	InitGameObjects();

	this->setCameraMask((unsigned short)CAMERA_GAMEPLAY_FLAG, true);

	return Layer::init();
}

void GameplayLayer::InitGameObjects()
{
	m_gameObjs.push_back(Player::Create(this));
	m_gameObjs.push_back(Brush::Create(this));
	m_gameObjs.push_back(BackgroundTilePool::Create(this));
	m_gameObjs.push_back(ObstaclePool::Create(this));
	m_gameObjs.push_back(UpSpeedPickupPool::Create(this));
	m_gameObjs.push_back(CoinPickupPool::Create(this));
}