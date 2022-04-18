#pragma once
#include "std_lib_facilities.h"
enum PlantStatus{
    HAPPY_PLANT, WATER_LOW, WATER_HIGH, SENSOR_ERROR
};


class Plant{
    string name;
    string location;
    int sensorId;
    float humidityMin;
    float humidityMax;
    float humidity;

    public:
    string setName(string n){n=name;}

    string getName(){return name;}
    float readSensor(int s);
    Plant(string name, string location, int sensorId, float humidityMin, float humidityMax, float humidity=-1.0):
    name{name}, location{location}, sensorId{sensorId}, humidityMin{humidityMin}, humidityMax{humidityMax}{}

    float readHumidity(){
        humidity = readSensor(sensorId);
        return humidity;
    }
    string getLocation(){return location;}
    PlantStatus getStatus();
    
    bool operator==(Plant &rhs);

    friend ostream &operator<<(ostream& out, Plant &p);
};


class Garden{

    string name;
    vector<Plant> plants;

    public:
    Garden(string name):name{name}{}
    
    void addPlant(Plant p){plants.push_back(p);}
    void removePlant(Plant p);
    vector<Plant> needsHelp();
    void monitor(int interval);
    int sleep(int p);
};
