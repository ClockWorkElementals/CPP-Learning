/*
    * https://projecteuler.net/problem=3
    * Largest Prime Number
    * The Prime Factors of 13195 are 5, 7, 13, and 29.
    * What is the largest prime factor of 600,851,475,143?
*/
#include <iostream>
using namespace std;

long largestPrimeFactor(long long number) {
    while (number % 2 == 0) {
        number /= 2;
    }
    long largestFactor = 2;
    for(long i = 3; i <= number; i += 2) {
        while (number % i == 0) {
            number /= i;
            
            largestFactor = i;            
        }
    }
    return largestFactor;
}


int main() {
    long long input = 600851475143;
    std::cout<<"The largest factor of " << input << " is: " << largestPrimeFactor(input);
}