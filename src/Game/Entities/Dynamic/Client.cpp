#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    delete burger;
}
void Client::render(){
    if (color==1){
        ofSetColor(255, 0, 0);
    }if(color==2){
        ofSetColor(255, 180, 0);
    }else if(color==3){
        ofSetColor(255, 255, 255);
    }
    sprite.draw(x, y, width, height);
    if(nextClient != nullptr){
        nextClient->render();
    }
    burger->render();
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience<=250){
        color=1;
    }
    if (patience<=1000&&patience>250){
        color=2;
    }

    if(patience == 0){
        isLeaving = true;
        isHappy = false;
        servestreak=0;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    int price = 0;
    if (this->getClientBurger()->equals(burger)||(servestreak>3&&servestreak<5)){
        isLeaving = true; 
        servestreak++;
        for (int i = 0; i<burger->getIngredients().size(); i++){
            if (burger->getIngredients()[i]->name == "cheese"){
                price += 3;
            }if (burger->getIngredients()[i]->name == "lettuce"){
                price += 2;
            }if (burger->getIngredients()[i]->name == "tomato"){
                price += 2;
            }if (burger->getIngredients()[i]->name == "patty"){
                price += 4;
            }if (burger->getIngredients()[i]->name == "topBun" || burger->getIngredients()[i]->name == "bottomBun" ){
                price += 1;
            }
        }
        burger->eliminateAll();
        return price;
    }else if(nextClient != nullptr){
        return nextClient->serve(burger);
    }
    burger->eliminateAll();
    return 0;
}

