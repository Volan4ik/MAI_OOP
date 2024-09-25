#include "seven.h"
#include <iostream>

int main() {
    Seven num1("123");
    Seven num2("456");

    std::cout << "Number 1: " << num1 << std::endl;
    std::cout << "Number 2: " << num2 << std::endl;

    Seven result = num1 + num2;
    std::cout << "Sum: " << result << std::endl;

    if (num1 == num2) {
        std::cout << "Numbers are equal." << std::endl;
    } else if (num1 > num2) {
        std::cout << "Number 1 is greater than Number 2." << std::endl;
    } else {
        std::cout << "Number 1 is less than Number 2." << std::endl;
    }

    return 0;
}
