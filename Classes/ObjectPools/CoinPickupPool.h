
#ifndef __COIN_PICKUP_POOL_H__
#define __COIN_PICKUP_POOL_H__

#include "CCF_ObjectPool.h"
#include "CoinPickup.h"

namespace SlashSave
{

#define COIN_PICKUP_SPAWNING_RATE 2
#define COIN_PICKUP_POOL_SIZE 5

	class CoinPickupPool : public CCF_ObjectPool<CoinPickup>
	{
	public:
		CCF_GAME_OBJECT_CREATE_FUNC(CoinPickupPool)

		bool Init(cocos2d::Node* parent);

		void DoAddObject(CoinPickup* obj);

	private:
		void AddAPickup(float dt);

	};

}

#endif