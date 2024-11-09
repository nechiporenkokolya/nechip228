#include <iostream>
#include <string>
#include <cctype>

bool isValidString(const std::string& str) {
    int n = str.size();
    if (n < 4) return false; 

    int i = 0;

    if (str[i] != '(') return false;
    i++;

    if (str[i] < '5' || str[i] > '9') return false;
    i++;

    while (i < n && str[i] >= '5' && str[i] <= '9') {
        i++;
    }

    if (str[i] != '%' && str[i] != '*') return false;
    i++;

    if (!isupper(str[i])) return false; 
    while (i < n && isupper(str[i])) {
        i++;
    }

    if (str[i] != ')') return false;

    return i == n - 1;
}

int main() {
    std::string input;
    std::cout << "Введите строку для проверки: ";
    std::cin >> input;

    if (isValidString(input)) {
        std::cout << "Строка принадлежит языку L(V)." << std::endl;
    }
    else {
        std::cout << "Ошибка: строка не принадлежит языку L(V)." << std::endl;
    }

    return 0;
}
 