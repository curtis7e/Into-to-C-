/*
Please refer to Program 1 on page 328 of your text.

Write a program that prompts the user to input an integer and then outputs both the individual digits of the number and the sum of the digits.
For example, it should output the individual digits of 3456 as 3 4 5 6, output the individual digits of 8030 as 8 0 3 0, output the individual digits of 2345526 as 2 3 4 5 5 2 6,
output the individual digits of 4000 as 4 0 0 0, and output the individual digits of -2345 as 2 3 4 5.
*/
#include <iostream>

using namespace std;

int main(){
// Declare variables
int digitFwd = 0, userNum = 0, digit, revNum = 0, sum = userNum;

//user input
cout << "Please enter a whole number: ";
cin >> userNum;

if(userNum < 0) // convert a negative number to a positive one
{
    userNum = 0 - userNum;
}

do // extracts the numbers in reverse order.
{
    digit = userNum % 10;
    userNum = userNum / 10;
    revNum = (revNum + digit) * 10; // stores the number in reverse order
} while (userNum > 0);

revNum = revNum / 10; // drops the 0 off the end

cout << "Individual digits: ";
do
{ //extracting the digits back in the correct order
    digitFwd = 0;
    digitFwd = revNum % 10;
    revNum = revNum / 10;
    sum = sum + digitFwd;
    cout << digitFwd << " ";
}
while(revNum > 0);

cout << endl;
cout << "The sums of the entered digits is: " << sum << endl; // sum output

return 0;
}
