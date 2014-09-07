//
//  HelpScene.cpp
//  PlaneGame
//
//  Created by Eric Wang on 14-9-7.
//
//

#include "HelpScene.h"
#include "HelloWorldScene.h"

bool HelpScene::init() {
    if (!Layer::init()) {
        return false;
    }
    auto spriteBK = Sprite::create("help.png");
    spriteBK->setPosition(Vec2::ZERO);
    spriteBK->setAnchorPoint(Vec2::ZERO);
    this->addChild(spriteBK);
    
    EventListenerTouchOneByOne* touch = EventListenerTouchOneByOne::create();
    
    touch->onTouchBegan = [](Touch *touch, Event *event) {
    
        return true;
    };
    
    touch->onTouchMoved = [](Touch *touch, Event *event) {
        Director::getInstance()->replaceScene(HelloWorld::createScene());
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);
    
    return true;
}

Scene* HelpScene::createScene() {
    auto scene = Scene::create();
    auto layer = HelpScene::create();
    scene->addChild(layer);
    return scene;
}