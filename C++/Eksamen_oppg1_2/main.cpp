//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"

/*
class X
{
	int i;
    public:
    X(int a=0) : i(a){ 
		
	}
	~X();

};
*/
/*
struct LaundryPile {
	float sizeInKiloGrams;
	
};

LaundryPile operator+(LaundryPile vs, LaundryPile hs){
	LaundryPile tot;
	tot += vs.sizeInKiloGrams + hs.sizeInKiloGrams;
	return tot;
}
*/

class C{
    int num;
    public:
    template <typename T>
    T set_num(T x)
    {
        num = x;
    }
};

/*
vector<int> read(string filename){
	ifstream ist{filename};
	vector<int> numbers;
	string number;
	while (getline(ist, number, ',')){
		numbers.push_back(stoi(number));

	}
	return numbers;
}
stoi("1")
*/

// C++ programs start by executing the function main
int main()
{
	/*
	X* i = new X[100];
	delete [] i;
	*/
	/*
	read("test.txt");
	*/
	C i;
	i.set_num(4.1);
	keep_window_open();
}

//------------------------------------------------------------------------------
