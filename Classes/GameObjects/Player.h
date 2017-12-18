
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "CCF_Sprite.h"

namespace SlashSave
{

	class Player : public CCF_Sprite
	{
		CCF_GET_INSTANCE_FUNC(Player)

	public:
		CCF_GAME_OBJECT_CREATE_FUNC(Player)

		// Core.
		bool Init(cocos2d::Node* parent);
		void update(float dt);

		// Getter/Setter.
		float GetTravelledDistance();
		int GetCoins();

		// Callback.
		bool OnCollideWith(cocos2d::PhysicsBody* other);

	private:
		void OnEndGame();
		void OnGetUpSpeedPickup();
		void OnGetCoinPickup();

	private:
		float m_upSpeedTime;
		CCF_Vec2 m_prevPos;
		float m_travelledDist;
		int m_nCoins;
		bool m_isEndGame;
	};

}

#endif