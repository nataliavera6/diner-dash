#include "BaseCounter.h"
#pragma once

class StoveCounter : public BaseCounter{
    private:
        Item *item;
        int burgerCookingTime = 0;
    public:
        StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        virtual Item* getItem();
        virtual void showItem();
        void tick();
        void cook();
        bool iscooking = false;
        bool doneCooking = false;
};