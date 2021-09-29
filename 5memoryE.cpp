#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))

using namespace std;
typedef vector<string> vs;

class Node {
    private:
        int number;
        int point;
        Node* next = nullptr;
    public:
        void sn(int n)
        {
            number = n;
        }
        int gn()
        {
            return number;
        }
        void sp(int p)
        {
            point = p;
        }
        int gp()
        {
            return point;
        }
        void sN(Node& ne)
        {
            next = &ne;
        }
        Node* gN()
        {
            return next;
        }
};

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;

    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());

    return maxlen;
}

vs hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;
    string::size_type width1 = width(left) + 1;
    
    vector<string>::size_type i = 0, j = 0;

    while (i != left.size() || j != right.size()) {
        string s;

        if (i != left.size())
            s = left[i++];
        
        s += string(width1 - s.size(), ' ');

        if (j != right.size())
            s += right[j++];

        ret.push_back(s);
    }
    return ret;
}

void show(const vector<string>& test)
{
    for (int i = 0; i < 7; i++) cout << test[i] << endl;
}

int getInput()
{
    string s;
    int num;
    istringstream i;
    bool f = false;
    do {
        if (f) cout << "Invalid input. Try again: ";
        f = true;
        getline(cin, s);
        i.clear();
        i.str(s);
    } while (s.find(' ') != s.npos || !(i >> num) || num < 0 || num > 4);
    return num;
}

vs select(int x)
{
    // create the four node selections
    vs first;
    first.push_back("o");
    first.push_back(" ");
    first.push_back("x");
    first.push_back(" ");
    first.push_back("x");
    first.push_back(" ");
    first.push_back("x");

    vs second;
    second.push_back("x");
    second.push_back(" ");
    second.push_back("o");
    second.push_back(" ");
    second.push_back("x");
    second.push_back(" ");
    second.push_back("x");

    vs third;
    third.push_back("x");
    third.push_back(" ");
    third.push_back("x");
    third.push_back(" ");
    third.push_back("o");
    third.push_back(" ");
    third.push_back("x");

    vs fourth;
    fourth.push_back("x");
    fourth.push_back(" ");
    fourth.push_back("x");
    fourth.push_back(" ");
    fourth.push_back("x");
    fourth.push_back(" ");
    fourth.push_back("o");

    if (x == 1) return first;
    else if (x == 2) return second;
    else if (x == 3) return third;
    else return fourth;
}

vs getConnector(int x, int y) {
    
    // create connectors
    vs one_one;
    one_one.push_back("---");
    one_one.push_back("   ");
    one_one.push_back("   ");
    one_one.push_back("   ");
    one_one.push_back("   ");
    one_one.push_back("   ");
    one_one.push_back("   ");

    vs one_two;
    one_two.push_back("-| ");
    one_two.push_back(" | ");
    one_two.push_back(" |-");
    one_two.push_back("   ");
    one_two.push_back("   ");
    one_two.push_back("   ");
    one_two.push_back("   ");
        
    vs one_three;
    one_three.push_back("-| ");
    one_three.push_back(" | ");
    one_three.push_back(" | ");
    one_three.push_back(" | ");
    one_three.push_back(" |-");
    one_three.push_back("   ");
    one_three.push_back("   ");
        
    vs one_four;
    one_four.push_back("-| ");
    one_four.push_back(" | ");
    one_four.push_back(" | ");
    one_four.push_back(" | ");
    one_four.push_back(" | ");
    one_four.push_back(" | ");
    one_four.push_back(" |-");
        
    vs two_one;
    two_one.push_back(" |-");
    two_one.push_back(" | ");
    two_one.push_back("-| ");
    two_one.push_back("   ");
    two_one.push_back("   ");
    two_one.push_back("   ");
    two_one.push_back("   ");
        
    vs two_two;
    two_two.push_back("   ");
    two_two.push_back("   ");
    two_two.push_back("---");
    two_two.push_back("   ");
    two_two.push_back("   ");
    two_two.push_back("   ");
    two_two.push_back("   ");
        
    vs two_three;
    two_three.push_back("   ");
    two_three.push_back("   ");
    two_three.push_back("-| ");
    two_three.push_back(" | ");
    two_three.push_back(" |-");
    two_three.push_back("   ");
    two_three.push_back("   ");
        
    vs two_four;
    two_four.push_back("   ");
    two_four.push_back("   ");
    two_four.push_back("-| ");
    two_four.push_back(" | ");
    two_four.push_back(" | ");
    two_four.push_back(" | ");
    two_four.push_back(" |-");
        
    vs three_one;
    three_one.push_back(" |-");
    three_one.push_back(" | ");
    three_one.push_back(" | ");
    three_one.push_back(" | ");
    three_one.push_back("-| ");
    three_one.push_back("   ");
    three_one.push_back("   ");
        
    vs three_two;
    three_two.push_back("   ");
    three_two.push_back("   ");
    three_two.push_back(" |-");
    three_two.push_back(" | ");
    three_two.push_back("-| ");
    three_two.push_back("   ");
    three_two.push_back("   ");
        
    vs three_three;
    three_three.push_back("   ");
    three_three.push_back("   ");
    three_three.push_back("   ");
    three_three.push_back("   ");
    three_three.push_back("---");
    three_three.push_back("   ");
    three_three.push_back("   ");
        
    vs three_four;
    three_four.push_back("   ");
    three_four.push_back("   ");
    three_four.push_back("   ");
    three_four.push_back("   ");
    three_four.push_back("-| ");
    three_four.push_back(" | ");
    three_four.push_back(" |-");
        
    vs four_one;
    four_one.push_back(" |-");
    four_one.push_back(" | ");
    four_one.push_back(" | ");
    four_one.push_back(" | ");
    four_one.push_back(" | ");
    four_one.push_back(" | ");
    four_one.push_back("-| ");
        
    vs four_two;
    four_two.push_back("   ");
    four_two.push_back("   ");
    four_two.push_back(" |-");
    four_two.push_back(" | ");
    four_two.push_back(" | ");
    four_two.push_back(" | ");
    four_two.push_back("-| ");
        
    vs four_three;
    four_three.push_back("   ");
    four_three.push_back("   ");
    four_three.push_back("   ");
    four_three.push_back("   ");
    four_three.push_back(" |-");
    four_three.push_back(" | ");
    four_three.push_back("-| ");
        
    vs four_four;
    four_four.push_back("   ");
    four_four.push_back("   ");
    four_four.push_back("   ");
    four_four.push_back("   ");
    four_four.push_back("   ");
    four_four.push_back("   ");
    four_four.push_back("---");

    // choose connector
    if (x == 1 && y == 1) return one_one;
    else if (x == 1 && y == 2) return one_two;
    else if (x == 1 && y == 3) return one_three;
    else if (x == 1 && y == 4) return one_four;
    else if (x == 2 && y == 1) return two_one;
    else if (x == 2 && y == 2) return two_two;
    else if (x == 2 && y == 3) return two_three;
    else if (x == 2 && y == 4) return two_four;
    else if (x == 3 && y == 1) return three_one;
    else if (x == 3 && y == 2) return three_two;
    else if (x == 3 && y == 3) return three_three;
    else if (x == 3 && y == 4) return three_four;
    else if (x == 4 && y == 1) return four_one;
    else if (x == 4 && y == 2) return four_two;
    else if (x == 4 && y == 3) return four_three;
    else return four_four;
}

void memory1()
{
    srand(time(NULL));

    int num = 0;
    int point = 0;

    // Node Creation
    Node one, two, three, four, five, six;

    // create node one
    one.sn(rand() % 4 + 1);
    one.sp(rand() % 4 + 1);
    one.sN(two);
    
    // create node two
    two.sn(one.gp());
    two.sp(rand() % 4 + 1);
    two.sN(three);

    // create node three
    three.sn(two.gp());
    three.sp(rand() % 4 + 1);
    three.sN(four);

    // create node four
    four.sn(three.gp());
    four.sp(rand() % 4 + 1);
    four.sN(five);

    // create node five
    five.sn(four.gp());
    five.sp(rand() % 4 + 1);
    five.sN(six);

    // create node six
    six.sn(five.gp());
    
    // create test
    vs test;

    vs number;
    number.push_back("1 ");
    number.push_back("  ");
    number.push_back("2 ");
    number.push_back("  ");
    number.push_back("3 ");
    number.push_back("  ");
    number.push_back("4 ");

    test = number;

    vs column;
    column.push_back("x");
    column.push_back(" ");
    column.push_back("x");
    column.push_back(" ");
    column.push_back("x");
    column.push_back(" ");
    column.push_back("x");
    
    test = hcat(test, select(one.gn()));

    Node* curr = &one;
    while (curr->gN() != nullptr) {
        test = hcat(test, getConnector(curr->gn(), curr->gp()));
        test = hcat(test, select(curr->gN()->gn()));
        curr = curr->gN();
    }

    cout << "You have ten second to remember the path of the wires. Get Ready!" << endl;
    sleep(3);
    show(test);

    vector<string> original = test;

    for (int i = 10; i > 0; i--) {
        cout << i << endl;
        sleep(1);
    }

    for (int i = 0; i < 200; i++) cout << "..." << endl;

    cout << endl;

    vs empty;
    empty.push_back("   ");
    empty.push_back("   ");
    empty.push_back("   ");
    empty.push_back("   ");
    empty.push_back("   ");
    empty.push_back("   ");
    empty.push_back("   ");

    test.clear();
    test = hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(number, column), empty), column), empty), column), empty), column), empty), column), empty), column);
    
    show(test);
    int count;

    // intro
    cout << "Enter a number between [1, 4] to choose the location of the wire." << endl;
    cout << "Enter 0 to undo." << endl;

    bool notFirst = false;

    // 1
    first:
    if (notFirst) {
        test.clear();
        test = hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(number, column), empty), column), empty), column), empty), column), empty), column), empty), column);
        show(test);
    }
    cout << "Which node did the wire begin: ";
    int num1 = getInput();
    while (num1 == 0) {
        cout << "You cannot undo at the start. Try again: " << endl;
        num1 = getInput();
    }
    if (num1 == one.gn()) count++;
    notFirst = true;

    // 2
    second:
    test.clear();
    test = hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(number, select(num1)), empty), column), empty), column), empty), column), empty), column), empty), column);
    show(test);
    cout << "What was the second node: ";
    int num2 = getInput();
    if (num2 == two.gn()) count++;
    else if (num2 == 0) {
        if (num1 == one.gn()) count--;
        goto first;
    }

    // 3
    third:
    test.clear();
    test = hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(number, select(num1)), getConnector(num1, num2)), select(num2)), empty), column), empty), column), empty), column), empty), column);
    show(test);
    cout << "What was the third node: ";
    int num3 = getInput();
    if (num3 == three.gn()) count++;
    else if (num3 == 0) {
        if (num2 == two.gn()) count--;
        goto second;
    }

    // 4
    fourth:
    test.clear();
    test = hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(number, select(num1)), getConnector(num1, num2)), select(num2)), getConnector(num2, num3)), select(num3)), empty), column), empty), column), empty), column);
    show(test);
    cout << "What was the fourth node: ";
    int num4 = getInput();
    if (num4 == four.gn()) count++;
    else if (num4 == 0) {
        if (num3 == three.gn()) count--;
        goto third;
    }

    // 5
    fifth:
    test.clear();
    test = hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(number, select(num1)), getConnector(num1, num2)), select(num2)), getConnector(num2, num3)), select(num3)), getConnector(num3, num4)), select(num4)), empty), column), empty), column);
    show(test);
    cout << "What was the fifth node: ";
    int num5 = getInput();
    if (num5 == five.gn()) count++;
    else if (num5 == 0) {
        if (num4 == four.gn()) count--;
        goto fourth;
    }

    // 6
    sixth:
    test.clear();
    test = hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(number, select(num1)), getConnector(num1, num2)), select(num2)), getConnector(num2, num3)), select(num3)), getConnector(num3, num4)), select(num4)), getConnector(num4, num5)), select(num5)), empty), column);
    show(test);
    cout << "What was the last node: ";
    int num6 = getInput();
    if (num6 == six.gn()) count++;
    else if (num6 == 0) {
        if (num5 == five.gn()) count--;
        goto fifth;
    }
    test.clear();
    test = hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(hcat(number, select(num1)), getConnector(num1, num2)), select(num2)), getConnector(num2, num3)), select(num3)), getConnector(num3, num4)), select(num4)), getConnector(num4, num5)), select(num5)), getConnector(num5, num6)), select(num6));
    show(test);
    
    // last call
    cout << "Type 0 if you want to undo." << endl;
    cout << "Type anything else if you want to submit." << endl;
    cout << "Enter: ";
    string s;
    cin >> s;
    if (s == "0") {
        if (num6 == six.gn()) count--;
        goto sixth;
    }
    cin.ignore();
    
    // submit
    cout << "Calculating results...";
    sleep(3);
    if (count != 6) {
        cout << "Your grade is %" << 100.0 * count / 6 << endl;
        cout << "Here is how you connected the wires..." << endl;
        sleep(3);
        show(test);
        cout << "Here is how you are supposed to connect the wires..." << endl;
        sleep(3);
        show(original);
        cout << "Returning to menu..." << endl;
        sleep(3);
        return;
    }
    else {
        cout << "Great job! Your grade is %100!" << endl;
        sleep(1);
        cout << "Returning to menu..." << endl;
        sleep(3);
        return;
    }
}
