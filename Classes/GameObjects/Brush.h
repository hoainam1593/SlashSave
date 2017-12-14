
#ifndef __BRUSH_H__
#define __BRUSH_H__

#include "CCF_GameObject.h"
#include "BrushDot.h"

namespace SlashSave
{

	class Brush : public CCF_GameObject
	{
	public:
		CCF_GAME_OBJECT_CREATE_FUNC(Brush)

		bool Init(cocos2d::Node* parent);
		void update(float dt);
		void OnMouseDown(cocos2d::Event* evt);
		void OnMouseMoveWhileLeftBtnPressed(const CCF_Vec2& mousePos);

	private:
		void AddADot(CCF_Vec2 mousePos);

	private:
		std::vector<BrushDot*> m_brushDots;
		std::vector<CCF_Vec2> m_mousePositions;
	};

}

#endif