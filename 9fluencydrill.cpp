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
#include "9fluencydrill.h"

using namespace std;

Node* create()
{
    Node* test = new Node[100];
    for (int i = 0; i < 100; i++) {
        Node& n = test[i];
        n.first = rand() % 12 + 1;
        n.second = rand() % n.first + 1;
        n.operation = rand() % 4;
        switch (n.operation) {
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
    }
    return test;
}

char getOp(int n)
{
    switch (n) {
        case 0:
            return '+';
        case 1:
            return '-';
        case 2:
            return 'x';
        default:
            return '/';
    }
}

void fluency(int& end, int& correct)
{
    srand(time(NULL));
    Node* test = create();
    cout << "Solve 100 arithmetic problems as fast as you can. Get ready!" << endl;
    sleep(1);
    for (int i = 3; i > 0; i--) {
        cout << i << endl;
        sleep(1);
    }
    int i = 0;
    istringstream iss;
    string s;
    while (i != 100) {
        Node& n = test[i];
        char c = getOp(n.operation);
        bool f = true;  
        do {
            if (!f) cout << "Invalid input. Try again." << endl;
            f = false;
            cout << n.first << " " << c << " " << n.second << " = ";
            getline(cin, s);
            if (s == "e") {
                end = 2;
                return;
            }
            if (s == "-" && i != 0) {
                if (test[i - 1].attempt == test[i - 1].answer) correct--;
                i -= 2;
                break;
            }
            iss.clear();
            iss.str(s);
        } while (s.find(' ') != s.npos || !(iss >> n.attempt));
        iss.clear();
        if (n.attempt == n.answer) correct++;
        i++;
    }
    end = 1;
    return;
}

void fluencydrill()
{   
    int end = 0, correct = 0, time = 0;
    thread t(fluency, ref(end), ref(correct));
    while (end != 1)
    {
        if (end == 2) {
            t.detach();
            cout << "Returning to menu..." << endl;
            sleep(3);
            return;
        }
        sleep(1);
        time++;
    }
    cout << "Your grade is "<< correct << "%" << " in " << time << " seconds" << endl;
    t.detach();
    cout << "Returning to menu..." << endl;
    sleep(3);
    return;
}