#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string word;
    Node* next;
    Node(string w) {
        word = w;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void insert(string w) {
        Node* n = new Node(w);
        n->next = head;
        head = n;
    }

    bool search(string w) {
        Node* curr = head;
        while (curr) {
            if (curr->word == w) return true;
            curr = curr->next;
        }
        return false;
    }

    void print() {
        Node* curr = head;
        while (curr) {
            cout << curr->word << " -> ";
            curr = curr->next;
        }
        cout << "NULL";
    }
};

class HashTable {
private:
    LinkedList* table;
    int size;

    int hashFunction(string s) {
        int sum = 0;
        for (int i = 0 ; i < s.length() ; i++){
            sum += int(s[i]);
        }
        return sum % size;
    }

public:
    HashTable(int s) {
        size = s;
        table = new LinkedList[size];
    }

    void Add_Record(string w) {
        int index = hashFunction(w);
        table[index].insert(w);
    }

    void Word_Search(string w) {
        int index = hashFunction(w);
        if (table[index].search(w))
            cout << "Word Found\n";
        else
            cout << "Word Not Found\n";
    }

    void Print_Dictionary() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            table[i].print();
            cout << endl;
        }
    }
};

int main() {
    HashTable dict(100);

    dict.Add_Record("apple");
    dict.Add_Record("banana");
    dict.Add_Record("cat");
    dict.Add_Record("dog");
    dict.Add_Record("zebra");

    dict.Print_Dictionary();

    dict.Word_Search("cat");
    dict.Word_Search("mango");

    return 0;
}
