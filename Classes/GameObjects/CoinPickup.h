
#ifndef __COIN_PICKUP_H__
#define __COIN_PICKUP_H__

#include "CCF_Sprite.h"

namespace SlashSave
{

#define COIN_PICKUP_SPRITE_FILE_NAME "coin.png"
#define COIN_PICKUP_BODY_RADIUS 24

	class CoinPickup : public CCF_Sprite
	{
	public:
		CCF_CREATE_FUNC(CoinPickup)
		CCF_GAME_OBJECT_CREATE_FUNC(CoinPickup)

		bool Init(cocos2d::Node* parent);
		cocos2d::Node* Clone();

		bool OnCollideWith(cocos2d::PhysicsBody* other);

	private:
		void OnDestroy();
	};

}

#endif