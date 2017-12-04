
#ifndef __BRUSH_DOT_H__
#define __BRUSH_DOT_H__

#include "CCF_Sprite.h"

namespace SlashSave
{

#define BRUSH_DOT_SPRITE_FILE_NAME "brush.png"
#define BRUSH_DOT_BODY_RADIUS 12

	class BrushDot : public CCF_Sprite
	{
	public:
		CCF_CREATE_FUNC(BrushDot)
		CCF_GAME_OBJECT_CREATE_FUNC(BrushDot)

		bool Init(cocos2d::Node* parent);
		cocos2d::Node* Clone();
	};

}

#endif