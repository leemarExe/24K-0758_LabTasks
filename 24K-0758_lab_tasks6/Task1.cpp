#include <iostream>
#include <string>
using namespace std;

class Call {
public:
    string name;
    string number;
    int duration;

    Call() {}
    Call(string n, string num, int d) {
        name = n;
        number = num;
        duration = d;
    }

    void display() const {
        cout << "Name: " << name << ", Number: " << number << ", Duration: " << duration << " min" << endl;
    }
};

class CallStack {
private:
    static const int MAX = 100;
    Call calls[MAX];
    int topIndex;

public:
    CallStack() {
        topIndex = -1;
    }

    bool empty() {
        return topIndex == -1;
    }

    bool full() {
        return topIndex == MAX - 1;
    }

    void push(Call c) {
        if (full()) {
            cout << "Call history is full. Cannot add more calls." << endl;
            return;
        }
        calls[++topIndex] = c;
        cout << "Call added successfully.\n";
        display();
    }

    void pop() {
        if (empty()) {
            cout << "No calls to remove! Call history is empty." << endl;
            return;
        }
        cout << "Removing last call: ";
        calls[topIndex--].display();
        display();
    }

    void top() {
        if (empty()) {
            cout << "No recent calls to show." << endl;
            return;
        }
        cout << "Most Recent Call: ";
        calls[topIndex].display();
    }

    void display() {
        if (empty()) {
            cout << "(No call history)\n";
            return;
        }
        cout << "\nCurrent Call Log (" << topIndex + 1 << " calls):\n";
        for (int i = topIndex; i >= 0; i--) {
            cout << " " << (topIndex - i + 1) << ". ";
            calls[i].display();
        }
        cout << endl;
    }
};

int main() {
    CallStack history;

    Call c1("Ali", "03001234567", 5);
    Call c2("Sara", "03119998877", 3);
    Call c3("Ahmed", "03215556677", 10);

    cout << "Adding three calls:\n";
    history.push(c1);
    history.push(c2);
    history.push(c3);

    cout << "\nShowing most recent call:\n";
    history.top();
    
    cout << "\nRemoving most recent call:\n";
    history.pop();

    cout << "\nChecking if call history is empty:\n";
    if (history.empty())
        cout << "History is empty.\n";
    else
        cout << "There are calls in history.\n";

    cout << "\nFinal call log:\n";
    history.display();

    return 0;
}
