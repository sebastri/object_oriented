#include "std_lib_facilities.h"
#include "cannonball.h"

double acclY(){
double a = -9.81;
return a;
}

double velY(double initVelocityY, double time){
    double FartY = initVelocityY + acclY()*time;
    return FartY;
}

double posX(double initPosition, double initVelocity, double time){
    double posisjonX = initPosition + (initVelocity*time) + (0*pow(time, 2))/2;
    return posisjonX;
}

double posY(double initPosition, double initVelocity, double time){
    double posisjonY = initPosition + (initVelocity*time) + (acclY()*pow(time, 2))/2;
    return posisjonY;
}

void printTime(double sek){
    int timer = sek / 3600;
    int minutter = (sek - timer*3600)/60;
    int sekunder = sek - (timer*3600) - (minutter*60);
    cout << "Tiden er " << timer << " tim(er) " << minutter << " minutt(er) " << " og " << sekunder << "sekund(er).";
}

double flightTime(double Ystartfart){
    double Tid = (-2*Ystartfart)/acclY();
    return Tid;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
    cout << name << "\n";
    if ((abs(compareOperand-toOperand))<maxError){
        cout << "Tallene er tilnærmet like med en maxError på " << maxError;
    }
    else {
        cout << "Tallene har for stor differanse med en maxError på " << maxError;
    }
}

double getUserInputTheta(){
    double theta;
    cout << "Skriv inn en vinkel: ";
    cin >> theta;
    return theta;
}

double getUserInputAbsVelocity(){
    double absoluttfart;
    cout << "Skriv inn en absoluttfart: ";
    cin >> absoluttfart;
    return absoluttfart;
}

double degToRad(double deg){
    double rad = deg*(_Pi/180);
    return rad;
}


double getVelocityX(double theta, double absVelocity){
    double FartX = absVelocity*cos(theta);
    cout << "FartY: " << FartX << endl;
    return FartX;
}

double getVelocityY(double theta, double absVelocity){
    double FartY = absVelocity*sin(theta);
    cout << "FartY: " << FartY << endl;
    return FartY;
}

vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> velocityvec;
    theta = degToRad(theta);
    velocityvec.push_back(getVelocityX(theta, absVelocity));
    velocityvec.push_back(getVelocityY(theta, absVelocity));
    return velocityvec;
}

double getDistanceTraveled(double velocityX, double velocityY){
    double distance = flightTime(velocityY);
    double posx = posX(0, velocityX, distance);
    cout << "Distance Traveled: " << posx << "m" << endl;
    return posx;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    double avvik = (getDistanceTraveled(velocityX, velocityY)-distanceToTarget);
    cout << "Avviket er " << abs(avvik) << endl;
    return avvik;
}
