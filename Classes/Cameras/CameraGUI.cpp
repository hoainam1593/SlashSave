
#include "CameraGUI.h"

using namespace SlashSave;

bool CameraGUI::Init(cocos2d::Node* parent)
{
	setCameraFlag(CAMERA_GUI_FLAG);

	return CCF_OrthoCamera::Init(parent);
}