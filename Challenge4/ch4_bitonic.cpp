
// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>
#include <algorithm>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int>& v) {
    int count = v.size();

    if (count < 2) return true;  // A single-element or empty vector is always bitonic

    int i = 0;
    bool rising = false;

    // Skip initial repeated values
    while (i < (count - 1) && v[i] == v[i + 1]) {
        i++;
    }

    if (i == (count - 1)) {
        return true;  // All values are the same
    }

    // First slope: check if it's increasing or decreasing
    if (v[i] < v[i + 1]) {
        // Check for non-strictly increasing slope
        while (i < (count - 1) && v[i] <= v[i + 1]) {
            i++;
        }
    }
    else {
        // Check for non-strictly decreasing slope
        while (i < (count - 1) && v[i] >= v[i + 1]) {
            i++;
        }
    }

    // If we reached the end, it's a monotonic sequence (either strictly increasing or decreasing)
    if (i == (count - 1)) {
        return true;
    }

    // Second slope: check if it is opposite to the first slope
    if (v[i] < v[i + 1]) {
        // Check for non-strictly increasing slope
        while (i < (count - 1) && v[i] <= v[i + 1]) {
            i++;
        }
    }
    else {
        // Check for non-strictly decreasing slope
        while (i < (count - 1) && v[i] >= v[i + 1]) {
            i++;
        }
    }

    // If we reached the end, it's a bitonic sequence
    if (i == (count - 1)) {
        return true;
    }

    // Third slope: check if it's similar to the first slope for a circular bitonic sequence
    if (v[i] < v[i + 1]) {
        rising = true;
        // Check for non-strictly increasing slope
        while (i < (count - 1) && v[i] <= v[i + 1]) {
            i++;
        }
    }
    else {
        rising = false;
        // Check for non-strictly decreasing slope
        while (i < (count - 1) && v[i] >= v[i + 1]) {
            i++;
        }
    }

    // If we reached the end, check if the sequence wraps around to form a circular bitonic
    if (i < (count - 1)) {
        return false;  // There's a fourth slope, so it's not a valid bitonic sequence
    }

    // If the sequence wraps back to the start (circular check)
    if (rising && v[i] <= v[0]) {
        return true;
    }

    if (!rising && v[i] >= v[0]) {
        return true;
    }

    return false;  // The third slope is different from the first one (there's a fourth slope)
}

// Main function
int main() {
    // Uncomment one of these lines and make sure you get the result at the right. 

    std::vector<int> myvec1 = { 1, 2, 5, 4, 3 };  // Yes
    std::vector<int> myvec2 = {1, 1, 1, 1, 1};  // Yes
    std::vector<int> myvec3 = {3, 4, 5, 2, 2};  // Yes
    std::vector<int> myvec4 = {3, 4, 5, 2, 4};  // No
    std::vector<int> myvec5 = {1, 2, 3, 4, 5};  // Yes
    std::vector<int> myvec6 = {1, 2, 3, 1, 2};  // No
    std::vector<int> myvec7 = {5, 4, 6, 2, 6};  // No
    std::vector<int> myvec8 = {5, 4, 3, 2, 1};  // Yes
    std::vector<int> myvec9 = {5, 4, 3, 2, 6};  // Yes
    std::vector<int> myvec10 = {5, 4, 6, 5, 4};  // No
    std::vector<int> myvec11 = {5, 4, 6, 5, 5};  // Yes

    std::cout << (is_bitonic(myvec1) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    std::cout << (is_bitonic(myvec2) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    std::cout << (is_bitonic(myvec3) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    std::cout << (is_bitonic(myvec4) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    std::cout << (is_bitonic(myvec5) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    std::cout << (is_bitonic(myvec6) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    std::cout << (is_bitonic(myvec7) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    std::cout << (is_bitonic(myvec8) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    std::cout << (is_bitonic(myvec9) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    std::cout << (is_bitonic(myvec10) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    std::cout << (is_bitonic(myvec11) == true ? "Yes, it is bitonic." : "No, it is not bitonic.") << std::endl;
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}