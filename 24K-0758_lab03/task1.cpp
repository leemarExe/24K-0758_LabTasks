#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string book;
    Node* next;
    Node(string name) {
        book = name;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void addFront(string name) {
        Node* newNode = new Node(name);
        newNode->next = head;
        head = newNode;
    }

    void addEnd(string name) {
        Node* newNode = new Node(name);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAfter(string target, string name) {
        Node* temp = head;
        while (temp && temp->book != target) temp = temp->next;
        if (!temp) return;
        Node* newNode = new Node(name);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    bool searchBook(string name) {
        Node* temp = head;
        while (temp) {
            if (temp->book == name) return true;
            temp = temp->next;
        }
        return false;
    }

    void displayList() {
        Node* temp = head;
        while (temp) {
            cout << temp->book << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    list.addEnd("Data Structures");
    list.addEnd("Operating Systems");
    list.addEnd("Computer Networks");
    list.addEnd("Database Systems");

    list.addFront("Artificial Intelligence");
    list.addEnd("Machine Learning");
    list.insertAfter("Operating Systems", "Cyber Security");

    if (list.searchBook("Database Systems"))
        cout << "Book 'Database Systems' found!\n";
    else
        cout << "Book 'Database Systems' not found!\n";

    list.displayList();
}
