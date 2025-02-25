#pragma once
// Challenge #1: Checking for Palindromes
// Write a function to check if a string is a palindrome or not.
// Examples: civic, radar, level.

#include <iostream>
#include <algorithm>
#include <string>

// is_palindrome()
// Summary: This function receives a string and returns true if the string is a palindrome, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for palindromes, false otherwise.
bool is_palindrome(std::string str) {

    bool checker = false;
    int totalSize = str.length() - 1;

    for (int i = 0; i <= totalSize; i++)
    {
        if (tolower(str[i]) == tolower(str[totalSize - i]))
        {
            checker = true;
        }
        else
        {
            checker = false;
        }

        if (i <= totalSize - i)
        {
            break;
        }
    }


    return checker;
}

// Main function
int main() {
    std::string s;
    std::cout << "Enter a string: " << std::flush;
    std::getline(std::cin, s);
    std::cout << "\n\"" << s << (is_palindrome(s) ? "\" is" : "\" is not") << " a palindrome.\n\n";
    return 0;
}
