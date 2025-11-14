#include <iostream>
using namespace std;

class Node {
public:
    int val;
    int height;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        height = 1;
        left = 0;
        right = 0;
    }
};

class AVLTree {
    Node* root;

    int h(Node* n) {
        return n ? n->height : 0;
    }

    int bf(Node* n) {
        return n ? h(n->left) - h(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t = x->right;
        x->right = y;
        y->left = t;
        y->height = 1 + max(h(y->left), h(y->right));
        x->height = 1 + max(h(x->left), h(x->right));
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t = y->left;
        y->left = x;
        x->right = t;
        x->height = 1 + max(h(x->left), h(x->right));
        y->height = 1 + max(h(y->left), h(y->right));
        return y;
    }

    Node* insertNode(Node* node, int val) {
        if (!node) return new Node(val);

        if (val < node->val)
            node->left = insertNode(node->left, val);
        else
            node->right = insertNode(node->right, val);

        node->height = 1 + max(h(node->left), h(node->right));
        int balance = bf(node);

        if (balance > 1 && val < node->left->val)
            return rightRotate(node);

        if (balance < -1 && val > node->right->val)
            return leftRotate(node);

        if (balance > 1 && val > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && val < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderPrint(Node* r) {
        if (!r) return;
        inorderPrint(r->left);
        cout << r->val << " ";
        inorderPrint(r->right);
    }

public:
    AVLTree() {
        root = 0;
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    void inorder() {
        inorderPrint(root);
    }
};

int main() {
    
    AVLTree t;
    t.insert(10);
    t.insert(5);
    t.insert(15);
    t.insert(3);
    t.insert(7);
    t.insert(12);

    t.inorder();
}
