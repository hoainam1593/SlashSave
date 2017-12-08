
#include "BackgroundTile.h"

using namespace cocos2d;
using namespace SlashSave;

bool BackgroundTile::Init(cocos2d::Node* parent)
{
	CCF_Sprite::Init(BACKGROUND_TILE_SPRITE_FILE_NAME, 0, CCF_ANCHOR_CENTER, parent);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto sz = getContentSize();

	setScale(visibleSize.width / sz.width);

	return true;
}