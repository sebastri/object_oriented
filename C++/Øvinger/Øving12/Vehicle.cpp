#include "Vehicle.h"

void Vehicle::draw(){
    state.update(steer().first, steer().second);
    if (state.x < 0){state.x=0;};
    if (state.y < 0){state.y=0;};
    if (state.x > screenWidth-vehicleRadius){state.x=screenWidth-vehicleRadius;};
    if (state.y > screenHeight-vehicleRadius){state.y=screenHeight-vehicleRadius;};
    drawBody();
}

void PlayerVehicle::drawBody() const{
    fl_color(FL_BLUE);
    fl_line_style(FL_SOLID);
    fl_pie(state.x, state.y, vehicleRadius, vehicleRadius, -state.angle*180/3.1415 + 15, -state.angle*180/3.1415 - 15);

}

std::pair<double, double> PlayerVehicle::steer() const {
    std::pair<double, double> out{0,0};
    if(Fl::event_key('W')) {out.first++;};
    if(Fl::event_key('S')) {out.first--;};
    if(Fl::event_key('D')) {out.second++;};
    if(Fl::event_key('A')) {out.second--;};
    return out;
}
/*
void Track::draw() {
    fl_color(FL_BLACK);
    fl_circle(10,10, spillRadius);
}
*/
bool Vehicle::circleCollision(double delX, double delY, double sumR){
    return(delX*delX + delY*delY < sumR*sumR);
}