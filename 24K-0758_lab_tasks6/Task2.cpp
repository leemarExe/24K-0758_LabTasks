#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Stack {
    float arr[100];
    int topIndex;
public:
    Stack() { topIndex = -1; }

    void push(float val) {
        if (topIndex < 99) arr[++topIndex] = val;
        else cout << "Stack Overflow\n";
    }

    float pop() {
        if (topIndex >= 0) return arr[topIndex--];
        else {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    bool empty() {
        return topIndex == -1;
    }

    float top() {
        if (topIndex >= 0) return arr[topIndex];
        else {
            cout << "Stack is empty\n";
            return -1;
        }
    }
};

float evaluatePostfix(const char* exp) {
    Stack s;
    int n = strlen(exp);

    for (int i = 0; i < n; i++) {
        char c = exp[i];

        if (isdigit(c)) {
            s.push(c - '0');
        }
        else {
            float val2 = s.pop();
            float val1 = s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                default: cout << "Invalid operator: " << c << endl;
            }
        }
    }

    return s.top();
}

int main() {
    char expression[100];
    cout << "Enter postfix expression: ";
    cin >> expression;

    float result = evaluatePostfix(expression);
    cout << "Result = " << result << endl;

    return 0;
}
