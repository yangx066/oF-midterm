#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "cloud.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVideoGrabber cam;
    ofImage skirt;
    ofImage pants;
    ofImage coat;
    ofImage sun;
    ofTrueTypeFont tempFont;
    ofTrueTypeFont warning1;
    ofTrueTypeFont warning2;
    ofTrueTypeFont cong;
    int temp;
    string icon;
    int alpha1 = 255;
    int alpha2 = 255;
    ofSerial serial;
    float a;
    cloud myCloud;
    cloud myCloud1;
    cloud myCloud2;
    ofSoundPlayer music;
    ofSoundPlayer clap;
    
    ofArduino	ard;
private:
    
    void setupArduino(const int & version);
    void updateArduino();
    bool		bSetupArduino;

   

		
};
