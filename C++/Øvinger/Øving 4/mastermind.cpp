#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "mastermind.h"
#include "masterVisual.h"

void playMastermind(){
    constexpr int size = 4;
    //constexpr int letters = 6; 
    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    string code;
    string guess;
    code += randomizeString(size, 'A', 'F');
    cout << code << "\n";
    int i = 0;
    int j = 0;
    int telle = 0;
    int try1 = 0;
    cout << "Velkommen til Mastermind\n";
    cout << "Hvor mange forsøk vi du ha?\n";
    cin >> try1;
    while (i != size){
        if (try1 == telle){
            break;
        }
        cout << "A=RED, B=GREEN, C=YELLOW, D=BLUE, E=PINK, F=LIGHT BLUE\n";
        guess.clear();
        guess += mwin.getInput(size, 'A', 'F');

        addGuess(mwin, guess, size, 'A', telle);
        
        i = checkCharactersAndPosition(code, guess);
        cout << "Antall riktige bokstaver på rett plass: " << i << "\n";
        j = checkCharacters(code, guess);
        cout << "Antall riktige bokstaver totalt: " << j << "\n"; 
        addFeedback(mwin, i, j, size, telle);
        telle += 1;
    }
    if (i == size){
        cout << "\n\nGratulerer du vant!\n\n";
    }
    else {
        cout << "\n\nDu er tom for forsøk\n\n";
    }
    mwin.redraw();
    
}

int checkCharactersAndPosition(string code, string guess){
    int t = 0;
    for (int i = 0; i < 4; i++)
    {
        if (code[i]==guess[i]){
            t+=1;
        }
    }
    return t;
}

int checkCharacters(string code, string guess){
    int c = 0;
    int g = 0;
    int count = 0;
    for (int i = 0; i < 6; i++){
        c = countChar(code, 'A' + i);
        g = countChar(guess, 'A' + i);
        
        if (c > 0 && g > 0){
            if (c > g){
                count += g;
            }
            else if (c == g){
            count += c;
        }
            else {
                count += c;
            }
        }
        else {
            count += 0;
        }
        
    }
    return count;
}