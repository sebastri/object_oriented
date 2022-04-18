#include "std_lib_facilities.h"
#include "utilities.h"
#include "cannonball_viz.h"


int randomWithLimits(int downlimit, int upperlimit){
    int diff = upperlimit - downlimit;
    int tilfeldig = rand() % (diff + 1) + downlimit;
    return tilfeldig;
}

void playTargetPractise(){
    cout << "Avstand til målet er mellom (100 og 1000 meter)\n";
    int target = randomWithLimits(100, 1000);
    bool win = false;
    for (int i = 0; i < 10; i++){
        double velocity = getUserInputAbsVelocity();
        double radianer = degToRad(getUserInputTheta());
        double velx = getVelocityX(radianer, velocity);
        double vely = getVelocityY(radianer, velocity);

        cannonBallViz(target, 1000, velx, vely,10);

        double avstandmellom = targetPractice(target, velx, vely);
        if (abs(avstandmellom) < 5){
            cout << "Du traff!"<<endl;
            win = true;
            break;
        }
        else if (avstandmellom > 0) {
            cout << "Skuddet var for langt"<<endl;
        }
        else{
            cout << "Skuddet var for kort" << endl;
        }
    }

    if(!win){
        cout << "Du tapte\n";
    }
}
	
