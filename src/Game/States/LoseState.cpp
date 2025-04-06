#include "LoseState.h"


LoseState::LoseState() {
	string text = "Try Again";
	retryButton = new Button(ofGetWidth()/2- text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Try Again");

}
void LoseState::tick() {
	retryButton->tick();
	if(retryButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);}
}

void LoseState::render() {
	ofSetBackgroundColor(255, 0, 0);
	ofSetColor(255,255,255);
	string text2 = "You Lose";
    ofDrawBitmapString(text2, ofGetWidth()/2 - 35, ofGetHeight()/4);
	retryButton->render();
}

void LoseState::keyPressed(int key){
	
}

void LoseState::mousePressed(int x, int y, int button){
	retryButton->mousePressed(x, y);
}

void LoseState::reset(){
	setFinished(false);
	setNextState("");
    retryButton->reset();

}