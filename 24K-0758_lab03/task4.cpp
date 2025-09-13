#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(NULL) {}

    void addNode(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void sortList() {
        if (!head) return;
        Node* i;
        Node* j;
        for (i = head; i->next; i = i->next) {
            for (j = i->next; j; j = j->next) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    void concatenate(LinkedList& other) {
        if (!head) {
            head = other.head;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = other.head;
        other.head = NULL;
    }

    void findMiddle() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }

    void removeDuplicates() {
        if (!head) return;
        Node* current = head;
        while (current) {
            Node* runner = current;
            while (runner->next) {
                if (runner->next->data == current->data) {
                    Node* dup = runner->next;
                    runner->next = runner->next->next;
                    delete dup;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    static LinkedList mergeSorted(LinkedList& l1, LinkedList& l2) {
        LinkedList result;
        Node dummy(0);
        Node* tail = &dummy;
        Node* p = l1.head;
        Node* q = l2.head;

        while (p && q) {
            if (p->data <= q->data) {
                tail->next = p;
                p = p->next;
            } else {
                tail->next = q;
                q = q->next;
            }
            tail = tail->next;
        }
        tail->next = (p) ? p : q;
        result.head = dummy.next;
        l1.head = l2.head = NULL;
        return result;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list1, list2;
    list1.addNode(5);
    list1.addNode(3);
    list1.addNode(8);
    list1.addNode(3);
    list1.addNode(1);

    cout << "Original List1: ";
    list1.display();

    list1.sortList();
    cout << "Sorted List1: ";
    list1.display();

    list1.removeDuplicates();
    cout << "List1 after removing duplicates: ";
    list1.display();

    list1.findMiddle();

    list2.addNode(2);
    list2.addNode(4);
    list2.addNode(6);

    cout << "List2: ";
    list2.display();

    LinkedList merged = LinkedList::mergeSorted(list1, list2);
    cout << "Merged Sorted List: ";
    merged.display();

    return 0;
}
