#include "bildebehandling.h"

float clip(float n, float lower, float upper){
    if (n<=lower)
    {
        return lower;
    }
    else if (n>=upper){
        return upper;
    }
    else
    {
        return n;
    }
}
Image Image::grayscale(){
    Image pic(*this);
    for (int i = 0; i < width*height; i++)
    {
        Color c = data[i];
        int gj = (c.r + c.b +c.g)/3;
        c.r = gj;
        c.b = gj;
        c.g = gj;
        pic.data[i] = c;
    }
    return pic;
}
Image Image::threshold(unsigned int t){
Image pic(*this);
    for (int i = 0; i < width*height; i++)
    {
        Color c = data[i];

        if (c.r >= t)
        {
            c.r = 255;
        }
        else
        {
            c.r = 0;
        }
        
        if (c.g >= t)
        {
            c.g = 255;
        }
        else
        {
            c.g = 0;
        }
        
        if (c.r >= t)
        {
            c.r = 255;
        }
        else
        {
            c.r = 0;
        }
        pic.data[i] = c;
        
        
    }
return pic;


