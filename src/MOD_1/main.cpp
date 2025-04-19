#include <iostream>
#include <cmath>

int main() {
    double number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number < 0) {
        std::cout << "Square root of a negative number is not defined in real numbers." << std::endl;
    } else {
        std::cout << "Square root of " << number << " is " << std::sqrt(number) << std::endl;
    }

    return 0;
}