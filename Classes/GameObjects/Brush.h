
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

		void update(float dt);
		void OnMouseMoveWhileLeftBtnPressed(const CCF_Vec2& mousePos);

	private:
		std::vector<BrushDot*> m_brushDots;
	};

}

#endif