//
//  cloud.cpp
//  midtermProject
//
//  Created by yang on 3/15/17.
//
//

#include "cloud.hpp"

cloud::cloud(){
    catchUpSpeed = 0.001f;
    color.set(158,167,183);
}

void cloud::draw(){

    ofEnableAlphaBlending();
    ofSetColor(color,240);
    ofDrawCircle(pos.x,pos.y,40);
    ofDrawCircle(pos.x+40,pos.y+10, 60);
    ofDrawCircle(pos.x+90, pos.y+10, 50);


}

void cloud::move(float catchX, float catchY){
    pos.x = pos.x + catchUpSpeed * (catchX-pos.x);
    pos.y = pos.y + catchUpSpeed * (catchY-pos.y);
}
