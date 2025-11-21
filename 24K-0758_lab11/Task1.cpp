#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(string value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    bool search(string key) {
        Node* curr = head;
        while (curr) {
            if (curr->data == key)
                return true;
            curr = curr->next;
        }
        return false;
    }

    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL";
    }
};

class HashTable {
private:
    LinkedList* table;
    int buckets;

    int hashFunction(string s) {
        int sum = 0;
        for (int i = 0 ; i < s.length() ; i++){
            sum += int(s[i]);
        }
        return sum % buckets;
    }

public:
    HashTable(int b) {
        buckets = b;
        table = new LinkedList[buckets]; 
    }

    void insert(string value) {
        int index = hashFunction(value);
        table[index].insert(value);
    }

    bool search(string key) {
        int index = hashFunction(key);
        return table[index].search(key);
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < buckets; i++) {
            cout << "Bucket " << i << ": ";
            table[i].display();
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(10);

    ht.insert("apple");
    ht.insert("mango");
    ht.insert("grapes");
    ht.insert("peach");
    ht.insert("banana");
    ht.insert("apple");

    ht.display();

    cout << "\nSearching 'apple': " << (ht.search("apple") ? "Found" : "Not Found") << endl;

    cout << "Searching 'orange': " << (ht.search("orange") ? "Found" : "Not Found") << endl;

    return 0;
}
