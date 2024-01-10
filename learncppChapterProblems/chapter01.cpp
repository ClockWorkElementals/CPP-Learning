
/*
    * https://www.learncpp.com/cpp-tutorial/developing-your-first-program/
    * The goal of this program is incorporating basic C++ skills to build a very simple app
    * that takes in an integer as an input and multiplies it by 2.
*/

#include <iostream>

int main() {

    int input{};
    
    std::cout << "Enter an integer: ";

    std::cin >> input;

    std::cout << "Your input, once doubled, is: " << input * 2 << "\n";
    std::cout << "Your input, once tripled, is: " << input * 3;

    return 0;
}