#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string title;
    Node* next;
    Node(string t) : title(t), next(NULL) {}
};

class LibraryCatalog {
private:
    Node* head;
public:
    LibraryCatalog() : head(NULL) {}

    void addBookToTail(string title) {
        Node* newNode = new Node(title);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteBookFromFront() {
        if (!head) {
            cout << "Catalog is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted: " << temp->title << endl;
        delete temp;
    }

    void searchByTitle(string title) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->title == title) {
                cout << "Found \"" << title << "\" at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Book \"" << title << "\" not found\n";
    }

    void searchByPosition(int pos) {
        Node* temp = head;
        int count = 1;
        while (temp) {
            if (count == pos) {
                cout << "Book at position " << pos << ": " << temp->title << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "No book found at position " << pos << endl;
    }

    void display() {
        if (!head) {
            cout << "Catalog is empty\n";
            return;
        }
        Node* temp = head;
        cout << "Library Catalog: ";
        while (temp) {
            cout << temp->title;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LibraryCatalog catalog;

    catalog.addBookToTail("Data Structures");
    catalog.addBookToTail("Operating Systems");
    catalog.addBookToTail("Computer Networks");
    catalog.addBookToTail("Database Systems");

    catalog.display();

    catalog.deleteBookFromFront();
    catalog.display();

    catalog.searchByTitle("Computer Networks");
    catalog.searchByTitle("AI");

    catalog.searchByPosition(2);
    catalog.searchByPosition(10);

    return 0;
}
