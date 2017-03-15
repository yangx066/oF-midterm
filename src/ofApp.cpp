#include "ofApp.h"
#include "ofxJSON.h"
int byteData;

ofxJSONElement json;	// JSON reader

//--------------------------------------------------------------
void ofApp::setup(){
    music.load("music.mp3");
    music.play();
    clap.load("clap.mp3");

    ard.connect("/dev/cu.usbmodem1421",57600);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino	= false;
    
//    serial.setup("/dev/cu.usbmodem1421", 9600);
    ofBackground(255,255,255);
    
    string url = "https://api.darksky.net/forecast/d50195f011439e72a3544440252f540e/40.7128,74.0059";
    json.open(url);
    temp = json["currently"]["temperature"].asInt();
    icon = json["currently"]["icon"].asString();
    cout << temp << endl;
    cout << icon << endl;
    
    
    cam.setup(1280,720);
    skirt.load("skirt.png");
    pants.load("pants.png");
    coat.load("coat.png");
    sun.load("sun.png");
    
    myCloud.pos.x = 0;
    myCloud.pos.y = 90;
    myCloud1.pos.x = ofGetWidth();
    myCloud1.pos.y = 140;
    myCloud2.pos.x = 800;
    myCloud2.pos.y = 160;

    

}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
//    while (serial.available() >= 0) {
//        a = serial.readByte();
//    }
        updateArduino();

        myCloud.move(ofGetWidth(),myCloud.pos.y);
        myCloud1.move(-ofGetWidth(),myCloud1.pos.y);
        myCloud2.move(-ofGetWidth(),myCloud1.pos.y);


}

void ofApp::setupArduino(const int & version) {
    
    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
    
    // it is now safe to send commands to the Arduino
    bSetupArduino = true;
    
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();
    
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    ard.sendAnalogPinReporting(1, ARD_ANALOG);
    ard.sendAnalogPinReporting(2, ARD_ANALOG);
    
}

void ofApp::updateArduino(){
    
    ard.update();
}


//--------------------------------------------------------------
void ofApp::draw(){


    int data0 = ard.getAnalog(0);
    int data1 = ard.getAnalog(1);
    int data2 = ard.getAnalog(2);
    cout << data0 << endl;
    cout << data1 << endl;
    cout << data2 << endl;
    
    
    ofSetColor(255,255,255);
    cam.draw(1280,0,-1280,720);

    
    skirt.draw(150, 200,500,500);
    pants.draw(450, 200,500,500);
    coat.draw(750, 200,500,500);
 


    string weather = ofToString(temp);
    tempFont.load("FuturBoo",40);
    tempFont.drawString("TEMPERATURE:" + weather+"F", 700, 100);

    
    
    
    
    
    if(icon == "clear"){
        sun.draw(100, 50,100);
    }else if(icon == "cloudy"){
        sun.draw(100, 50,100);
        myCloud.draw();
        myCloud1.draw();
        myCloud2.draw();
 
    }else if(icon == "snow"){
        
    }
    if(temp<20){
    if (data0 > 50) {
        skirt.clear();
        pants.clear();
        music.stop();
        clap.play();
        ofSetColor(255, 87, 87);
        cong.load("FuturBoo",50);
        cong.drawString("CONGRADULATIONS!" , 130, 400);
    }
    
    if(data1 >50) {
        ofSetColor(255, 87, 87);
        warning2.load("FuturBoo",40);
        warning2.drawString("Try again!" , 580, 150);
        
    }
    if(data2 >50) {
        ofSetColor(255, 87, 87);
        warning2.load("FuturBoo",40);
        warning2.drawString("Try again!" , 280, 150);
            }
    }


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){



}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
   
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    

//        ofClear ( 0, 255,255);
//        cam.draw(1600,0,-1600,900);
//        alpha2=255;
    

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
