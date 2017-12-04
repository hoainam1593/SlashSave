
#include "Brush.h"
#include "CameraGameplay.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;

void Brush::update(float dt)
{
	auto sz = m_brushDots.size();
	for (int i = sz - 1; i >= 0; i--)
	{
		auto dot = m_brushDots[i];
		if (!IsInScreen(dot->getPosition()))
		{
			dot->removeFromParentAndCleanup(true);
			m_brushDots.erase(m_brushDots.begin() + i);
		}
	}
}

void Brush::OnMouseMoveWhileLeftBtnPressed(const CCF_Vec2& mousePos)
{
	auto sz = m_brushDots.size();
	auto dot = ((sz == 0) ? BrushDot::Create(this) : (BrushDot*)m_brushDots[0]->Clone());

	dot->SetPosition(CameraGameplay::GetInstance()->ScreenToWorldCoordinate(mousePos), CCF_ANCHOR_LEFT_BOTTOM);

	m_brushDots.push_back(dot);
}