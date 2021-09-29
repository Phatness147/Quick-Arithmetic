using namespace std;

class Node {
    public:
        void sguess(int guess) {
            guess_ = guess;
        }
        int gguess() const {
            return guess_;
        }
        void snumber(int number) {
            number_ = number;
        }
        int gnumber() const {
            return number_;
        }
        void spoint(int point) {
            point_ = point;
        }
        int gpoint() const {
            return point_;
        }
        void scorrect(bool correct) {
            correct_ = correct;
        }
        bool gcorrect() const {
            return correct_;
        }
        void snext(Node& next) {
            next_ = &next;
        }
        Node* gnext() const {
            return next_;
        }
        void slast(Node& last) {
            last_ = &last;
        }
        Node* glast() const {
            return last_;
        }
        private:
            int guess_;
            int number_;
            int point_;
            bool correct_;
            Node* next_ = nullptr;
            Node* last_ = nullptr;
};

class LinkedList {
    public:
        LinkedList(Node* h) : head{h} {}
        void display();
    private:
        Node* head;
};

void LinkedList::display()
{

}