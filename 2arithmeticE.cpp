#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#include "2arithmeticE.h"

using namespace std;

void introduction()
{
    cout << "Enter a row number between [1, 4]" << endl;
    cout << "Then, enter a column between [1, 6]" << endl;
    cout << "Press the spacebar to autoselect" << endl;
    cout << "If you want to return to the main menu, enter 'e' " << endl;
    cout << "If you want to submit, enter 's' " << endl; 
}

void show(node test[4][6]) 
{
    for (int i = 0; i < 4; i++) { // rows
        for (int j = 0; j < 7; j++) { // strings
            for (int k = 0; k < 6; k++) { // columns
                cout << test[i][k].display[j]; // print the same level string for each column
            }
            cout << endl;
        }
    }
}

pair<int, int> next(int r1, int c1) 
{
    c1++;
    if (c1 == 7) {
        c1 = 1;
        r1++;
    }
    if (r1 == 5) r1 = 1;
    return {r1, c1};
}

void select(node& n) 
{
    char o = n.display[2][4];
    string op = "  ";
    op[0] = o;
    n.display.clear();
    n.display.push_back("xxxxxxxxxxxxx");
    n.display.push_back("x    " + string(2 - to_string(n.first).size(), ' ') + to_string(n.first) + "     x");
    n.display.push_back("x   " + op + to_string(n.second) + "     x");
    n.display.push_back("x  -------  x");
    n.display.push_back("x           x"); 
    n.display.push_back("x           x"); 
    n.display.push_back("xxxxxxxxxxxxx");           
}

void update(node& n)
{   
    string ans = to_string(n.attempt);
    char o = n.display[2][4];
    string op = "  ";
    op[0] = o;
    n.display.clear();
    n.display.push_back("xxxxxxxxxxxxx");
    n.display.push_back("x" + string(6 - to_string(n.first).size(), ' ') + to_string(n.first) + "     x");
    n.display.push_back("x   " + op + to_string(n.second) + "     x");
    n.display.push_back("x  -------  x");
    n.display.push_back("x" + string(6 - ans.size(), ' ') + ans + "     x"); 
    n.display.push_back("x           x"); 
    n.display.push_back("xxxxxxxxxxxxx");           
}

void deselect(node& n) 
{
    string ans = to_string(n.attempt);
    char o = n.display[2][4];
    string op = "  ";
    op[0] = o;
    n.display.clear();
    n.display.push_back("-------------");
    n.display.push_back("|    " + string(2 - to_string(n.first).size(), ' ') + to_string(n.first) + "     |");
    n.display.push_back("|   " + op + to_string(n.second) + "     |");
    n.display.push_back("|  -------  |");
    n.display.push_back("|" + string(6 - ans.size(), ' ') + ans + "     |"); 
    n.display.push_back("|           |"); 
    n.display.push_back("-------------");           
}

void submit(node test[4][6])
{   
    int right = 0;
    float grade;
    vector<node> wrong;

    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 6; c++) {
            node& n = test[r][c];
            if (n.correct) right++;
            else wrong.push_back(n);
        }
    }

    grade = 100.0 * right / 24;
    cout << "Here is your grade: %" + to_string(grade) << endl;

    if (wrong.empty()) {
        cout << "Good Job. Returning to menu...";
        sleep(3);
    }
    else {
        cout << "These are the problem(s) you got wrong with the right answer(s)..." << endl;
        sleep(3);
        for (int i = 0; i < wrong.size(); i++) {
            node& n = wrong[i];
            for (int j = 0; j < 7; j++) {
                if (j == 4) cout << "|" + string(6 - to_string(n.answer).size(), ' ') + to_string(n.answer) + "     |" << endl;
                else cout << n.display[j] << endl;
            }            
        }
        cout << "Enter a anything in the keyboard when you are ready to return to the menu:" << endl;
        string s;
        getline(cin, s);
        cout << "Returning to the menu...";
        sleep(3);
    }
}

void timer(bool& b)
{
    for (int i = 600; i > 0; i--) sleep(1);
    cout << endl << "Times up! Enter a number to submit: ";
    b = true;
}

void arithmetic1(){
    srand(time(NULL));
    
    node test[4][6];
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 6; c++) {
            node& n = test[r][c];
            n.first = rand() % 10;
            do n.second = rand() % 10;
            while (n.second == 0);
            string op;
            if (r == 0) op = "+ ";
            else if (r == 1) op = "- ";
            else if (r == 2) op = "* ";
            else op = "/ ";
            switch (r) {
                case 0:
                    n.answer = n.first + n.second;
                    break;
                case 1:
                    n.answer = n.first - n.second;
                    break;
                case 2:
                    n.answer = n.first * n.second;
                    break;
                default:
                    n.answer = n.first;
                    n.first *= n.second;
                    break;
            }

            n.display.push_back("-------------");
            n.display.push_back("|    " + string(2 - to_string(n.first).size(), ' ') + to_string(n.first) + "     |");
            n.display.push_back("|   " + op + to_string(n.second) + "     |");
            n.display.push_back("|  -------  |");
            n.display.push_back("|           |"); 
            n.display.push_back("|           |"); 
            n.display.push_back("-------------");           
        }
    }
    
    // introduction
    cout << "Welcome to Arithmetic Practice (Easy)." << endl;
    cout << "Complete the following problems in 10 minutes..." << endl;
    sleep(3);

    bool intro = true;
    show(test);
    int r, c;
    int r1 = 1, c1 = 0;
    bool end = false;
    bool f = false;
    thread t(timer, ref(end));
    string s;
    istringstream i;

    // game loop
    while (true) {

        // give rules
        if (intro) {
            introduction();
            intro = false;
        }

        cout << "Enter a row number: ";

        // get user input
        f = false;
        do {
            if (f) cout << "Invalid input. Try again: ";
            f = true;
            s.clear();
            getline(cin, s);
            i.clear();
            i.str(s);
            if (end) {
                t.join();
                submit(test);
                return;
            }
            else if (s == "e") {
                t.detach();
                cout << "Returning to the menu...";
                sleep(3);
                return;
            }
            else if (s == "s") {
                t.detach();
                submit(test);
                return; 
            }    
            else if (s == " ") {
                pair<int, int> p = next(r1, c1); 
                r = p.first;
                c = p.second;
                break;
            }
        } while (s.find(' ') != s.npos || !(i >> r) || r < 1 || r > 4);
        i.clear();

        if (s != " ") {
            cout << "Enter a column number: ";
            f = false;
            do {
                if (f) cout << "Invalid input. Try again: ";
                f = true;
                getline(cin, s);
                i.clear();
                i.str(s);
                if (end) {
                    t.join();
                    submit(test);
                    return;
                }
                else if (s == "e") {
                    t.detach();
                    cout << "Returning to the menu...";
                    sleep(3);
                    return;
                }
                else if (s == "s") {
                    t.detach();
                    submit(test);
                    return;                
                }
                else if (s == " ") {
                    pair<int, int> p = next(r1, c1); 
                    r = p.first;
                    c = p.second;
                    break;
                }
            } while (s.find(' ') != s.npos || !(i >> c) || c < 1 || c > 6);
        }
        
        r1 = r;
        c1 = c;
        r--; 
        c--;
        
        select(test[r][c]);
        show(test);
        cout << "Enter your solution: ";
        int ans;
        f = false;
        do {
            if (f) cout << "Invalid input. Try again: ";
            f = true;
            getline(cin, s);
            i.clear();
            i.str(s);
            if (end) {
                t.join();
                submit(test);
                return;
            }
            else if (s == "e") {
                t.detach();
                cout << "Returning to the menu...";
                sleep(3);
                return;
            }
            else if (s == "s") {
                t.detach();
                submit(test);
                return; 
            }
        } while (s.find(' ') != s.npos || !(i >> ans));
        if (ans == test[r][c].answer) test[r][c].correct = true;
        test[r][c].attempt = ans;        
        update(test[r][c]);
        show(test);
        deselect(test[r][c]);
    }
}