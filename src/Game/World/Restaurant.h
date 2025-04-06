//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"
#include "inspector.h"
#include "StoveCounter.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int money =0;
        bool lose = false;
        bool win = false;

    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        ofImage plant;
        ofImage floor;
        ofImage furniture;
        ofImage chair;
        ofImage table;
        int Inspectorcounter=0;
        int amountGenerated=0;
         vector<double> tableX{5.5,5.5,5.5,5.5,5.5,1.23,1.23,1.23,1.23,1.23}; // x values for each table
         vector<double> tableY{8,4.5,3.2,2.45,2,8,4.5,3.2,2.45,2};// y values for each table
         vector<double> plantX{5,2.5,1.2,1.9}; // x values for each plant
         vector<double> plantY{3.8,3,3.8,3};// y values for each plant
         vector<double> chairX{7,7,7,7,7,1.3,1.3,1.3,1.3,1.3}; // x values for each chair
         vector<double> chairY{6,3.8,2.9,2.25,1.85,6,3.8,2.9,2.25,1.85};// y values for each chair
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void generateInspector();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        bool didILose();
        bool didIWin();
        int getMoney();
        void setMoney(int money);
        
         //randomizes the number of ingredients in client's burger
        int NumOfIngredients = ofRandom(1,4);
        //randomizes which ingredient is in client's burger 
        int randomIngredientIndex=ofRandom(0,4);
};
