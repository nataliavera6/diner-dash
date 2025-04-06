#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){

    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
    
}
void Player::tick(){
    chefAnim->tick();
    // if(facing == "left"){
    //     x-=speed;
    // }else if(facing == "right"){
    //     x+=speed;
    // }
    // if(x <= 0){
    //     facing = "right";
    // }else if(x + width >= ofGetWidth()){
    //     facing = "left";
    // }

}

void Player::render(){
    BaseCounter *ac = getActiveCounter();
    if (ac != nullptr) {
        ac->showItem();
        ac->tick();}

    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key){
    if(key == 'e'){
        BaseCounter* ac = getActiveCounter();
        if(ac != nullptr){
            Item* item = ac->getItem();
            if(item != nullptr){
                    burger->addIngredient(item);
            }
        }
    }
    if(key == 'u'){
        burger->removeIngredient();
    }
    //if you press left key, chef moves one block to the left
    if(key == OF_KEY_LEFT){
        //chef reappears from the right when he walks off screen to the left
        if(x<0){
            x=ofGetWidth();
        }
        facing="left";
        x-=speed+90;
    }
    //if you press right key, chef moves one block to the right
    if(key == OF_KEY_RIGHT){
        //chef reappears from the left when he walks off screen to the right
        if(x>ofGetWidth()-90){
            x=-90;
        }
        facing="right";
        x+=speed+90;
    }
}
BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}


void Player::keyReleased(int key) {
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }