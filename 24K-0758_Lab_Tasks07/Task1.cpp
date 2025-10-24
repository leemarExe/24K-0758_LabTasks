#include<iostream>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
};

Node* insert(Node* head, string name, int score) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->score = score;
    newNode->next = head;
    return newNode;
}

int getMax(Node* head) {
    int mx = head->score;
    Node* temp = head->next;
    while(temp != NULL) {
        if(temp->score > mx)
            mx = temp->score;
        temp = temp->next;
    }
    return mx;
}

Node* append(Node* head, Node* node) {
    if(head == NULL)
        return node;
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = node;
    return head;
}

void countSort(Node*& head, int exp) {
    Node* buckets[10];
    for(int i = 0; i < 10; i++)
        buckets[i] = NULL;

    Node* temp = head;
    while(temp != NULL) {
        int digit = (temp->score / exp) % 10;
        Node* next = temp->next;
        temp->next = NULL;
        buckets[digit] = append(buckets[digit], temp);
        temp = next;
    }

    Node* newHead = NULL;
    Node* tail = NULL;

    for(int i = 0; i < 10; i++) {
        if(buckets[i] != NULL) {
            if(newHead == NULL)
                newHead = buckets[i];
            else
                tail->next = buckets[i];
            tail = buckets[i];
            while(tail->next != NULL)
                tail = tail->next;
        }
    }

    head = newHead;
}

void radixSort(Node*& head) {
    int m = getMax(head);
    for(int exp = 1; m / exp > 0; exp *= 10)
        countSort(head, exp);
}

void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    head = insert(head, "Ali", 75);
    head = insert(head, "Sara", 93);
    head = insert(head, "Hassan", 64);
    head = insert(head, "Aisha", 82);
    head = insert(head, "Bilal", 58);
    head = insert(head, "Omar", 91);
    head = insert(head, "Fatima", 73);
    head = insert(head, "Zain", 69);
    head = insert(head, "Usman", 87);
    head = insert(head, "Hira", 95);

    cout<<"Before radix sort: \n";
    display(head);

    radixSort(head);
    
    cout<<"\nAfter radix sort: \n";
    display(head);
    return 0;
}
