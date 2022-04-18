#pragma once

#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <tuple>
#include "utilities.h"
#include "FL/Fl.H"

class Vehicle: public Fl_Widget{
    protected:
    virtual std::pair<double, double> steer() const = 0;
    virtual void drawBody() const = 0;
    PhysicsState state;
    //Track& const track;
    int goal = 0;
    
    public: 
    Vehicle(double x, double y, double angle):Fl_Widget(10, 10, 10, 10), state{x, y, angle}{}
    void draw() final;
    ~Vehicle() = default;
    bool circleCollision(double delX, double delY, double sumR);
};

class PlayerVehicle: public Vehicle{

    public:
    PlayerVehicle(double x, double y, double angle):  Vehicle(x, y, angle){}
    void drawBody() const;
    std::pair<double, double> steer() const override;
};

/*
class Track: public Fl_Widget{
    std::vector<std::pair<double, double>> goals;
    public:
    Track():Fl_Widget(10, 10, 10, 10){}
    void draw() override;
    const std::vector<std::pair<double, double>>& getGoals() const{
        return goals;
    }
};
*/