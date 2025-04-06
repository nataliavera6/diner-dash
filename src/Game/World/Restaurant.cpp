//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }

Restaurant::Restaurant() {
    floor.load("images/floor.jpg");
    plant.load("images/plant.png");
    furniture.load("images/sprite.png");
    table.cropFrom(furniture,0,30,109,85);
    chair.cropFrom(furniture,101,1,57,50);
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager); 
    initItems();
    initCounters();
    initClients();
    generateClient();
    
}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity( new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));

}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);

}
void Restaurant::tick() {
    ticks++;
    if(ticks % 400 == 0){
        generateClient();
       
    }
    player->tick();
    entityManager->tick();
    lose = entityManager->didILose();
    if(entityManager->firstClient !=nullptr){
        if(entityManager->firstClient->isInspector()&& ticks%400==0){
            money=money/2;
        }
    }   

}

bool Restaurant::didILose(){
    return lose;
}

void Restaurant::generateClient(){
    //vector of possible ingredients 
    vector<Item* > possibleIngredients{burger,cheese,tomato,lettuce};
    NumOfIngredients = ofRandom(1,4);

    Burger* b = new Burger(72, 100, 50, 25);

    b->addIngredient(botBread);
    for (int x=0;x<NumOfIngredients;x++){
        randomIngredientIndex=ofRandom(0,4);
        b->addIngredient(possibleIngredients[randomIngredientIndex]);
    }
     b->addIngredient(topBread);
    
    if(amountGenerated==10){
        entityManager->addClient(new inspector(0, 50, 64, 72,people[ofRandom(8)], b));
        amountGenerated=0;
    }  else{
    entityManager->addClient(new Client(0, 50, 64, 72,people[ofRandom(8)], b));
   }
    amountGenerated++;
}
void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    //loop draws all ten tables
    for(int i = 0;i<tableX.size();i++){
        table.draw(ofGetWidth()/tableX[i],ofGetHeight()/tableY[i],ofGetWidth()/9.5, ofGetHeight()/9.5);
    }
    //loop draws all four plants
     for(int i = 0;i<plantX.size();i++){
        plant.draw(ofGetWidth()/plantX[i],ofGetHeight()/plantY[i],ofGetWidth()/15, ofGetHeight()/10);
    }
    //loop draws all ten chairs 
    for(int i = 0;i<chairX.size();i++){
        chair.draw(ofGetWidth()/chairX[i],ofGetHeight()/chairY[i],ofGetWidth()/20, ofGetHeight()/18);
    }
    player->render();
    entityManager->render();
    ofSetColor(255, 0, 0);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth()/2, 10);
    ofSetColor(256, 256, 256);
}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
            money += entityManager->firstClient->serve(player->getBurger()); 
       

    }
    if (money >= 100){
            win = true;
           
        }
}

int Restaurant::getMoney(){
    return money;
}

void Restaurant::setMoney(int money){
    this->money = money;
}


void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
    }if(key == 'e'){
        money-= 1;
    }
}
