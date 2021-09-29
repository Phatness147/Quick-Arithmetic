#include <iostream>
#include <sstream>
#include "4arithmeticH.h"
#include "5memoryE.h"
#include "6memoryM.h"
#include "7memoryH.h"
#include "8memoryVH.h"
#include "9fluencydrill.h"

using namespace std;

// g++ 1menu.cpp 2arithmeticE.cpp 3arithmeticM.cpp 4arithmeticH.cpp 5memoryE.cpp 6memoryM.cpp 7memoryH.cpp 8memoryVH.cpp 9fluencydrill.cpp

string check(string& s, istringstream& i, int& data, int lower, int upper, bool b)
{
    while ((s != "b" || b) && (s.find(' ') != s.npos || !(i >> data) || data < lower || data > upper)) {
        cout << "Invalid input. Try again: ";
        getline(cin, s);
        i.clear();
        i.str(s);
    }
    i.clear();
    return s;
}
int main() 
{    
    bool first = true;
    while (true) {

        // greetings
        if (first) {
            cout << "Welcome to Phat Math Games!" << endl;
            cout << "Type the number that corresponds to the game you want to play." << endl;
            cout << "Type 0 to exit the program." << endl;
        }

        menu:
        cout << endl;
        cout << "1: Arithmetic Practice" << endl;
        cout << "2: Memory Exercises" << endl;
        cout << "3: Fluency Drill" << endl;

        // user input
        cout << "Enter number: ";
        string s;
        int x;
        istringstream i;
        getline(cin, s);
        i.str(s);
        check(s, i, x, 0, 3, true);
        if (x == 0) {
            cout << "Bye!" << endl;
            break;
        }
        else if (x == 1) {
            cout << endl << "Choose a difficulty level: " << endl;

            // display difficulty levels
            cout << "1: Easy" << endl;
            cout << "2: Medium" << endl; 
            cout << "3: Hard" << endl;

            cout << "Enter number: ";
            int difficulty;
            getline(cin, s);
            i.str(s);
            if ("b" == check(s, i, difficulty, 1, 3, false)) goto menu;
            if (difficulty == 1) arithmetic1(); 
            else if (difficulty == 2) arithmetic2();
            else arithmetic3();
        }
        else if (x == 2) {
            cout << endl << "Choose a game: " << endl;
            // display the games
            cout << "1: Wire Connecting (Easy)" << endl;
            cout << "2: Tree Recall (Medium)" << endl;
            cout << "3: Phone Number (Hard)" << endl;
            cout << "4: Class Room Memorization (Very Hard)" << endl;

            cout << "Enter number: ";
            int game;
            getline(cin, s);
            i.str(s);
            if ("b" == check(s, i, game, 1, 4, false)) goto menu;
            cout << endl;
            if (game == 1) memory1();
            else if (game == 2) memory2();
            else if (game == 3) memory3();
            else memory4();
        }
        else if (x == 3) {
            fluencydrill();
        }
    first = false;
    cout << endl;
    }
    return 0;
}