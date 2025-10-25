#include <iostream>
using namespace std;

#define MAX 10  

// Task #6 Explanation:
//
// -> Data structure used: Queue
// Reason: A queue follows FIFO (First-In-First-Out) order, 
// meaning the first order received will be the first to be processed.
// This ensures fairness and proper sequence of order handling
// in a busy restaurant.
//
// -> Necessary operations:
//    - enqueue(): Add new order (when a customer places an order)
//    - dequeue(): Remove/process order (when it’s being prepared/served)
//    - isFull():  Prevent queue overflow (too many pending orders)
//    - isEmpty(): Prevent queue underflow (no orders to process)
//    - display(): Print all current orders in the order they were received


class Order {
public:
    string itemName;
    int quantity;
};

class Queue {
    Order orders[MAX]; 
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

    void enqueue(string name, int qty) {
        if (isFull()) {  
            cout << "Queue Overflow! Cannot add more orders.\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        orders[rear].itemName = name;
        orders[rear].quantity = qty;

        cout << "Order added: " << name << " (x" << qty << ")\n";
    }

    void dequeue() {
        if (isEmpty()) { 
            cout << "Queue Underflow! No orders to process.\n";
            return;
        }

        cout << "Processing order: " << orders[front].itemName
             << " (x" << orders[front].quantity << ")\n";

        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No processed orders to display.\n";
            return;
        }

        cout << "\nProcessed Orders in order received:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " 
                 << orders[i].itemName 
                 << " (x" << orders[i].quantity << ")\n";
        }
    }
};


int main() {
    Queue restaurantQueue;  

    restaurantQueue.enqueue("Burger", 2);
    restaurantQueue.enqueue("Pizza", 1);
    restaurantQueue.enqueue("Pasta", 3);


    restaurantQueue.dequeue();  
    restaurantQueue.dequeue();  

    restaurantQueue.display();  

    return 0;
}
