
#ifndef __CAMERA_GAMEPLAY_H__
#define __CAMERA_GAMEPLAY_H__

#include "CCF_OrthoCamera.h"

namespace SlashSave
{

#define CAMERA_GAMEPLAY_FLAG cocos2d::CameraFlag::USER1
#define CAMERA_GAMEPLAY_MOVE_SPEED 80

	class CameraGameplay : public CCF_OrthoCamera
	{
	public:
		static CameraGameplay* GetInstance();

		CameraGameplay();

		CCF_GAME_OBJECT_CREATE_FUNC(CameraGameplay)

		bool Init(cocos2d::Node* parent);
		void update(float dt);

		CCF_Vec2 ScreenToWorldCoordinate(const CCF_Vec2& screenCoord);
		CCF_Vec2 WorldToScreenCoordinate(const CCF_Vec2& worldCoord);

	private:
		CCF_Vec2 m_oriPos;

		static CameraGameplay* s_instance;
	};
}

#endif