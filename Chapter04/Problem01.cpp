/*
Write a program that prompts the user to input three numbers. The program should then output the numbers in ascending order.
*/

#include <iostream>

using namespace std;

int main() {

	int num1, num2, num3; // number inputs by user

	cout << "Please enter your first number: "; // text for user input
	cin >> num1; // num1 input
	cout << endl; // end line for formatting
	cout << "Please enter your second number: "; // text for user input
	cin >> num2; // num2 input
	cout << endl; // end line for formatting
	cout << "Please enter your third number: "; // text for user input
	cin >> num3; //num3 input
	cout << endl; // end line for formatting
	
	cout << "Calculating accending order..." << endl; // words for the user to read while waiting

	if (num1 > num2 && num2 > num3) { // checks to see if num1 is greater than num2 AND num2 is greater than num3
		cout << num3 << " " << num2 << " " << num1 << endl; // if it evalutes to true this is the order of the numbers
	}
	else if (num1 > num3 && num3 > num2) // checks to see if num1 is greater than num3 AND num3 is greater than num2
		cout << num2 << " " << num3 << " " << num1 << endl; // if it evaluares to true this is the order of the numbers

	else if (num2 > num1 && num1 > num3) // checks to see if num2 is greater than num1 AND num1 is greater than num3
		cout << num3 << " " << num1 << " " << num2 << endl; // if it evaluates to true this is the order of the numbers

	else if (num2 > num3 && num3 > num1) // checks to see if num2 is greater than num3 AND num3 is greater than num1
		cout << num1 << " " << num3 << " " << num2 << endl; // if it evaluates to true this is the order of the numbers

	else if (num3 > num1 && num1 > num2) // checks to see if num3 is greater than num1 AND num1 is greater tha num2
		cout << num2 << " " << num1 << " " << num3 << endl; // if it evaluates to true this is the order of the numbers

	else
		cout << num1 << " " << num2 << " " << num3 << endl; // if all the above evaluate as false this is the order output


	system("pause");
	return 0;


}
