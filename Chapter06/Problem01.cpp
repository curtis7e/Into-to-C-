/*
Problem 1: Please refer to Program 1 on page 436 of your text.

Write a program that uses the function isPalindrome given in Example 6-5 (Palindrome). Test your program on the following strings: “madam”, “abba”, “22”, “67876”, “444244”, and “trymeuemyrt”.
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//declaring my function
bool isPalindrome(string str);

int main() //main function
{   //user input
    string userString;
    cout << "Enter string: ";
    cin >> userString;
    cout << endl;

    //output from function
    if (isPalindrome(userString) == 1)
        cout << "Your entry is Palindrome!\n";
    else
        cout << "Your entry is not Palindrome!\n";
    system("Pause");
    return 0;
} // end main function

bool isPalindrome(string str) //Palindrome function
{
    int length = str.length(); // gets the length of the string and stores it in a int

    for (int i =0; i < length / 2; i++) // for loop using the length
        if (str[i] != str[length - 1 -i]) // if statement to check palindrome
            return false;

    return true;

}
