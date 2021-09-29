#include <string>
#include <vector>

struct node {
        int first;
        int second;
        int answer;
        std::vector<std::string> display;
        int attempt;
        bool correct = false;
};

void introduction();

void show(node test[4][6]);

std::pair<int, int> next(int, int);

void select(node&);

void getAnswer(node&);

void update(node&);

void deselect(node&);

void submit(node test[4][6]);

void timer(bool&);

void arithmetic1();