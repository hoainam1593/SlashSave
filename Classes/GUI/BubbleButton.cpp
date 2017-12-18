
#include "BubbleButton.h"

using namespace SlashSave;

#define BUBBLE_BUTTON_SCALE_INTENSITY 0.02f
#define BUBBLE_BUTTON_SCALE_FREQUENCY 8.0f

BubbleButton* BubbleButton::Create(CCF_Sprite* sprite, const cocos2d::ccMenuCallback& callback, float localZOrder, Node* parent)
{
	auto pRet = BubbleButton::create();

	pRet->Init(sprite, callback, localZOrder, parent);

	return pRet;
}

void BubbleButton::Init(CCF_Sprite* sprite, const cocos2d::ccMenuCallback& callback, float localZOrder, Node* parent)
{
	CCF_Button::Init(sprite, callback, CCF_ANCHOR_CENTER, localZOrder, parent);

	m_totalTime = 0;
	m_originalScale = CCF_Vec2(m_item->getScaleX(), m_item->getScaleY());
}

void BubbleButton::update(float dt)
{
	m_totalTime += dt;

	auto t = sinf(m_totalTime * BUBBLE_BUTTON_SCALE_FREQUENCY) * BUBBLE_BUTTON_SCALE_INTENSITY;

	auto scale = m_originalScale.x + t;
	m_item->setScaleX(scale);

	scale = m_originalScale.y - t;
	m_item->setScaleY(scale);
}