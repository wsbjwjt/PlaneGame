//
//  GameScene.h
//  PlaneGame
//
//  Created by Eric Wang on 14-9-7.
//
//

#ifndef __PlaneGame__GameScene__
#define __PlaneGame__GameScene__

#include "cocos2d.h"

using namespace cocos2d;

class GameScene : public Layer {

public:
    bool init();
    CREATE_FUNC(GameScene);
    static Scene * createScene();
    
    void moveBackground(float t);
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    int px, py;
    
    Vector<Sprite *> allBullet;
    virtual void newBullet(float dt);
    virtual void moveBullet(float dt);
    
    Vector<Sprite *> allEnemy;
    virtual void newEnemy(float dt);
    virtual void moveEnemy(float dt);
};



#endif /* defined(__PlaneGame__GameScene__) */
