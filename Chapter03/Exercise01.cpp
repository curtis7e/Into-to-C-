/*
Write a program that prompts the user to enter the weight of a person in kilograms and outputs the equivalent weight in pounds. 
Output both the weights rounded to two decimal places (note that 1 kilogram = 2.2 pounds).
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double weightKilo, weightPound; // weight in kilograms then weight in pounds converted from weightKilo
	cout << "Enter weight in kilograms: ";
	cin >> weightKilo; //user input for weight in kilograms
	cout << endl; // end line

	weightPound = weightKilo * 2.2; // defines weightPound from weightKilo

	cout << fixed << showpoint << setprecision(2); //sets fixed decimal point, show the last zero, and sets the decimal to 2.

	cout << "Weight in Kilograms is: " << weightKilo << endl; // outputs the weight in kilograms
	cout << "Weight in Pounds is: " << weightPound << endl; //outputs the weight in pounds

	system("pause");
	return 0;

}
