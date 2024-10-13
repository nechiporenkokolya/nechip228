#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

string infixToPostfix(const string& expression) {
    stack<char> operators;
    string postfix;

    for (char c : expression) {
        if (isdigit(c)) {
            postfix += c;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& expression) {
    stack<int> operands;

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0');
        }
        else {
            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();
            if (c == '+') operands.push(a + b);
            else if (c == '-') operands.push(a - b);
            else if (c == '*') operands.push(a * b);
            else if (c == '/') operands.push(a / b);
        }
    }
    return operands.top();
}

int main() {
    string expression;
    cout << "Enter the expression: ";
    cin >> expression;

    string postfix = infixToPostfix(expression);
    int result = evaluatePostfix(postfix);

    cout << "Result: " << result << endl;
    return 0;
}
