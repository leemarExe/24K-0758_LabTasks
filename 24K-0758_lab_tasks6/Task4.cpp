#include <iostream>
#include <string>
using namespace std;

class Stack {
    char arr[100];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    void push(char ch) { arr[++topIndex] = ch; }
    char pop() { return arr[topIndex--]; }
    char top() { return arr[topIndex]; }
    bool empty() { return topIndex == -1; }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.pop();
            }
            s.pop();
        }
        else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch) && ch != '^') {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        postfix += s.pop();
    }
    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    return 0;
}
