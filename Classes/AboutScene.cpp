//
//  AboutScene.cpp
//  PlaneGame
//
//  Created by Eric Wang on 14-9-7.
//
//

#include "AboutScene.h"
#include "HelloWorldScene.h"

bool AboutScene::init() {
    if (!Layer::init()) {
        return false;
    }
    auto spriteBK = Sprite::create("about.png");
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

Scene* AboutScene::createScene() {
    auto scene = Scene::create();
    auto layer = AboutScene::create();
    scene->addChild(layer);
    return scene;
}