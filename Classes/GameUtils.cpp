
#include "GameUtils.h"
#include "CameraGameplay.h"

using namespace cocos2d;
using namespace SlashSave;

bool SlashSave::IsInScreen(const CCF_Vec2& worldCoord)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto screenCoord = CameraGameplay::GetInstance()->WorldToScreenCoordinate(worldCoord);
	auto screenRect = Rect(0, 0, visibleSize.width, visibleSize.height);

	return screenRect.containsPoint(screenCoord);
}