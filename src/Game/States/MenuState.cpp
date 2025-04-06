#include "MenuState.h"
MenuState::MenuState() {
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetBackgroundColor(230, 230, 250);
    ofDrawBitmapString("~GAME INSTRUCTIONS~", 0, 15);
	ofDrawBitmapString("press 'e' to pickup ingredients", 0, 30);
	ofDrawBitmapString("press 's' to serve clients", 0, 45);
	ofDrawBitmapString("press 'u' to undo ingredient",0,60);
	startButton->render();
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}