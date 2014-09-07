//
//  GameScene.cpp
//  PlaneGame
//
//  Created by Eric Wang on 14-9-7.
//
//

#include "GameScene.h"

bool GameScene::init() {
    if (!Layer::init()) {
        return false;
    }
    auto spriteBK = Sprite::create("background4.png");
    spriteBK->setPosition(Vec2::ZERO);
    spriteBK->setAnchorPoint(Vec2::ZERO);
    this->addChild(spriteBK);
    return true;
}

Scene* GameScene::createScene() {
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}
