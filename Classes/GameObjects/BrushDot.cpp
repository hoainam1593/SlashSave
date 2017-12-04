
#include "BrushDot.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;

bool BrushDot::Init(cocos2d::Node* parent)
{
	CCF_Sprite::Init(BRUSH_DOT_SPRITE_FILE_NAME, 0, CCF_ANCHOR_CENTER, parent);
	CreateCircleBody(BRUSH_DOT_BODY_RADIUS, false, nullptr, -1, GAME_OBJECT_TAG_BRUSH_DOT);

	return true;
}

cocos2d::Node* BrushDot::Clone()
{
	auto other = BrushDot::Create();

	CopyTo(other);

	return other;
}