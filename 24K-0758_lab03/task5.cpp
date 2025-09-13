#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* next;
    Node(string s) : song(s), next(NULL) {}
};

class Playlist {
private:
    Node* tail;
public:
    Playlist() : tail(NULL) {}

    void addSong(string s) {
        Node* newNode = new Node(s);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteSong(string s) {
        if (!tail) return;
        Node* curr = tail->next;
        Node* prev = tail;
        do {
            if (curr->song == s) {
                if (curr == tail && curr == tail->next) {
                    delete curr;
                    tail = NULL;
                    return;
                }
                prev->next = curr->next;
                if (curr == tail) tail = prev;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
    }

    void searchSong(string s) {
        if (!tail) {
            cout << "Playlist empty\n";
            return;
        }
        Node* curr = tail->next;
        do {
            if (curr->song == s) {
                cout << "Song found: " << s << endl;
                return;
            }
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Song not found\n";
    }

    void display() {
        if (!tail) {
            cout << "Playlist empty\n";
            return;
        }
        Node* curr = tail->next;
        do {
            cout << curr->song << " -> ";
            curr = curr->next;
        } while (curr != tail->next);
        cout << "(back to start)" << endl;
    }
};

int main() {
    Playlist p;
    p.addSong("Song A");
    p.addSong("Song B");
    p.addSong("Song C");
    p.display();

    p.searchSong("Song B");
    p.deleteSong("Song B");
    p.display();

    p.searchSong("Song B");

    return 0;
}
