#include <iostream>
#include <cmath> // For floating-point abs()
#include <cstdlib> // For integer abs()

int main() {
    int num1 = -10;
    int num2 = 5;

    // For integers
    int absoluteDifferenceInt = std::abs(num1 - num2);
    std::cout << "Absolute difference (int): " << absoluteDifferenceInt << std::endl; // Output: 15

    double num3 = 10.5;
    double num4 = -5.2;

    // For floating-point numbers
    double absoluteDifferenceDouble = std::abs(num3 - num4);
    std::cout << "Absolute difference (double): " << absoluteDifferenceDouble << std::endl; // Output: 15.7

    return 0;
}