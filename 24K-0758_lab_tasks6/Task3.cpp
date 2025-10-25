#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string url;
    Node* next;
    Node(string u) {
        url = u;
        next = NULL;
    }
};

class Stack {
    string arr[100];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    void push(string val) {
        if (topIndex < 99) arr[++topIndex] = val;
    }
    string pop() {
        if (topIndex >= 0) return arr[topIndex--];
        else return "";
    }
    bool empty() {
        return topIndex == -1;
    }
    string top() {
        if (topIndex >= 0) return arr[topIndex];
        else return "";
    }
};

class BrowserHistory {
    Node* head;
public:
    BrowserHistory() { head = NULL; }
    void visit(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
    }
    void goBack(Stack& s, int steps) {
        for (int i = 0; i < steps; i++) {
            if (!s.empty()) {
                s.pop();
                removeFront();
            }
        }
    }
    void removeFront() {
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->url << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    BrowserHistory history;
    Stack stack;

    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (int i = 0; i < 5; i++) {
        history.visit(sites[i]);
        stack.push(sites[i]);
    }

    cout << "Before going back:\n";
    history.display();

    history.goBack(stack, 2);

    cout << "\nAfter going back:\n";
    history.display();

    cout << "\nCurrent page: " << stack.top() << endl;

    return 0;
}
