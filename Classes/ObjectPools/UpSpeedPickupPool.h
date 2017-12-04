
#ifndef __UP_SPEED_PICKUP_POOL_H__
#define __UP_SPEED_PICKUP_POOL_H__

#include "CCF_ObjectPool.h"
#include "UpSpeedPickup.h"

namespace SlashSave
{

#define UP_SPEED_PICKUP_SPAWNING_RATE 2
#define UP_SPEED_PICKUP_POOL_SIZE 5

	class UpSpeedPickupPool : public CCF_ObjectPool<UpSpeedPickup>
	{
	public:
		CCF_GAME_OBJECT_CREATE_FUNC(UpSpeedPickupPool)

		bool Init(cocos2d::Node* parent);

		void DoAddObject(UpSpeedPickup* obj);

	private:
		void AddAPickup(float dt);

	};

}

#endif