#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int year;

    std::cout << "Enter year: ";
    std::cin >> year;

    double n = year / 1000;

    if ((n / (pow(10, 3)) < 10 || (n / (pow(10, 3)) >= 1))) {
        if ((year % 4 == 0) || (year % 400 == 0)) {
            std::cout << "Leap year\n";
        }
        else {
            std::cout << "No leap year\n";
        }
    }
    else {
        std::cout << "Invalid input\n";
    }
}
