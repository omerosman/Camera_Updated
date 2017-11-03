#include "ofApp.h"

//--------------------------------------------------------------
using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
	camWidth = 320;
	camHeight = 240;

	vidGrabber.setVerbose(true);
	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(camWidth, camHeight);

	lighter.allocate(camWidth, camHeight, OF_PIXELS_RGB);
	lightTexture.allocate(darker);
	
	tracker.setup();

}

//--------------------------------------------------------------
void ofApp::update() {
	vidGrabber.update();
	if (vidGrabber.isFrameNew()) {
		tracker.update(toCv(vidGrabber));
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(ofColor::white);
	//vidGrabber.draw(0, 0);
	tracker.draw();
	lightTexture.draw(2*camWidth,0);
	lightTexture.draw(0,2*camHeight,camWidth,-camHeight);
	lightTexture.draw(camWidth*2, 2 * camHeight, camWidth, -camHeight);

	vidGrabber.draw(camWidth,0);
	vidGrabber.draw(camWidth, 2 * camHeight, camWidth, -camHeight);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'x') {
		if (vidGrabber.isFrameNew()) {
			ofPixels & pixels = vidGrabber.getPixels();
			for (size_t i = 0; i < pixels.size(); i++) {
				lighter[i] = 255 - pixels[i];
			}
			lightTexture.loadData(lighter);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
//--------------------------------------------------------------