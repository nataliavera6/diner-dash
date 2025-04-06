#include "Entity.h"
#include "Burger.h"
#include "Client.h"

class inspector:public Client {
private:
        Burger* burger;
        int originalPatience;
        int patience=2000;
public:
    //inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger);
   // ~inspector();

        inspector(int, int, int, int, ofImage, Burger*);
        //virtual ~Client();
        // virtual void tick();
        // virtual void render();
        virtual int serve(Burger*);
         bool isLeaving=false;
         virtual bool isInspector(){return true;}

//inspector::~inspector();
};