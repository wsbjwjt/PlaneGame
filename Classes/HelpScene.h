//
//  HelpScene.h
//  PlaneGame
//
//  Created by Eric Wang on 14-9-7.
//
//

#ifndef __PlaneGame__HelpScene__
#define __PlaneGame__HelpScene__

#include "cocos2d.h"

using namespace cocos2d;

class HelpScene : public Layer {
    
public:
    bool init();
    CREATE_FUNC(HelpScene);
    static Scene * createScene();
};

#endif /* defined(__PlaneGame__HelpScene__) */
