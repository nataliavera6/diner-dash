//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}
//removes last ingredient added
void Burger::removeIngredient() {
    if (ingredients.size()>0){
         ingredients.pop_back();
    }
   
}
//erases player burger
void Burger::eliminateAll(){
    ingredients.clear();
}
int Burger::IngredientCounter(Item *ingredient){
    vector<Item* > ing=this->getIngredients();
    int counter=0;
    for (int i=0;i<=ing.size()-1;i++){
        if (ing[i]==ingredient){
            counter++;
        }
    }
    return counter;
}

bool Burger::equals(Burger* burg){
    //variables for client's burger(cb) and players's burger(pb) ingredient vectors
    vector<Item* >cb=this->getIngredients();
    vector<Item* >pb=burg->getIngredients();
    bool bur=false;
    if (cb.size()>0&&cb.size()==pb.size()&&pb.size()>0){
        if(cb[0]==pb[0]&&pb[pb.size()-1]==cb[cb.size()-1]){
            for (int b=0;b<=pb.size()-1;b++){
                if(burg->IngredientCounter(pb[b])==this->IngredientCounter(pb[b])){
                    bur=true;
                }if(burg->IngredientCounter(pb[b])!=this->IngredientCounter(pb[b])){
                    return false;
                } 
            }
        }
    }
    return bur;
}
void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}
