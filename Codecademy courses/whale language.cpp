#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string input = "Turpentine and turtles.";

    std::vector<char> vowels = { 'a', 'o', 'i', 'e', 'u' };
    std::vector<char> result;

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < vowels.size(); j++) {
            if (input[i] == vowels[j]) {
                result.push_back(input[i]);
            }
        }
        if (input[i] == 'e') {
            result.push_back(input[i]);
        }
        if (input[i] == 'u') {
            result.push_back(input[i]);
        }
    }

    for (int k = 0; k < result.size(); k++) {
        std::cout << result[k];
    }
}
