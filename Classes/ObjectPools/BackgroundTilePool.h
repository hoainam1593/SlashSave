
#ifndef __BACKGROUND_TILE_POOL_H__
#define __BACKGROUND_TILE_POOL_H__

#include "CCF_ObjectPool.h"
#include "BackgroundTile.h"

namespace SlashSave
{

#define BACKGROUND_TILE_POOL_SIZE 3

	class BackgroundTilePool : public CCF_ObjectPool<BackgroundTile>
	{
	public:
		CCF_GAME_OBJECT_CREATE_FUNC(BackgroundTilePool)

		bool Init(cocos2d::Node* parent);
		void update(float dt);

		void DoAddObject(BackgroundTile* obj);

	private:
		void InitTiles();

	private:
		CCF_Vec2 m_poolPos;
		CCF_Size m_tileSz;
	};

}

#endif