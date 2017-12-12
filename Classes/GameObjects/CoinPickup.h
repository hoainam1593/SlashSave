
#ifndef __COIN_PICKUP_H__
#define __COIN_PICKUP_H__

#include "CCF_SpriteAnim.h"

namespace SlashSave
{

	class CoinPickup : public CCF_SpriteAnim
	{
	public:
		CCF_CREATE_FUNC(CoinPickup)
		CCF_GAME_OBJECT_CREATE_FUNC(CoinPickup)
		CCF_CLONE_FUNC(CoinPickup)

		bool Init(cocos2d::Node* parent);

		bool OnCollideWith(cocos2d::PhysicsBody* other);

	private:
		void OnDestroy();
	};

}

#endif