#pragma once
// Challenge #3: FizzBuzz
// Write an application that plays FizzBuzz.
// Print an integer number sequence starting at 1, replacing multiples of 3 by "Fizz", multiples of 5 by "Buzz", and multiples of 3 and 5 by "FizzBuzz".
// The user enters the last number in the sequence.

#include <iostream>

// FizzBuzz, main()
// Summary: This application runs on the main function.
int main() {
    int n; // How many numbers to include in the sequence.

    std::cout << "Enter a positive integer: " << std::flush;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0) 
        {
            std::cout << "FizzBuzz" << std::endl;
        }
        else if (i % 3 == 0) 
        {
            std::cout << "Fizz" << std::endl;
        }
        else if (i % 5 == 0) 
        {
            std::cout << "Buzz" << std::endl;
        }
        else
        {
            std::cout << i << std::endl;
        }
    }

    std::cout << std::endl << std::flush;
    return 0;
}
