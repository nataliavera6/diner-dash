//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "Entity.h"
#include "Item.h"

class Burger {
  private:
    int x, y, width, height;
    vector<Item *> ingredients;

  public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    bool equals(Burger* burg);
    void render();
    void eliminateAll();
    void removeIngredient();
     void setY(int y) {
         this->y = y;
     }
      int IngredientCounter(Item* ingredient);
    //getter for ingredients vector of burger 
  vector<Item* >getIngredients(){return ingredients;}
};
