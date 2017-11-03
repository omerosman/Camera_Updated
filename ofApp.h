#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "ofxOsc.h"
#include "ofxGui.h"

#include "ofxFaceTracker.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		ofImage grabMouth();
		void drawMouth(ofVec2f eye, ofImage mouth);


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
		
	ofVideoGrabber vidGrabber;
	int             camWidth, camHeight;
	ofxFaceTracker tracker;
	ofPixels	darker;
	ofTexture       darkTexture;
	ofPixels	lighter;
	ofTexture	lightTexture;

};
