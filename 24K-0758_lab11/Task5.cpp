#include <iostream>
using namespace std;

class HashTable {
    string table[50];
    int size;

public:
    HashTable() {
        size = 50;
        for (int i = 0; i < size; i++) table[i] = "";
    }

    int sumASCII(string s) {
        int sum = 0;
        for (char c : s) sum += int(c);
        return sum;
    }

    void Add_Employee(string name) {
        int ascii = sumASCII(name);
        int h1 = ascii % size;
        int h2 = 7 - (ascii % 7);

        int index = h1;
        int i = 1;

        while (table[index] != "") {
            index = (h1 + i * h2) % size;
            i++;
            if (i > size) return;
        }
        table[index] = name;
    }

    void Search_Employee(string name) {
        int ascii = sumASCII(name);
        int h1 = ascii % size;
        int h2 = 7 - (ascii % 7);

        int index = h1;
        int i = 1;

        while (table[index] != "") {
            if (table[index] == name) {
                cout << "Employee found at index " << index << endl;
                return;
            }
            index = (h1 + i * h2) % size;
            i++;
            if (i > size) break;
        }

        cout << "Employee not found in the directory." << endl;
    }

    void Display_Table() {
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            if (table[i] == "") cout << "EMPTY";
            else cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.Add_Employee("Ali");
    ht.Add_Employee("Sara");
    ht.Add_Employee("Hassan");
    ht.Add_Employee("Zainab");
    ht.Add_Employee("Hamza");

    cout << "Searching Sara: ";
    ht.Search_Employee("Sara");

    cout << "Searching Umar: ";
    ht.Search_Employee("Umar");

    cout << endl << "Employee Directory:" << endl;
    ht.Display_Table();

    return 0;
}
