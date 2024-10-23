#include <iostream>
#include <vector>


int main() {

    int sumOfEven = 0;
    int productOfOdd = 1;

    std::vector<int> numbers = { 2,3,4,6,1,9,32,45,52,100 };

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 == 0) {
            sumOfEven = sumOfEven + numbers[i];
        }
        else {
            productOfOdd = productOfOdd * numbers[i];
        }
    }
    std::cout << "Sum of even numbers is " << sumOfEven;
    std::cout << "\nProduct of odd numbers is " << productOfOdd;
}