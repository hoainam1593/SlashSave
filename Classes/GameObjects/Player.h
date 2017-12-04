
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "CCF_Sprite.h"

namespace SlashSave
{

#define PLAYER_SPRITE_FILE_NAME "character.png"
#define PLAYER_BODY_RADIUS 24
#define PLAYER_MAX_MOVE_SPEED 80
#define PLAYER_BOUNCING_AMOUNT 10
#define PLAYER_DISTANCE_MODIFIER 100.0f

	class Player : public CCF_Sprite
	{
	public:
		CCF_GAME_OBJECT_CREATE_FUNC(Player)

		// Core.
		static Player* GetInstance();

		Player();
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
		static Player* s_instance;

		float m_upSpeedTime;
		CCF_Vec2 m_prevPos;
		float m_travelledDist;
		int m_nCoins;
	};

}

#endif