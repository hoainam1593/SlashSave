
#include "UpSpeedPickup.h"
#include "GameUtils.h"
#include "CameraGameplay.h"

using namespace cocos2d;
using namespace SlashSave;
using namespace std;

#define UP_SPEED_PICKUP_SPRITE_FILE_NAME "sprites/gameplay/battery-sheet0.png"
#define UP_SPEED_PICKUP_BODY_RADIUS 24

#define ELECTRIC_EFFECT_PLIST_FILE_NAME "sprites/gameplay/electric.plist"
#define ELECTRIC_EFFECT_NUMBER_OF_FRAMES 3
#define ELECTRIC_EFFECT_ANIM_FPS 10

bool UpSpeedPickup::Init(cocos2d::Node* parent)
{
	// Init pickup
	CCF_Sprite::Init(UP_SPEED_PICKUP_SPRITE_FILE_NAME, 1, CCF_ANCHOR_CENTER, parent);
	CreateCircleBody(UP_SPEED_PICKUP_BODY_RADIUS, false, nullptr, 0, GAME_OBJECT_TAG_UP_SPEED_PICKUP);

	// Init effect.
	{
		vector<CCF_String> names;
		CCF_BuildFrameNames(names, ELECTRIC_EFFECT_NUMBER_OF_FRAMES);

		m_electricEffect = CCF_SpriteAnim::Create(ELECTRIC_EFFECT_PLIST_FILE_NAME, names, ELECTRIC_EFFECT_ANIM_FPS, 0, CCF_ANCHOR_CENTER, parent);
	}
	
	return true;
}

cocos2d::Node* UpSpeedPickup::Clone()
{
	auto other = UpSpeedPickup::Create();

	other->m_electricEffect = (CCF_SpriteAnim*)m_electricEffect->Clone();
	CopyTo(other);

	return other;
}

void UpSpeedPickup::SetPosition(const CCF_Vec2& offset, const CCF_Vec2& anchorToScreen)
{
	CCF_Sprite::SetPosition(offset, anchorToScreen);
	m_electricEffect->SetPosition(offset, anchorToScreen);
}

void UpSpeedPickup::setVisible(bool bVisible)
{
	CCF_Sprite::setVisible(bVisible);
	m_electricEffect->setVisible(bVisible);
}

bool UpSpeedPickup::OnCollideWith(cocos2d::PhysicsBody* other)
{
	if (other->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		OnDestroy();
		return false;
	}

	return true;
}

void UpSpeedPickup::OnDestroy()
{
	setVisible(false);
}