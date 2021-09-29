#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))

using namespace std;
typedef vector<string> vs;

class Node {
    private:
        bool left;
        bool right;
        int left1;
        int right1;
        Node* ln = nullptr;
        Node* rn = nullptr;
        public:
        void sl(int a)
        {
            left = a;
        }
        void sr(int b)
        {
            right = b;
        }
        int gl()
        {
            return left;
        }
        int gr()
        {
            return right;
        }
        void sl1(int c)
        {
            left1 = c;
        }
        void sr1(int c)
        {
            right1 = c;
        }
        int gl1()
        {
            return left1;
        }
        int gr1()
        {
            return right1;
        }
        void sln(Node& l)
        {
            ln = &l;
        }
        void srn(Node& r)
        {
            rn = &r;
        }
};

string::size_type width2(const vs& v)
{
    string::size_type maxlen = 0;

    for (vs::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());

    return maxlen;
}

vs hcat2(const vs& left, const vs& right)
{
    vs ret;
    string::size_type width1 = width2(left);
    
    vs::size_type i = 0, j = 0;

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


vs vcat(const vs& top, const vs& bottom)
{
    vs ret = top;
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;
}

class Tree {
    public:
        Node* head = nullptr;
        vs display;
        void simulate()
        {
            // connect the nodes
            Node one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen;
            one.sl(rand() % 2);
            one.sr(rand() % 2);
            two.sl(rand() % 2);
            two.sr(rand() % 2);
            three.sl(rand() % 2);
            three.sr(rand() % 2);
            four.sl(rand() % 2);
            four.sr(rand() % 2);
            five.sl(rand() % 2);
            five.sr(rand() % 2);
            six.sl(rand() % 2);
            six.sr(rand() % 2);
            seven.sl(rand() % 2);
            seven.sr(rand() % 2);
            one.sl1(0);
            one.sr1(0);
            two.sl1(0);
            two.sr1(0);
            three.sl1(0);
            three.sr1(0);
            four.sl1(0);
            four.sr1(0);
            five.sl1(0);
            five.sr1(0);
            six.sl1(0);
            six.sr1(0);
            seven.sl1(0);
            seven.sr1(0);
            one.sln(two);
            one.srn(three);
            two.sln(four);
            two.srn(five);
            three.sln(six);
            three.srn(seven);
            four.sln(eight);
            four.srn(nine);
            five.sln(ten);
            five.srn(eleven);
            six.sln(twelve);
            six.srn(thirteen);
            seven.sln(fourteen);
            seven.srn(fifteen);
            head = &one;

            cout << "You have fifteen seconds to memorize the following tree. Get ready!" << endl;
            sleep(3);
            display = render(one.gl(), one.gr(), two.gl(), two.gr(), three.gl(), three.gr(), four.gl(), four.gr(), five.gl(), five.gr(), six.gl(), six.gr(), seven.gl(), seven.gr());  
            vs original = display;
            show(); 
            for (int i = 15; i > 0; i--) {
                cout << i << endl;
                sleep(1);
            }            
            for (int i = 0; i < 200; i++) cout << "..." << endl;

            display = render(one.gl1(), one.gr1(), two.gl1(), two.gr1(), three.gl1(), three.gr1(), four.gl1(), four.gr1(), five.gl1(), five.gr1(), six.gl1(), six.gr1(), seven.gl1(), seven.gr1());   
            show();
            sleep(3);
            cout << "The game will autoselect nodes. There is no undo button in this game! The selected node is marked with an o." << endl;
            sleep(3);
            cout << "You must recall whether or not the chosen node has no branches, a left branch, a right branch, or both." << endl;
            sleep(3);
            cout << "1 corresponds with yes. 0 corresponds with no. Enter 2 to return to the menu." << endl;
            sleep(3);

            // create ordering of autoselection
            int nums[7];
            nums[0] = rand() % 7 + 1;
            do nums[1] = rand() % 7 + 1;
            while (nums[1] == nums[0]);
            do nums[2] = rand() % 7 + 1;
            while (nums[2] == nums[1] || nums[2] == nums[0]);
            do nums[3] = rand() % 7 + 1;
            while (nums[3] == nums[2] || nums[3] == nums[1] || nums[3] == nums[0]);
            do nums[4] = rand() % 7 + 1;
            while (nums[4] == nums[3] || nums[4] == nums[2] || nums[4] == nums[1] || nums[4] == nums[0]);
            do nums[5] = rand() % 7 + 1;
            while (nums[5] == nums[4] || nums[5] == nums[3] || nums[5] == nums[2] || nums[5] == nums[1] || nums[5] == nums[0]);
            do nums[6] = rand() % 7 + 1; 
            while (nums[6] == nums[5] || nums[6] == nums[4] || nums[6] == nums[3] || nums[6] == nums[2] || nums[6] == nums[1] || nums[6] == nums[0]);

            for (int i = 0; i < 7; i++) {
                deOrselect(nums[i], display, 'o');
                show();

                Node* n = nullptr;
                switch (nums[i]) {
                    case 1:
                        n = &one;
                        break;
                    case 2:
                        n = &two;
                        break;
                    case 3:
                        n = &three;
                        break;
                    case 4:
                        n = &four;
                        break;
                    case 5:
                        n = &five;
                        break;
                    case 6:
                        n = &six;
                        break;
                    default:
                        n = &seven;
                        break;
                }

                // get user left input
                cout << "Does the selected node have a left branch: ";
                int x;
                cin >> x;
                while (x < 0 || x > 2) {
                    cout << "Invalid input. Try again: ";
                    cin >> x;
                }
                if (x == 2) {
                    cout << "Returning to menu...";
                    sleep(3);
                    return;
                }
                n->sl1(x);
                display = render(one.gl1(), one.gr1(), two.gl1(), two.gr1(), three.gl1(), three.gr1(), four.gl1(), four.gr1(), five.gl1(), five.gr1(), six.gl1(), six.gr1(), seven.gl1(), seven.gr1());
                deOrselect(nums[i], display, 'o');
                show();

                cout << "Does the selected node have a right branch: ";
                int y;
                cin >> y;
                while (y < 0 || y > 2) {
                    cout << "Invalid input. Try again: ";
                    cin >> y;
                }
                if (y == 2) {
                    cout << "Returning to menu...";
                    sleep(3);
                    return;
                }
                n->sr1(y);
                display = render(one.gl1(), one.gr1(), two.gl1(), two.gr1(), three.gl1(), three.gr1(), four.gl1(), four.gr1(), five.gl1(), five.gr1(), six.gl1(), six.gr1(), seven.gl1(), seven.gr1());
                show();
                deOrselect(nums[i], display, 'x');
            }

            cout << "Submitting results...";
            sleep(3);
            int count = 0;
            if (one.gl() == one.gl1()) count++;
            if (one.gr() == one.gr1()) count++;
            if (two.gl() == two.gl1()) count++;
            if (two.gr() == two.gr1()) count++;
            if (three.gl() == three.gl1()) count++;
            if (three.gr() == three.gr1()) count++;
            if (four.gl() == four.gl1()) count++;
            if (four.gr() == four.gr1()) count++;
            if (five.gl() == five.gl1()) count++;
            if (five.gr() == five.gr1()) count++;
            if (six.gl() == six.gl1()) count++;
            if (six.gr() == six.gr1()) count++;
            if (seven.gl() == seven.gl1()) count++;
            if (seven.gr() == seven.gr1()) count++;
            
            if (count == 14) {
                cout << "You got a %100! Returning to menu..." << endl;
                sleep(3);
            }
            else {
                cout << "Your grade is %" << 100.0 * count / 14 << endl;
                cout << "Here is how you remembed the tree..." << endl;
                sleep(3);
                show();
                cout << "Here is how it is supposed to be..." << endl;
                sleep(3);
                display = original;
                show();
                cout << "Returning to menu..." << endl;
                sleep(3);
            }
        }
            
        vs render(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n)
        {
            vs twenty1;
            if (a) {
                twenty1.push_back("                     x");
                twenty1.push_back("                    / ");
                twenty1.push_back("                   /  ");
                twenty1.push_back("                  /   ");
                twenty1.push_back("                 /    ");
                twenty1.push_back("                /     ");
                twenty1.push_back("               /      ");
                twenty1.push_back("              /       ");
                twenty1.push_back("             /        ");
                twenty1.push_back("            /         ");
                twenty1.push_back("           /          ");
            } else {
                twenty1.push_back(string(21, ' ') + "x");
                for (int i = 0; i < 10; i++) twenty1.push_back(string(22, ' '));
            }
            
            vs twentyone1;
            if (b) {
                twentyone1.push_back("                     ");
                twentyone1.push_back("\\                    ");
                twentyone1.push_back(" \\                   ");
                twentyone1.push_back("  \\                  ");
                twentyone1.push_back("   \\                 ");
                twentyone1.push_back("    \\                ");
                twentyone1.push_back("     \\               ");
                twentyone1.push_back("      \\              ");
                twentyone1.push_back("       \\             ");
                twentyone1.push_back("        \\            ");
                twentyone1.push_back("         \\           ");
            } else for (int i = 0; i < 11; i++) twentyone1.push_back(string(21, ' '));

            vs left2;
            left2.push_back("     x");
            left2.push_back("    / ");
            left2.push_back("   /  ");
            left2.push_back("  |   ");
            left2.push_back("  |   ");
            left2.push_back("  |   ");
            left2.push_back(" /    ");
            left2.push_back("/     ");

            vs left3;
            left3.push_back("     x");
            for (int i = 0; i < 7; i++) left3.push_back("      ");

            vs right2;
            right2.push_back("      ");
            right2.push_back("\\     ");
            right2.push_back(" \\    ");
            right2.push_back("  |   ");
            right2.push_back("  |   ");
            right2.push_back("  |   ");
            right2.push_back("   \\  ");
            right2.push_back("    \\ ");

            vs right3;
            for (int i = 0; i < 8; i++) right3.push_back("      ");

            vs thirteen1;
            if (c) thirteen1 = left2;
            else thirteen1 = left3;

            vs fourteen1;
            if (d) fourteen1 = right2;
            else fourteen1 = right3;

            vs seventeen1;
            if (e) seventeen1 = left2; 
            else seventeen1 = left3;

            vs eighteen1;
            if (f) eighteen1 = right2;
            else eighteen1 = right3;

            vs left4;
            left4.push_back("    x");
            left4.push_back("   / ");
            left4.push_back("  |  ");
            left4.push_back("  |  ");
            left4.push_back("  |  ");
            left4.push_back("  |  ");
            left4.push_back("  |  ");
            left4.push_back(" /   ");
            left4.push_back("x    ");

            vs left5;
            left5.push_back("    x");
            for (int i = 0; i < 7; i++) left5.push_back("     ");
            left5.push_back("x    ");

            vs right4;
            right4.push_back("    ");
            right4.push_back("\\   ");
            right4.push_back(" |  ");
            right4.push_back(" |  ");
            right4.push_back(" |  ");
            right4.push_back(" |  ");
            right4.push_back(" |  ");
            right4.push_back("  \\ ");
            right4.push_back("   x");

            vs right5;
            for (int i = 0; i < 8; i++) right5.push_back("    ");
            right5.push_back("   x");

            vs one1;
            if (g) one1 = left4;
            else one1 = left5;

            vs two1;
            if (h) two1 = right4;
            else two1 = right5;

            vs four1;
            if (i) four1 = left4;
            else four1 = left5;

            vs five1;
            if (j) five1 = right4;
            else five1 = right5;

            vs seven1;
            if (k) seven1 = left4;
            else seven1 = left5;

            vs eight1;
            if (l) eight1 = right4;
            else eight1 = right5;

            vs ten1;
            if (m) ten1 = left4;
            else ten1 = left5;

            vs eleven1;
            if (n) eleven1 = right4;
            else eleven1 = right5;

            vs three1;
            for (int i = 0; i < 9; i++) three1.push_back("   ");

            vs six1;
            for (int i = 0; i < 9; i++) six1.push_back(" ");

            vs nine1 = three1;

            vs twelve1;
            for (int i = 0; i < 8; i++) twelve1.push_back("     ");

            vs fifteen1 = twelve1;

            vs sixteen1 = fifteen1;

            vs nineteen1;
            for (int i = 0; i < 8; i++) nineteen1.push_back("    ");

            display = hcat2(one1, two1);
            display = hcat2(display, three1);
            display = hcat2(display, four1);
            display = hcat2(display, five1);
            display = hcat2(display, six1);
            display = hcat2(display, seven1);
            display = hcat2(display, eight1);
            display = hcat2(display, nine1);
            display = hcat2(display, ten1);
            display = hcat2(display, eleven1);
            display = vcat(hcat2(hcat2(hcat2(hcat2(hcat2(hcat2(hcat2(twelve1, thirteen1), fourteen1), fifteen1), sixteen1), seventeen1), eighteen1), nineteen1), display);
            display = vcat(hcat2(twenty1, twentyone1), display);

            return display;
        }

        void deOrselect(int n, vs& d, char c) {
            switch (n) {
                case 1:
                    d[0][21] = c;
                    break;
                case 2:
                    d[11][10] = c;
                    break;
                case 3:
                    d[11][32] = c;
                    break;
                case 4:
                    d[19][4] = c;
                    break;
                case 5:
                    d[19][16] = c;
                    break;
                case 6:
                    d[19][26] = c;
                    break;
                default:
                    d[19][38] = c;
                    break;
            }
        }

        void show() 
        {
            for (int i = 0; i < 28; i++) cout << display[i] << endl;
        }

};

void memory2()
{   
    srand(time(NULL));
    Node one;
    Tree t;
    t.simulate();
    return;
}

