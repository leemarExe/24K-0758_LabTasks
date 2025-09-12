#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray() : capacity(2), size(0) {
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << ' ';
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);

    arr.print();

    return 0;
}
