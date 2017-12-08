
#include "BackgroundTilePool.h"
#include "GameUtils.h"
#include "CameraGameplay.h"

using namespace cocos2d;
using namespace SlashSave;

bool BackgroundTilePool::Init(cocos2d::Node* parent)
{
	if (!CCF_ObjectPool<BackgroundTile>::Init(GAMEPLAY_LOCAL_Z_BACKGROUND, parent, BACKGROUND_TILE_POOL_SIZE))
	{
		return false;
	}

	m_tileSz = m_objects[0]->getBoundingBox().size;
	
	InitTiles();

	return true;
}

void BackgroundTilePool::InitTiles()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto pos = CCF_Vec2(visibleSize.width / 2, visibleSize.height - m_tileSz.height / 2);
	m_poolPos = pos;
	m_poolPos.y -= m_tileSz.height / 2;

	for each (auto obj in m_objects)
	{
		obj->setPosition(pos);
		obj->setVisible(true);

		pos.y -= m_tileSz.height;
	}
}

void BackgroundTilePool::update(float dt)
{
	if (!IsInScreen(m_poolPos))
	{
		AddObject();
		m_poolPos.y -= m_tileSz.height;
	}
}

void BackgroundTilePool::DoAddObject(BackgroundTile* obj)
{
	// Calculate position.
	auto pos = m_poolPos;
	pos.y -= (BACKGROUND_TILE_POOL_SIZE - 1) * m_tileSz.height + m_tileSz.height / 2;

	// Config sprite.
	obj->setPosition(pos);
}