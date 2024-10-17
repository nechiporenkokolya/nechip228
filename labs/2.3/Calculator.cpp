#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <stdexcept>
using namespace std;

// ������� ��� ���������� ��������� ���������
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1; // ��������� ��������
    }
    else if (c == '*' || c == '/') {
        return 2; // ����� ��������
    }
    return -1; // ������� ��������
}

// ������� ��� ��������� ����������� ��������
int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/':
        if (operand2 == 0) {
            throw invalid_argument("ĳ����� �� ����!"); // �������� �� ������ �� ����
        }
        return operand1 / operand2;
    default: throw invalid_argument("������� ��������!"); // �������� ��������
    }
}

// ������� ��� ������������ ���������� ������ � �����������
string infixToPostfix(const string& expression) {
    stack<char> operators; // ���� ��� ��������� ���������
    string postfix; // ������������ ����������� �����

    for (char c : expression) {
        if (isdigit(c)) {
            postfix += c; // ���� �� �����, ������ �� ������������ ������
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // ��������� � ����� ��������� � ����� ��� ����� ����������
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c); // ������ �������� �������� � ����
        }
    }

    // ������ ����� ��������� � �����
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix; // ��������� ����������� �����
}

// ������� ��� ���������� ������������ ������
int evaluatePostfix(const string& expression) {
    stack<int> operands; // ���� ��� ��������� ��������

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0'); // ������������ ������ ����� � ���� �����
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // ������� ��� �������� � �����
            int operand2 = operands.top(); operands.pop();
            int operand1 = operands.top(); operands.pop();
            // �������� �������� � ������ ��������� � ����
            int result = performOperation(c, operand1, operand2);
            operands.push(result);
        }
    }

    return operands.top(); // ��������� ��������� ����������
}

// ������� ������� ��������
int main() {

    setlocale(LC_ALL, "ukr");
    system("chcp 65001");

    string infixExpression;
    cout << "������ ��������� �����: ";
    cin >> infixExpression;

    try {
        // ������������ ���������� ������ � �����������
        string postfixExpression = infixToPostfix(infixExpression);
        cout << "����������� �����: " << postfixExpression << endl;

        // ���������� ������������ ������
        int result = evaluatePostfix(postfixExpression);
        cout << "���������: " << result << endl;
    }
    catch (const exception& e) {
        // ��������� ����������� ��� �������
        cout << "�������: " << e.what() << endl;
    }

    return 0;
}

