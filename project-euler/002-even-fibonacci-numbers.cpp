/*
    * https://projecteuler.net/problem=2
    * Even Fibonacci Numbers
    * Taking all numbers in the fibonacci sequence that are less than 4 million,
    * add all the even numbers together.
*/
#include <iostream>

using namespace std;

int main() {
    //2 is an even number, and since the while loop won't process it, I'm hard-coding sum to start at 2
    int sum = 2;
    
    //Hard-coded the first 3 numbers of the fibonacci sequence to facilitate an easy while loop
    int first = 1;
    int second = 2;
    int current = 3;

    while(current <= 4000000) {
        first = second;
        second = current;
        current = first + second;

        if (current % 2 == 0) {
            sum += current;
        }
    }

    std::cout << "The sum of all even fibonacci numbers is: " << sum;
}