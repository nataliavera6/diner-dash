#include "inspector.h"

inspector::inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger):Client( x, y, width,  height,  sprite,  burger){
    this->tick();
    this->render();
    //this->serve(burger);
}
// void inspector::render(){
//     burger->render();
//     ofSetColor (255,255,255);
//     sprite.draw(x, y, width, height);
// }

// void inspector::tick(){
//     patience--;
//     //burger->setY(y);
//     if(patience == 0){
//         isLeaving = true;
//     }
// }

int inspector::serve(Burger* burger){
    int price=0;
     if (this->getClientBurger()->equals(burger)==true){
        isLeaving = true;
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
    }
}
