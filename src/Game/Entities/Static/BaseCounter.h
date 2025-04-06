//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "Item.h"
#include "Entity.h"

class BaseCounter: public Entity {
    protected:
        Item *item;

    public:
        BaseCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        virtual Item* getItem();
        virtual void showItem();

};
