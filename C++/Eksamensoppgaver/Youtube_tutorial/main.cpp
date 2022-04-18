
#include "Figure.h"
#include "Simple_window.h"

int main()
{
	
	const Point tl{0,0};
	constexpr int xmax = 1000;
	constexpr int ymax = 600;
	const string win_label{"Lines"};
	Simple_window win{tl, xmax, ymax, win_label};
	linje lin{Point{0,0}, Point{80,80}};
	lin.attach_to(win);

	keep_window_open();
}

/*
#include "std_lib_facilities.h"
int main() 
{ 
    // Get the string 
    string str = "11, 21, 31, 41, 51, 61"; 
  
    vector<int> v; 
  
    // Get the string to be taken 
    // as input in stringstream 
    stringstream ss(str); 
  
    // Parse the string 
    for (int i; ss >> i;) { 
        v.push_back(i); 
        if (ss.peek() == ',') {
			ss.ignore();
		}
             
    } 
  
    // Print the words 
    for (size_t i = 0; i < v.size(); i++){
		cout << v[i] << endl; 
	} 
        	
	keep_window_open();
  
} 
*/
