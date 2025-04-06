#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();
	if (restaurant->getMoney() >= 100){
		setFinished(true);
		restaurant->setMoney(0);
		setNextState("Win");
	}if(restaurant->didILose()){
		setFinished(true);
		restaurant->setMoney(0);
		setNextState("Lose");
}
}

void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}