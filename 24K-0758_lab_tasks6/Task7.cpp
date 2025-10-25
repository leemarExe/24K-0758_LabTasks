#include <iostream>
using namespace std;

#define MAX 10

class Patron {
public:
    string name;
    int books;
};

class Queue {
    Patron patrons[MAX];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string n, int b) {
        if (isFull()) {
            cout << "Queue is full. Patron cannot be added.\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        patrons[rear].name = n;
        patrons[rear].books = b;
        cout << n << " has entered the queue with " << b << " book(s).\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No patrons in the queue.\n";
            return;
        }
        cout << patrons[front].name << " has completed their transaction for "
             << patrons[front].books << " book(s).\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patrons are waiting in the queue.\n";
            return;
        }
        cout << "\nCurrent Queue of Patrons:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << patrons[i].name
                 << " (" << patrons[i].books << " book(s))\n";
        }
    }
};

int main() {
    Queue libraryQueue;

    libraryQueue.enqueue("Alice", 2);
    libraryQueue.enqueue("Bob", 3);
    libraryQueue.enqueue("Charlie", 1);

    libraryQueue.display();

    libraryQueue.dequeue();
    libraryQueue.dequeue();

    libraryQueue.display();

    return 0;
}
