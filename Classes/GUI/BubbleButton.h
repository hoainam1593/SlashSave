
#ifndef __BUBBLE_BUTTON_H__
#define __BUBBLE_BUTTON_H__

#include "CCF_Button.h"

namespace SlashSave
{
	class BubbleButton : public CCF_Button
	{
	public:
		CREATE_FUNC(BubbleButton)
			static BubbleButton* Create(CCF_Sprite* sprite, const cocos2d::ccMenuCallback& callback, float localZOrder, Node* parent);

		void Init(CCF_Sprite* sprite, const cocos2d::ccMenuCallback& callback, float localZOrder, Node* parent);
		void update(float dt);

	private:
		float m_totalTime;
		CCF_Vec2 m_originalScale;
	};
}

#endif