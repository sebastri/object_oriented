#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "mastermind.h"
#include "Graph.h"
#include "Simple_window.h"
// Oppgave 1a - 25

int main() {
	using namespace Graph_lib;
	system("chcp 65001 > nul");
	srand(static_cast<unsigned int>(time(nullptr)));

    int x = -1;
	    while (x != 0) {
	    cout << "Velg funksjon:\n";
	    cout << "0) Avslutt\n";
	    cout << "1) testCallByValue\n";
        cout << "2) testCallByReference\n";
		cout << "3) swapNumbers\n";
		cout << "4) testVectorSorting\n";
		cout << "5) testStruct\n";
		cout << "6) testString\n";
		cout << "7) testreadinput\n";
		cout << "8) countChar\n";
		cout << "9) Mastermind\n";
	    cin >> x;
		    switch(x) {
		    case 1:
            testCallByValue();
            break;
            case 2:
            testCallByReference();
            break;
			case 3:{
				int a = 1;
				int b = 2;
			swapNumbers(a,b);
			break;
			}
			case 4:
			testVectorSorting();
			break;
			case 5:
			teststruct();
			break;
			case 6:
			testString();
			break;
			case 7:
			readInputToString(3, 'A', 'F');
			break;
			case 8:
			countChar("AABCA", 'A');
			break;
			case 9:
			playMastermind();
			break;
		    default:
		    cout << "Du skrev inn et ugyldig tall";
		}
    }
	return gui_main();
	
}



