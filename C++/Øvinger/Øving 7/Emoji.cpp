#include "Emoji.h"

Face::Face(Point c, int r) : ansikt{c,r}
{
    ansikt.set_fill_color(Color::yellow);
}

void Face::attach_to(Graph_lib::Window& win){
    win.attach(ansikt);
}

void EmptyFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(leftEye);
    win.attach(rightEye);
}
void EmptyFace::attach_to2(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(leftEye);
}

EmptyFace::EmptyFace(Point c, int r): Face{c,r}, 
leftEye{Point{c.x-16,c.y-14},r-40}, 
rightEye{Point{c.x+16,c.y-14}, r-40}
{
    leftEye.set_fill_color(Color::black);
    rightEye.set_fill_color(Color::black);
}
