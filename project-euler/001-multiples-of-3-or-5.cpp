/*
    * https://projecteuler.net/problem=1
    * Multiples of 3 and 5
    * Between 1 and 10 (exclusive), the multiples of 3 and 5 are [3,5,6,9] and their sum is 23.
    * What is the sum of all multiples of 3 and 5 between 1 and 1000 exclusive?
*/

#include <iostream>

using namespace std;

bool multipleOfFive(int num) {
    return num % 5 == 0;
}

bool multipleOfThree(int num) {
    return num % 3 == 0;
}

bool multipleOfThreeOrFive(int num) {
    return multipleOfFive(num) | multipleOfThree(num);
}

int main() {
    int sum = 0;

    for (int i = 0; i < 1000; i++) {
        if (multipleOfThreeOrFive(i)) {
            sum += i;
        }
    }

    std::cout << "The sum of all multiples of 3 or 5 between 1 and 1000 (exclusive) is: " << sum;
}