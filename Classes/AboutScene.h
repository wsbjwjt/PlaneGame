//
//  AboutScene.h
//  PlaneGame
//
//  Created by Eric Wang on 14-9-7.
//
//

#ifndef __PlaneGame__AboutScene__
#define __PlaneGame__AboutScene__

#include "cocos2d.h"

using namespace cocos2d;

class AboutScene : public Layer {
    
public:
    bool init();
    CREATE_FUNC(AboutScene);
    static Scene * createScene();
};

#endif /* defined(__PlaneGame__AboutScene__) */
