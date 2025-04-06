#include "WinState.h"


WinState::WinState() {
	string text = "Try Again";
	retryButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Try Again");

}
void WinState::tick() {
	retryButton->tick();
	if(retryButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);}
}

void WinState::render() {
	ofSetBackgroundColor(255, 255, 255);
	ofSetColor(255,255,255);
    ofDrawBitmapString("You Win", ofGetWidth()/2, ofGetHeight()/1.5);
	retryButton->render();
}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
	retryButton->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
    retryButton->reset();

}