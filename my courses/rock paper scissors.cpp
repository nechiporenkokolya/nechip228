/*эта программа для игры камень, ножницы, бумага

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    // Live long and prosper
    srand(time(NULL));
    int computer = rand() % 3 + 1;
    int user = 0;

    std::cout << "====================\n";
    std::cout << "rock paper scissors!\n";
    std::cout << "====================\n";

    std::cout << "1) Rock\n";
    std::cout << "2) Paper\n";
    std::cout << "3) Scissors\n";

    std::cout << "shoot! ";

    std::cin >> user;

    if (user == 1 && computer == 1) {
        std::cout << "Draw\n";
    }
    else if (user == 1 && computer == 2) {
        std::cout << "Computer win\n";
    }
    else if (user == 1 && computer == 3) {
        std::cout << "You win\n";
    }
    else if (user == 2 && computer == 1) {
        std::cout << "You win\n";
    }
    else if (user == 2 && computer == 2) {
        std::cout << "Draw\n";
    }
    else if (user == 2 && computer == 3) {
        std::cout << "Computer win\n";
    }
    else if (user == 3 && computer == 1) {
        std::cout << "Computer win\n";
    }
    else if (user == 3 && computer == 2) {
        std::cout << "You win\n";
    }
    else if (user == 3 && computer == 3) {
        std::cout << "Draw\n";
    }
    else {
        std::cout << "Invalid input";
    }
}*/