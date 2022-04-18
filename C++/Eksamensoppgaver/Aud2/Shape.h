#include <vector>

struct Shape{
    int linewidth, line_color, fill_color;
    vector<Point> pts;
    Shape(int lw, int lc, int fc):linewidth(lw),line_color(lc),fill_color(fc){};
    void add(Point p) {pts.push_back(p);}
    void move(int dx, int dy){
        for (int i = 0; i < pts.size(); i++)
        {
            pts[i].x += dx;
            pts[i].y += dy;
        }
        
    }
    virtual void draw() {}
};
