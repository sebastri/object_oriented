#pragma once
#include "std_lib_facilities.h"

float clip(float n, float lower, float upper);

struct Color{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    Color(): r(0), g(0), b(0){}
    Color(int red, int green, int blue){
        r=static_cast<uint8_t>(clip(static_cast<float>(red), 0, 255));
        g=static_cast<uint8_t>(clip(static_cast<float>(green), 0, 255));
        b=static_cast<uint8_t>(clip(static_cast<float>(blue), 0, 255));
    }
};

class Image {
private:
Color * data; // Array of pixels
unsigned int width; // Width of image
unsigned int height; // Height of image
typedef float Kernel[3][3];
public:
Image(int width, int height):width{width}, height{height}{
data = new Color[width*height];
};
Image(const Image &other){
    width = other.width;
    height = other.height;
    data = new Color[width*height];
    for (int i = 0; i < width*height; i++)
    {
        data[i]=other.data[i];
    }
};
~Image(){
    delete[] data;
};
Image& operator=(Image rhs);
Color getPixel(int x, int y){return data[y*width + x];};
void setPixel(int x, int y, Color c){c = data[y*width +x];};
Image grayscale(){};

Image threshold(unsigned int t);


Color applyKernel(int x, int y, Kernel k){
    float r = 0;
    float g = 0;
    float b = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Color p = getPixel(x-1 + i, y-1 + j);
            r += p.r * k[i][j];
            g += p.g * k[i][j];
            b += p.b * k[i][j];
        }
    }
    return Color(r,g,b);
}

Image convolve(Kernel k);

Image operator+(Image other){
    if ((width*height) != (other.height * other.width))
    {
        throw invalid_argument("error");
    }
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            Color p1 = this->getPixel(x,y); 
            Color p2 = other.getPixel(x,y);
            Color p((p1.r + p2.r)/2, (p1.g + p2.g)/2, (p1.b +p2.b)/2);
            this->setPixel(x,y,p);
        }
        
    }
    return (*this);
};

};
