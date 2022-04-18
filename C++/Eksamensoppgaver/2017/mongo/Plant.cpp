#include "Plant.h"

PlantStatus Plant::getStatus(){
        if (humidityMin<humidity<humidityMax)
        {
            return HAPPY_PLANT;
        }
        else if (0<humidity<humidityMin)
        {
            return WATER_LOW;
        }
        else if (humidity>humidityMax)
        {
            return WATER_HIGH;
        }
        else
        {
            return SENSOR_ERROR;
        }
}

bool Plant::operator==(Plant &rhs){
    if (sensorId==rhs.sensorId)
    {
        return true;
    }
}

ostream &operator<<(ostream& out, Plant &p){
    out << p.getName() << " @ " << p.getLocation();
    return out;
}

void Garden::removePlant(Plant p){
    vector<Plant>::iterator it = plants.begin();
    while (it != plants.end())
    {
        if (*it==p)
        {
            it = plants.erase(it);
        }
        else{++it;} 
    }
}

vector<Plant> Garden::needsHelp(){
    
    vector<Plant> vec;
    for (auto p:plants)
    {
        p.readHumidity();
          
        if (p.getStatus() != HAPPY_PLANT)
        {
            vec.push_back(p);
        }
    }
    return vec;
}

void Garden::monitor(int interval){
    while(true)
    {
        vector<Plant> helpUs = needsHelp();
        for (auto p:helpUs)
        {
            
        if (p.getStatus() == WATER_LOW)
        {
            cout << p << ": " << "trenger vann!";
        }
        else if (p.getStatus() == WATER_HIGH){
            cout << p << ": " << "har for mye vann!";
        }
        else if (p.getStatus() == SENSOR_ERROR){
            cout << p << ": " << "sensorfeil!";
        }
        }
        //sleep(interval);
    }
}