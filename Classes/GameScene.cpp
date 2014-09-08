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
    spriteBK->setTag(10);
    
    auto spriteBK02 = Sprite::create("background4.png");
    spriteBK02->setPosition(Vec2::ZERO);
    spriteBK02->setAnchorPoint(Vec2::ZERO);
    spriteBK02->setPositionY(spriteBK->getPositionY() + spriteBK->getContentSize().height);
    this->addChild(spriteBK02);
    spriteBK02->setTag(11);
    
    //Add Plane
    auto spPlane = Sprite::create();
    spPlane->setTag(110);
    spPlane->setPosition(Vec2(160, 40));
    this->addChild(spPlane);
    
    Vector<SpriteFrame *> allFrame;
    for (int i = 0; i < 4; i++) {
        
        SpriteFrame *sf = SpriteFrame::create("player.png", Rect(i*47, 0, 47, 56));
        allFrame.pushBack(sf);
    }
    Animation * ani = Animation::createWithSpriteFrames(allFrame, 0.1);
    spPlane->runAction(RepeatForever::create(Animate::create(ani)));
    
    //touch event plane moved
    EventListenerTouchOneByOne *event = EventListenerTouchOneByOne::create();
    event->setSwallowTouches(true);
    
    event->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    event->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    event->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(event, this);
    
    //Schedule
    
    // background moved
    this->schedule(schedule_selector(GameScene::moveBackground), 0.01);
    
    //Add bullet new and move
    this->schedule(schedule_selector(GameScene::newBullet), 0.5);
    
    this->schedule(schedule_selector(GameScene::moveBullet), 0.01);
    
    //Add Enemies
    this->schedule(schedule_selector(GameScene::newEnemy), 0.5);
    
    this->schedule(schedule_selector(GameScene::moveEnemy), 0.01);
    
    return true;
}

Scene* GameScene::createScene() {
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

void GameScene::moveBackground(float t) {
    
    auto spriteBK = this->getChildByTag(10);
    auto spriteBK02 = this->getChildByTag(11);
    
    spriteBK->setPositionY(spriteBK->getPositionY() - 1);
    
    if (spriteBK->getPositionY() < -680) {
        
        spriteBK->setPositionY(0);
    }
    spriteBK02->setPositionY(spriteBK->getPositionY() + 680);
 
}

bool GameScene::onTouchBegan(Touch *touch, Event *unused_event) {
    
    px = touch->getLocation().x;
    py = touch->getLocation().y;
    return true;
}
void GameScene::onTouchMoved(Touch *touch, Event *unused_event) {
    
    int mx = touch->getLocation().x - px;
    int my = touch->getLocation().y - py;
    auto spPlane = this->getChildByTag(110);
    
    spPlane->runAction(MoveBy::create(0, Vec2(mx, my)));
    px = touch->getLocation().x;
    py = touch->getLocation().y;
    
    
}
void GameScene::onTouchEnded(Touch *touch, Event *unused_event) {
    
}

void GameScene::newBullet(float dt) {
    
    auto spPlane = this->getChildByTag(110);
    Sprite *bullet = Sprite::create("bullet3.png");
    bullet->setPosition(Vec2(spPlane->getPositionX(), spPlane->getPositionY() + 20));
    this->addChild(bullet);
    this->allBullet.pushBack(bullet);
}
void GameScene::moveBullet(float dt) {
    
    for (int i = 0; i < allBullet.size(); i++) {
        auto nowBullet = allBullet.at(i);
        nowBullet->setPositionY(nowBullet->getPositionY() + 3);
        
        if (nowBullet->getPositionY() > Director::getInstance()->getWinSize().height) {
            nowBullet->removeFromParent();
            allBullet.eraseObject(nowBullet);
            i--;
        }
    }
}

void GameScene::newEnemy(float dt) {
    
    Sprite * enemy = nullptr;
    int num = rand()%10;
    
    if (num >= 3) {
        enemy = Sprite::create("aaa.png");
        enemy->setTag(1000);
    } else {
        
        enemy = Sprite::create("ccc.png");
        enemy->setTag(2000);
    }
    enemy->setPosition(Vec2(rand()%300 + 10, 500));
    this->addChild(enemy);
    this->allEnemy.pushBack(enemy);
    
}
void GameScene::moveEnemy(float dt) {
    
    for (int i = 0; i < allEnemy.size(); i++) {
        
        auto nowEnemy = allEnemy.at(i);
        nowEnemy->setPositionY(nowEnemy->getPositionY()-3);
        if (nowEnemy->getPositionY() < 0) {
            
            nowEnemy->removeFromParent();
            allEnemy.eraseObject(nowEnemy);
            i--;
        }
    }
}
















