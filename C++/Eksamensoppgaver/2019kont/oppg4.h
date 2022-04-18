#pragma once
#include "std_lib_facilities.h"

class RingBuf {
private:
char *buf;    // The underlying buffer
int capacity; // Capacity of underlying buffer (max size)
int start;    // Start of valid data
int size;     // Size of valid data (0 if empty)
public:
RingBuf(int capacity):capacity(capacity){
    buf = new char[capacity];
    start = 0;
    size = 0;
}
RingBuf(const RingBuf &other){
    capacity = other.capacity;
    start = other.start;
    size = other.size;
    buf = new char[other.capacity];
    for (int i = 0; i < capacity; i++)
    {
        buf[i] = other.buf[i];
    }
} // copy constructor
RingBuf(RingBuf &&other):buf(other.buf), start(other.start),size(other.size){
other.buf = nullptr;
other.start = 0;
other.size = 0;
} // move constructor
~RingBuf(){
    delete[] buf;
}
RingBuf& operator=(RingBuf rhs){
    swap(buf, rhs.buf);
    swap(start, rhs.start);
    swap(size, rhs.size);
    return *this;
} // assignment operator, copy assignment
void write(char c){
    if (size == capacity)
    {
        buf[start] = c;
        start+= 1;
        if (start == capacity)
        {
            start = 0;
        }
    }
    else
    {
        buf[start + size % capacity] = c;
        size++;
    }
} // write a character to the buffer
void write(string s)
{
    for(char c:s){
        write(c);
    }
}

 // write a string of characters to the buffer
char read(){
    if (size == 0)
    {
        throw "Tom buffer!";
    }
    char c = buf[start++];
    if (start == capacity)
    {
        start = 0;
    }
    size--;
    return c; 
} // read a char from the buffer
string read(int count){
    if (count > capacity || count == 1)
    {
        count = capacity;
        
    }
    string s;
    for (int i = 0; i < count; i++)
    {
        s+= read();
    }
    return s;
    
} // read a number of chars from the buffer
string peek(){
    string s;
    for (int i = start; i < start + size; i++)
    {
        s += buf[i % capacity];
        
    }
    return s;
}
friend void testRingBuf(){
    
}
}; 