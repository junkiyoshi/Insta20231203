#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(ofGetFrameNum() * 1.44);

	auto radius = 300;
	for (auto deg = 0; deg < 360; deg += 5) {

		auto location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0);

		ofPushMatrix();
		ofTranslate(location);
		ofRotateZ(deg);

		ofRotateY(deg * 2 + ofGetFrameNum() * 4);

		ofFill();
		ofSetColor(0);
		ofDrawBox(40, 15, 250);

		ofNoFill();
		ofSetColor(255);
		ofDrawBox(40, 15, 250);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}