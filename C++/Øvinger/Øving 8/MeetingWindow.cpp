#include "MeetingWindow.h"


void MeetingWindow::cb_quit(Address, Address pw){
reference_to<MeetingWindow>(pw).hide();
}

void MeetingWindow::cb_new_person(Address, Address po){
    reference_to<MeetingWindow>(po).addPerson();
}

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title):Window(w, h, title), 
quitBtn(Point{400-pad-btnW, pad}, btnW, btnH, "Quit", cb_quit), x_y{xy}, width{w}, height{h},titlename{title},
personName(Point{fieldPad,pad}, fieldW, fieldH, "Name"), personEmail(Point{fieldPad, 2*pad+(fieldH)}, fieldW, fieldH, "Email"),
personNewBtn(Point{fieldPad, 2*fieldH + (3*pad)}, btnW, btnH, "Add Person", cb_new_person)
{
    attach(quitBtn); 
    attach(personName);
    attach(personEmail);
    attach(personNewBtn);
}

void MeetingWindow::addPerson(){
    
    people.push_back(new Person{personName.get_string(), personEmail.get_string()});
    personEmail.clear_value();
    personName.clear_value();
}

void MeetingWindow::printpeople(){
    for(auto i:people){
        cout << i->getName() << " " << i->getEmail() << endl;
    }
}