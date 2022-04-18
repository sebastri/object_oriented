// Assignment 3 - Open Assignment
#pragma once
#include "Line.h"
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include "GUI.h"

using namespace Graph_lib;

struct Windows : Fl_Double_Window{
    Windows(Point xy, int w, int h, string title):
    Fl_Double_Window(xy.x, xy.y, w, h, title.c_str()){
        color(FL_BLACK);
        show();
    }
    vector<Shape *> shapes;
    void attach(Shape& s){shapes.push_back(&s);}
    void draw(){
        Fl_Double_Window::draw();
        for (int i = 0; i < shapes.size(); i++)
        shapes[i]->draw();
    }
    
    
};



int main(){


    Windows mwin{Point{900, 20}, 500, 500, "Mastermind"};
    
    cout << "Please enter input file name: ";
    string inName;
    cin >> inName;
    ifstream ist{inName};
    if (!ist) error("cant open input file", inName);
    string lines;
    vector<Point> vc;
    while(getline(ist,lines)){
        stringstream ss{lines};
        for (int i = 0; i < 1; i++)
         {
            string x1;
            string y1;
          
            ss >> x1;
            ss >> y1;
            vc.push_back(Point{stoi(x1), stoi(y1)});
        } 
    }
    /*
    for (int i = 0; i < vc.size(); i++)
    {
        Lineftw l(vc[i], vc[i+1], 3, FL_WHITE);
        mwin.attach(l);
    }
    */
    Line line1(Point{4,4}, Point{5,5}, 3, FL_WHITE);
    mwin.attach(line1);
    return Fl::run();
    
    
    keep_window_open();


}   