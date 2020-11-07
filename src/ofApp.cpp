#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableSmoothing();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    videoPlayer.load("example.mp4");
    videoPlayer.play();
    
    movieWidth = 480;
    movieHeight = 270;
}

//--------------------------------------------------------------
void ofApp::update(){
    videoPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0xFFFFFF);
    videoPlayer.draw(0, ofGetHeight()/2-movieHeight/2);
    
    ofPixels pixels = videoPlayer.getPixels();
    for (int i=0; i<videoPlayer.getWidth(); i+=8) {
        for (int j=0; j<videoPlayer.getHeight(); j+=8) {
            unsigned char r = pixels[(j*movieWidth+i) * 3];
            unsigned char g = pixels[(j*movieWidth+i) * 3+1];
            unsigned char b = pixels[(j*movieWidth+i) * 3+2];
            
            ofSetColor(255, 0, 0, 100);
            ofDrawCircle(movieWidth+i, ofGetHeight()/2-movieHeight/2+j, 10.0*(float)r/255.0);
            ofSetColor(0, 255, 0, 100);
            ofDrawCircle(movieWidth+i, ofGetHeight()/2-movieHeight/2+j, 10.0*(float)g/255.0);
            ofSetColor(0, 0, 255, 100);
            ofDrawCircle(movieWidth+i, ofGetHeight()/2-movieHeight/2+j, 10.0*(float)b/255.0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '0':
            videoPlayer.firstFrame();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    videoPlayer.setPosition((float)x / (float)ofGetWidth());
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    videoPlayer.setPaused(true);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    videoPlayer.setPaused(false);
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
void ofApp::dragEvent(ofDragInfo dragInfo){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

