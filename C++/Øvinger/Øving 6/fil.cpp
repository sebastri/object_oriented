#include "fil.h"


void readToFile(){
    ofstream file;
    file.open("eksempelfil.txt");
    // eller ofstream file{"eksempelfil.txt"};
    string words;
    cout << "Skriv inn ord du vil ha til filen, og skriv inn 'quit' når du er ferdig" << endl;
    bool f = false;
    while (!f){
        cin >> words;
        if (words == "quit"){
            words.clear();
            f = true;
        }
        file << words << endl;
    }
    file.close();
}



void readIn(){
    cout << "Please enter input file name: ";
    string inName;
    cin >> inName;
    ifstream ist{inName};
    if (!ist) error("cant open input file", inName);

    cout << "Please enter name of output file: ";
    string outName;
    cin >> outName;
    ofstream ofs{outName};
    if (!ofs) error("cant open output file", outName);

    string line;
    int lineNumber = 1;
    while(!ist.eof()){
        getline(ist, line);
        if(!line.empty()){
        ofs << lineNumber << ". " << line << endl;
        lineNumber += 1;
        }
    }
}   



void countCharFile(){
    map<char, int> mapalphabet{
        {'a', 0},
        {'b', 0},
        {'c', 0},
        {'d', 0},
        {'e', 0},
        {'f', 0},
        {'g', 0},
        {'h', 0},
        {'i', 0},
        {'j', 0},
        {'k', 0},
        {'l', 0},
        {'m', 0},
        {'n', 0},
        {'o', 0},
        {'p', 0},
        {'q', 0},
        {'r', 0}, 
        {'s', 0},
        {'t', 0},
        {'u', 0},
        {'v', 0},
        {'w', 0},
        {'x', 0},
        {'y', 0},
        {'z', 0},
    };
    cout << "Please enter input file name: ";
    string file;
    cin >> file;
    ifstream ist{file};
    if(!ist) error("cant open this file!",file);
    
    /*
    cout << "Please enter name of output file: ";
    string outName;
    cin >> outName;
    ofstream ofs{outName};
    if (!ofs) error("cant open output file", outName);
    */

    string line;
    while(!ist.eof()){
        getline(ist, line);
        
        for (unsigned int i = 0; i < line.size(); i++){
        line[i] = tolower(line[i]);
        }

        for (char character : line){
            if (mapalphabet.count(character)){
                mapalphabet.at(character) += 1;
            } 
        }

        
    }
    for (auto alphabetkey : mapalphabet){
        cout << alphabetkey.first << ": " << alphabetkey.second << endl;
    }
}