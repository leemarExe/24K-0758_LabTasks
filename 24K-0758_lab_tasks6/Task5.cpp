#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Stack {
    double arr[100];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    void push(double val) { arr[++topIndex] = val; }
    double pop() { return arr[topIndex--]; }
    double top() { return arr[topIndex]; }
    bool empty() { return topIndex == -1; }
};

double evaluatePrefix(string expr) {
    Stack s;
    for (int i = expr.length() - 1; i >= 0; i--) {
        char ch = expr[i];
        if (isdigit(ch)) {
            s.push(ch - '0');
        } 
        else {
            double op1 = s.pop();
            double op2 = s.pop();
            double result;
            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default: result = 0;
            }
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    string expr;
    cout << "Enter Prefix Expression: ";
    cin >> expr;

    double result = evaluatePrefix(expr);
    cout << "Result = " << result << endl;

    return 0;
}
