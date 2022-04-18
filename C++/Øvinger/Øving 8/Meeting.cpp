#include "Meeting.h"

ostream& operator<<(ostream& out, const Campus& c){

out << mappet.at(c);

}


int Meeting::getDay(){
    return day;
}
int Meeting::getStartTime(){
    return startTime;
}
int Meeting::getEndTime(){
    return endTime;
}
Campus Meeting::getLocation(){
    return location;
}
string Meeting::getSubject(){
    return subject;
}
Person* Meeting::getLeader(){
    return leader;
}

void Meeting::addParticipant(Person* person){
    participants.insert(person);
}
    
set<Meeting*> Meeting::meetings;


Meeting::Meeting(int dag, int startdag, int sluttdag, Campus område, string subj, Person* lead):
day{dag}, startTime{startdag}, endTime{sluttdag}, location{område}, 
subject{subj}, leader{lead}
{
meetings.insert(this);
};

Meeting::~Meeting(){
    auto it = meetings.find(this);
    meetings.erase(it);
}

/*
Meeting::~Meeting(){
    meetings.find(this);
    for (auto it:meetings){
        meetings.erase(it);
    } 
}
*/

vector<string> Meeting::getParticipantList(){
   for (auto i:participants){
    vec.push_back((*i).getName());
   }
   return vec;
} 

ostream& operator<<(ostream& out, Meeting& m){
    out << m.getDay() << " " << m.getStartTime() << " " << m.getEndTime()  << " " << m.getSubject() << " " << m.getLeader()->getName()  << " " << endl;
    vector<string> vec = m.getParticipantList();
    for (unsigned int i = 0; i < vec.size(); i++){
        out << vec[i] << "\n";
    }
    return out;
}

vector<const Person*> Meeting::findPotentialCoDriving(){
    vector<const Person*> vec;
    for (auto m:meetings){
        if (this!=m){
            if (m->leader->hasAvailableSeats() > 0){
                if (m->getLocation()== this->location && m->getDay() == this->day){
                    if(abs(this->startTime - m->getStartTime() <= 1) && abs(this->endTime - m->getEndTime() <= 1) ){
                        vec.push_back(m->leader);
                    }
                }
                
            }
            
        }
    }
}

