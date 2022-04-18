#pragma once
#include "std_lib_facilities.h"

double acclY();
double velY(double initVelocityY, double time);
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);
void printTime(double sek);
double flightTime(double Ystartfart);
void testDeviation(double compareOperand, double toOperand, double maxError, string name);
double getUserInputTheta();
double getUserInputAbsVelocity();
double degToRad(double deg);
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
vector<double> getVelocityVector(double theta, double absVelocity);
double getDistanceTraveled(double velocityX, double velocityY);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);