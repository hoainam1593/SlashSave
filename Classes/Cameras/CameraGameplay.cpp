
#include "CameraGameplay.h"

using namespace SlashSave;

CameraGameplay* CameraGameplay::s_instance = nullptr;

CameraGameplay* CameraGameplay::GetInstance()
{
	return s_instance;
}

CameraGameplay::CameraGameplay()
{
	s_instance = this;
}

bool CameraGameplay::Init(cocos2d::Node* parent)
{
	m_oriPos = getPosition();

	setCameraFlag(CAMERA_GAMEPLAY_FLAG);

	return CCF_OrthoCamera::Init(parent);
}

void CameraGameplay::update(float dt)
{
	CCF_OrthoCamera::update(dt);

	this->Move(CCF_Vec2(0, -dt * CAMERA_GAMEPLAY_MOVE_SPEED));
}

CCF_Vec2 CameraGameplay::ScreenToWorldCoordinate(const CCF_Vec2& screenCoord)
{
	auto camPos = getPosition();
	auto camDir = camPos - m_oriPos;

	return (screenCoord + camDir);
}

CCF_Vec2 CameraGameplay::WorldToScreenCoordinate(const CCF_Vec2& worldCoord)
{
	auto camPos = getPosition();
	auto camDir = camPos - m_oriPos;

	return (worldCoord - camDir);
}