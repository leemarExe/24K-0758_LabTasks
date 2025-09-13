#include <iostream>
using namespace std;

class Node {
public:
    int compartment;
    Node* next;
    Node* prev;

    Node(int c) : compartment(c), next(NULL), prev(NULL) {}
};

class Train {
private:
    Node* head;
    Node* tail;
public:
    Train() : head(NULL), tail(NULL) {}

    void addCompartment(int num) {
        Node* newNode = new Node(num);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void removeFirstCompartment() {
        if (!head) {
            cout << "Train has no compartments\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL; 
        cout << "Removed compartment: " << temp->compartment << endl;
        delete temp;
    }

    void searchCompartment(int num) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->compartment == num) {
                cout << "Compartment " << num << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Compartment " << num << " not found\n";
    }

    void displayTrain() {
        if (!head) {
            cout << "Train is empty\n";
            return;
        }
        Node* temp = head;
        cout << "Train compartments: ";
        while (temp) {
            cout << temp->compartment;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Train t;
    t.addCompartment(101);
    t.addCompartment(102);
    t.addCompartment(103);
    t.addCompartment(104);

    t.displayTrain();

    t.removeFirstCompartment();
    t.displayTrain();

    t.searchCompartment(103);
    t.searchCompartment(999);

    return 0;
}
