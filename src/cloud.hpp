//
//  cloud.hpp
//  midtermProject
//
//  Created by yang on 3/15/17.
//
//

#ifndef cloud_hpp
#define cloud_hpp

#include <stdio.h>
#include "ofMain.h"

class cloud{
public:
    
    cloud();
    void draw();
    void move(float catchX, float catchY);
    
    ofPoint pos;
    float catchUpSpeed;
    ofColor color;

    
};




#endif /* cloud_hpp */
