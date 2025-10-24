#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low;
    Node* j = low;
    while(j != high) {
        if(j->data < pivot) {
            swap(i, j);
            i = i->next;
        }
        j = j->next;
    }
    swap(i, high);
    return i;
}

void quickSort(Node* low, Node* high) {
    if(low == NULL || low == high || low == high->next)
        return;
    Node* p = partition(low, high);
    Node* temp = low;
    while(temp->next != p && temp->next != NULL)
        temp = temp->next;
    if(temp != p)
        quickSort(low, temp);
    quickSort(p->next, high);
}

Node* getTail(Node* curr) {
    while(curr != NULL && curr->next != NULL)
        curr = curr->next;
    return curr;
}

void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = newNode(10);
    head->next = newNode(7);
    head->next->next = newNode(8);
    head->next->next->next = newNode(9);
    head->next->next->next->next = newNode(1);
    head->next->next->next->next->next = newNode(5);
    head->next->next->next->next->next->next = newNode(3);

    Node* tail = getTail(head);
    quickSort(head, tail);

    printList(head);
    return 0;
}
