
#include "Player.h"
#include "GameUtils.h"
#include "CameraGameplay.h"
#include "GameplayScene.h"
#include "UpSpeedPickup.h"

using namespace cocos2d;
using namespace SlashSave;

Player* Player::s_instance = nullptr;

static float Interpolate(float t0, float v0, float t1, float v1, float t);
static float Interpolate(float t0, float v0, float t1, float v1, float t2, float v2, float t);

#pragma region Core

Player* Player::GetInstance()
{
	return s_instance;
}

Player::Player()
	: m_upSpeedTime(-1),
	m_travelledDist(0),
	m_nCoins(0)
{
	s_instance = this;
}

bool Player::Init(cocos2d::Node* parent)
{
	auto mat = PhysicsMaterial(0, PLAYER_BOUNCING_AMOUNT, 0);

	CCF_Sprite::Init(PLAYER_SPRITE_FILE_NAME, 0, CCF_ANCHOR_CENTER, parent);

	SetPosition(CCF_Vec2(0, 0), CCF_ANCHOR_CENTER);
	CreateCircleBody(PLAYER_BODY_RADIUS, true, &mat, PLAYER_MAX_MOVE_SPEED, GAME_OBJECT_TAG_PLAYER);

	m_prevPos = getPosition();

	return true;
}

void Player::update(float dt)
{
	CCF_Sprite::update(dt);

	// Check if player within screen.
	if (!IsInScreen(getPosition()))
	{
		OnEndGame();
	}

	// Upspeed pickup.
	if (m_upSpeedTime >= 0)
	{
		m_upSpeedTime += dt;
	}

	if (m_upSpeedTime >= UP_SPEED_PICKUP_EFFECT_TIME)
	{
		m_upSpeedTime = -1;
	}

	if (m_upSpeedTime >= 0)
	{
		float t = Interpolate(
			0, PLAYER_MAX_MOVE_SPEED,
			UP_SPEED_PICKUP_EFFECT_TIME / 2, PLAYER_MAX_MOVE_SPEED + UP_SPEED_PICKUP_INCREASED_SPEED,
			UP_SPEED_PICKUP_EFFECT_TIME, PLAYER_MAX_MOVE_SPEED,
			m_upSpeedTime);
		SetMaxSpeed(t);
	}
	else
	{
		SetMaxSpeed(PLAYER_MAX_MOVE_SPEED);
	}

	// Travelled distance.
	m_travelledDist += abs(m_prevPos.y - getPosition().y);
	m_prevPos = getPosition();
}

#pragma endregion

#pragma region Getter/Setter

float Player::GetTravelledDistance()
{
	return m_travelledDist / PLAYER_DISTANCE_MODIFIER;
}

int Player::GetCoins()
{
	return m_nCoins;
}

#pragma endregion

#pragma region Callback

bool Player::OnCollideWith(cocos2d::PhysicsBody* other)
{
	auto tag = other->getTag();
	auto isCollide = true;

	switch (tag)
	{

	case GAME_OBJECT_TAG_OBSTACLE:
		OnEndGame();
		break;

	case GAME_OBJECT_TAG_UP_SPEED_PICKUP:
	{
		OnGetUpSpeedPickup();
		isCollide = false;
	} break;

	case GAME_OBJECT_TAG_COIN_PICKUP:
	{
		OnGetCoinPickup();
		isCollide = false;
	} break;

	default:
		break;

	}

	return isCollide;
}

void Player::OnEndGame()
{
	GameplayScene::GetInstance()->EndGame();
}

void Player::OnGetUpSpeedPickup()
{
	m_upSpeedTime = 0;
}

void Player::OnGetCoinPickup()
{
	m_nCoins++;
}

#pragma endregion

#pragma region Utilities

static float Interpolate(float t0, float v0, float t1, float v1, float t)
{
	float alpha = (t - t0) / (t1 - t0);
	return MathUtil::lerp(v0, v1, alpha);
}

static float Interpolate(float t0, float v0, float t1, float v1, float t2, float v2, float t)
{
	if (t < t1)
	{
		return Interpolate(t0, v0, t1, v1, t);
	}
	else
	{
		return Interpolate(t1, v1, t2, v2, t);
	}
}

#pragma endregion