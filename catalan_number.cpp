#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Validate if the input is an integer
bool IsValidNumber(const string& input)
{
    for (char character : input)
    {
        if (!isdigit(character))
        {
            return false;
        }
    }
    return true;
}

// Print error message to the terminal
void PrintErrorMessage()
{
    cerr << "Please provide an integer, non-negative input." << endl;
}

// Calculate the catalan number
unsigned long long int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    unsigned long long int catalan_number = 0;
    for (int i = 0; i < n; ++i)
    {
        catalan_number += catalan(i) * catalan(n - i - 1);
    }
    return catalan_number;
}

// DRIVER
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cerr << "Please follow the syntax: ./catalan + [positive number]." << endl;
        return -1;
    }
    else if (argc == 2)
    {
        string input = argv[1];
        if (!IsValidNumber(input))
        {
            PrintErrorMessage();
            return -1;
        }
        int num = stoi(input);
        if (num < 0)
        {
            PrintErrorMessage();
            return -1;
        }
        else
        {
            cout << catalan(num) << endl;
        }
    }
    return 0;
}
