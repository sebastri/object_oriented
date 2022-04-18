#pragma once
#include "std_lib_facilities.h"
#include "GUI.h"
#include "Meeting.h"
#include "Window.h"
#include "Car.h"

using namespace Graph_lib;

class MeetingWindow : public Window{
    private:
    Point x_y;
    int width;
    int height;
    const string& titlename;
    static constexpr int pad = 500/20;
    static constexpr int btnW = 500/6;
    static constexpr int btnH = 500/15;
    static constexpr int fieldW = 500/3;
    static constexpr int fieldH = 500/17;
    static constexpr int fieldPad = 500/6;
    Button quitBtn;
    Button personNewBtn;
    In_box personName;
    In_box personEmail;
    Vector_ref<Person> people;
    

    public:
    MeetingWindow(Point xy, int w, int h, const string& title);
    static void cb_quit(Address, Address pw);
    static void cb_new_person(Address, Address po);
    void addPerson();
    void printpeople();
};


