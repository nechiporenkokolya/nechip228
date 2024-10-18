#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <stdexcept>
using namespace std;

// Функція для визначення пріоритету операторів
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1; // Найнижчий пріоритет
    }
    else if (c == '*' || c == '/') {
        return 2; // Вищий пріоритет
    }
    return -1; // Невірний оператор
}

// Функція для виконання арифметичної операції
int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/':
        if (operand2 == 0) {
            throw invalid_argument("Ділення на нуль!"); // Перевірка на ділення на нуль
        }
        return operand1 / operand2;
    default: throw invalid_argument("Невірний оператор!"); // Невідомий оператор
    }
}

// Функція для перетворення інфіксного виразу в постфіксний
string infixToPostfix(const string& expression) {
    stack<char> operators; // Стек для зберігання операторів
    string postfix; // Результуючий постфіксний вираз

    for (char c : expression) {
        if (isdigit(c)) {
            postfix += c; // Якщо це цифра, додаємо до постфіксного виразу
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Видаляємо зі стеку оператори з вищим або рівним пріоритетом
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c); // Додаємо поточний оператор у стек
        }
    }

    // Додаємо решту операторів зі стеку
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix; // Повертаємо постфіксний вираз
}

// Функція для обчислення постфіксного виразу
int evaluatePostfix(const string& expression) {
    stack<int> operands; // Стек для зберігання операндів

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0'); // Перетворюємо символ цифри у ціле число
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Виймаємо два операнди зі стеку
            int operand2 = operands.top(); operands.pop();
            int operand1 = operands.top(); operands.pop();
            // Виконуємо операцію і додаємо результат у стек
            int result = performOperation(c, operand1, operand2);
            operands.push(result);
        }
    }

    return operands.top(); // Повертаємо результат обчислення
}

// Головна функція програми
int main() {

    setlocale(LC_ALL, "ukr");
    system("chcp 65001");

    string infixExpression;
    cout << "Введіть інфіксний вираз: ";
    cin >> infixExpression;

    try {
        // Перетворення інфіксного виразу в постфіксний
        string postfixExpression = infixToPostfix(infixExpression);
        cout << "Постфіксний вираз: " << postfixExpression << endl;

        // Обчислення постфіксного виразу
        int result = evaluatePostfix(postfixExpression);
        cout << "Результат: " << result << endl;
    }
    catch (const exception& e) {
        // Виведення повідомлення про помилку
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}

