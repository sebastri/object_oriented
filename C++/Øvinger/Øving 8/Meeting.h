#pragma once
#include "std_lib_facilities.h"
#include "Car.h"

enum class Campus{Trondheim, Ålesund, Gjøvik};
const map<Campus, string> mappet{
    {Campus::Trondheim, "Trondheim"},
    {Campus::Ålesund, "Ålesund"},
    {Campus::Gjøvik, "Gjøvik"},
};

ostream& operator<<(ostream& out, const Campus& c);



class Meeting{
    private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    Person* leader;
    set<Person*> participants;
    static set<Meeting*> meetings;
    vector<string> vec;


    public:
    int getDay();
    int getStartTime();
    int getEndTime();
    Campus getLocation();
    string getSubject();
    Person* getLeader();
    void addParticipant(Person* person);
    Meeting(int dag, int startdag, int sluttdag, Campus område, string subj, Person* lead);
    ~Meeting();
    vector<string> getParticipantList();
    vector<const Person*> findPotentialCoDriving();
    
};

ostream& operator<<(ostream& out, Meeting& m);

