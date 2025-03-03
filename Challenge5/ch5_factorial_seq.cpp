
// Challenge #5: Factorial Sequence
// Write a recursive function to print a sequence of factorials from 0! to n!
// n is received as an argument.
// n = 4 : {1, 1, 2, 6, 24}
// Only calculate each element once.
// Print the sequence on the screen.

#include <iostream>
using namespace std;
// print_factorials()
// Summary: This function receives a (small) positive integer n and prints out a sequence from 0! through n!.
// Arguments:
//           n: The argument of the last factorial to print.
// Returns: n!, the last calculated factorial.
int print_factorials(int n) {

    int factRecursive;

    if (n == 0) 
    {
        factRecursive = 1;
    }
    else 
    {
        factRecursive = n * print_factorials(n - 1);
    }

    cout << factRecursive << endl;
    return factRecursive;
}

// Main function
int main() {
    print_factorials(10);
    cout << endl << endl << flush;
    return 0;
}