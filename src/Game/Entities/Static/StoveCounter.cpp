#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height,Item* item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite){
    this->item = item;
}

Item* StoveCounter::getItem(){
    return item;
}

void StoveCounter::showItem(){
    if (item != nullptr){
        if (doneCooking == true){
            ofSetColor(50, 0, 0);
        }
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }

    }

void StoveCounter::tick(){
iscooking = true;
if (iscooking){
    burgerCookingTime ++;
}else if (iscooking == false){
    burgerCookingTime = 0;
}
}

void StoveCounter::cook(){
    if (iscooking == false){
            iscooking = true;
            doneCooking = false;
    }if (burgerCookingTime == 30){
            iscooking = false;
            doneCooking = true;
    }
}