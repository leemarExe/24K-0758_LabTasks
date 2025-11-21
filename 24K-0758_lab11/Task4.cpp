#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    bool empty;
    Student() {
        roll = -1;
        name = "";
        empty = true;
    }
};

class StudentHashTable {
    Student table[15];
    int size;
public:
    StudentHashTable() {
        size = 15;
    }

    int hashFunc(int key) {
        return key % size;
    }

    void InsertRecord(int roll, string name) {
        int index = hashFunc(roll);
        int attempt = 0;

        while (attempt < size) {
            int newIndex = (index + attempt * attempt) % size;
            if (table[newIndex].empty) {
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].empty = false;
                return;
            }
            attempt++;
        }
        cout << "Table Full\n";
    }

    void SearchRecord(int roll) {
        int index = hashFunc(roll);
        int attempt = 0;

        while (attempt < size) {
            int newIndex = (index + attempt * attempt) % size;
            if (!table[newIndex].empty && table[newIndex].roll == roll) {
                cout << table[newIndex].name << endl;
                return;
            }
            attempt++;
        }
        cout << "Record not found" << endl;
    }
};

int main() {
    StudentHashTable h;

    h.InsertRecord(10, "Ali");
    h.InsertRecord(25, "Sara");
    h.InsertRecord(40, "Hassan");

    h.SearchRecord(25);
    h.SearchRecord(50);

    return 0;
}
