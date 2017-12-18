
#include "Brush.h"
#include "CameraGameplay.h"
#include "GameUtils.h"

using namespace cocos2d;
using namespace SlashSave;

#define BRUSH_DOTS_MIN_DISTANCE 15.0f

bool Brush::Init(cocos2d::Node* parent)
{
	return CCF_GameObject::Init(GAMEPLAY_LOCAL_Z_BRUSHES, parent);
}

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

void Brush::OnMouseDown(cocos2d::Event* evt)
{
	CCF_GameObject::OnMouseDown(evt);

	m_mousePositions.clear();
}

void Brush::OnMouseMoveWhileLeftBtnPressed(const CCF_Vec2& mousePos)
{
	// Add a dot at the beginning
	if (m_mousePositions.empty())
	{
		m_mousePositions.push_back(mousePos);
		AddADot(mousePos);

		return;
	}

	// Add dot as long as the distance between current and previous position is less than a particular limit.
	CCF_Vec2 prevPos = m_mousePositions.back();
	float dist = mousePos.distance(prevPos);
	
	if (dist >= BRUSH_DOTS_MIN_DISTANCE)
	{
		CCF_Vec2 dir = (prevPos - mousePos) / dist;
		int i = 0;

		while (dist > 0)
		{
			AddADot(mousePos + i * BRUSH_DOTS_MIN_DISTANCE * dir);

			i++;
			dist -= BRUSH_DOTS_MIN_DISTANCE;
		}

		m_mousePositions.push_back(mousePos);
	}
}

void Brush::AddADot(CCF_Vec2 mousePos)
{
	auto sz = m_brushDots.size();
	auto dot = ((sz == 0) ? BrushDot::Create(this) : (BrushDot*)m_brushDots[0]->Clone());

	dot->SetPosition(CameraGameplay::GetInstance()->ScreenToWorldCoordinate(mousePos), CCF_ANCHOR_LEFT_BOTTOM);

	m_brushDots.push_back(dot);
}