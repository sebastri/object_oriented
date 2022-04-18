#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
template<typename T>
void shuffle(std::vector<T>& vec){
    for (size_t i = 0; i < vec.size()-1; i++)
    {
        int j = rand()% (vec.size()-1);
        swap(vec[i], vec[i+j]);
    }
    
}
*/

template<typename T>
void shuffle(vector<T>& vec){
	for (size_t i = 0; i < vec.size() - 1; i++){
      int j = rand() % (vec.size()- i);
      swap(vec[i], vec[i+j]);
	}
}
template<typename T>
T maximum(T a, T b){

    if (a > b){
        return a;
    }
    return b;
    
}




void testTemplate(){
    srand(time(nullptr));
    /*
    int a = 1;
    int b = 2;
    int c = maximum(a, b);

    cout << c << endl;

    // c er nå 2.
    double d = 2.4;
    double e = 3.2;
    double f = maximum(d,e);

    cout << f << endl;
    */
    
    vector<int> a{1,2,3,4,5,6,7};
	shuffle(a);

    for (auto x : a) {
		cout << x << " ";
	}
	cout << '\n';

	vector<double> b{1.1, 2.2, 3.3, 4.4};
	shuffle(b);
    for (auto x : b) {
		cout << x << " ";
	}
	cout << '\n';

	vector<string> c{"one", "two", "three", "four"};
	shuffle(c);
	for (const auto& x : c){
		cout << x << " ";
	}
	cout << "\n\n";

}