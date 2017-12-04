
#ifndef __CAMERA_GUI_H__
#define __CAMERA_GUI_H__

#include "CCF_OrthoCamera.h"

namespace SlashSave
{

#define CAMERA_GUI_FLAG cocos2d::CameraFlag::USER2

	class CameraGUI : public CCF_OrthoCamera
	{
	public:
		CCF_GAME_OBJECT_CREATE_FUNC(CameraGUI)

		bool Init(cocos2d::Node* parent);
	};
}

#endif