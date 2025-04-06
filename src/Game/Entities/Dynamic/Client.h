#pragma once
#include "Entity.h"
#include "Burger.h"


class Client: public Entity{
    //private:
    protected:
        Burger* burger;
        int originalPatience;
        int patience=2000;
        int color=3;
        // bool yellow=false;
        // bool red = false;
        // bool orange=false;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        virtual void tick();
        virtual void render();
        virtual int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;
        bool isHappy = true;
        //getter for client's burger 
        Burger* getClientBurger(){ return burger;
        }
        virtual bool isInspector(){return false;}
        virtual bool isPrincess(){return false;}
        ofImage getSprite(){return sprite;}
        int servestreak=0;



};