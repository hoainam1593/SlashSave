
#include "TestScene.h"
#include "CCF_SpriteAnim.h"

USING_NS_CC;
using namespace std;

Scene* TestScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TestScene::create();
    scene->addChild(layer);
    return scene;
}

bool TestScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
	int sz = 14;
	char str[64];
	vector<CCF_String> names;
	names.reserve(sz);
	for (int i = 0; i < sz; i++)
	{
		sprintf(str, "Boundary %d", i);
		names.push_back(str);
	}
	auto sprite = CCF_SpriteAnim::Create("_test/obj_bubble_flight.plist", names, 14, 0, CCF_ANCHOR_CENTER, this);
	sprite->SetPosition(CCF_Vec2(0, 0), CCF_ANCHOR_CENTER);

    return true;
}
