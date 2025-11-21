#include<iostream>
using namespace std;


class HashingLinearProbing{
    int size;
    int* table;

    public:
    HashingLinearProbing(int s) : size(s){
        table = new int[size];
        for(int i = 0 ; i < size ; i++) table[i] = -1;
    }

    int hash(int key){
        return key % size;
    }

    void insertLinear(int key){
        int index = hash(key);
        int i = 0;
        while(table[(index + i) % size] != -1) i += 1;
        table[(index + i) % size] = key;
    }

    void deleteKey(int key){
        int index = hash(key);
        for(int i = 0 ; i < size ; i++){
            int newIndex = (index + i) % size;
            if(table[newIndex] == key) table[newIndex] = -1;
            if(table[newIndex] == -1) break;
        }
    }

    bool search(int key){
        int index = hash(key);
        for(int i = 0 ; i < size ; i++){
            int newIndex = (index + i) % size;
            if(table[newIndex] == key) return true;
            if(table[newIndex] == -1) break;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1) {
                cout << table[i] << " ";
            }
        }
    }
};


int main() {
    HashingLinearProbing ht(10);

    ht.insertLinear(1);
    ht.insertLinear(3);
    ht.insertLinear(4);
    ht.insertLinear(5);
    ht.insertLinear(7);
    ht.display();
    
    cout << "\nRemove 4\n";
    ht.deleteKey(4);
    ht.display();
    
    if(ht.search(5)) cout  << "\n5 found.\n";
    else cout << "\n5 not found.\n"; 

    if(ht.search(6)) cout  << "6 found.\n";
    else cout << "6 not found.\n"; 

    return 0;
}