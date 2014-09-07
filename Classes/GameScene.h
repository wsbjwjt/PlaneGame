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
};



#endif /* defined(__PlaneGame__GameScene__) */
