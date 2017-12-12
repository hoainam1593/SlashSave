
#ifndef __UP_SPEED_PICKUP_H__
#define __UP_SPEED_PICKUP_H__

#include "CCF_SpriteAnim.h"

namespace SlashSave
{

#define UP_SPEED_PICKUP_INCREASED_SPEED 60
#define UP_SPEED_PICKUP_EFFECT_TIME 3

	class UpSpeedPickup : public CCF_Sprite
	{
	public:
		CCF_CREATE_FUNC(UpSpeedPickup)
		CCF_GAME_OBJECT_CREATE_FUNC(UpSpeedPickup)
		
		bool Init(cocos2d::Node* parent);
		cocos2d::Node* Clone();
		void SetPosition(const CCF_Vec2& offset, const CCF_Vec2& anchorToScreen);
		void setVisible(bool bVisible);

		bool OnCollideWith(cocos2d::PhysicsBody* other);

	private:
		void OnDestroy();

	private:
		CCF_SpriteAnim* m_electricEffect;
	};

}

#endif