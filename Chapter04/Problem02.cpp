/*
Write a program that calculates and prints a customer’s bill for a cellular telephone company. The company offers two types of service: regular and premium. Its rates vary depending on the type of service. The rates are computed as follows:

Regular service:

$10.00 plus first 50 minutes are free. Charges for over 50 minutes are $0.20 per minute.

Premium service:

$25.00 plus:

For calls made from 6:00 am to 6:00 pm, the first 75 minutes are free; charges for more than 75 minutes are $0.10 per minute.
For calls made from 6:00 pm to 6:00 am, the first 100 minutes are free; charges for more than 100 minutes are $0.05 per minute.
Your program should prompt the user to enter an account number, a service code (type char), and the number of minutes the service was used. A service code of r or R means regular service; a service code of p or P means premium service. Treat any other character as an error. Your program should output the account number, type of service, number of minutes the telephone service was used, and the amount due from the user.

For the premium service, the customer may be using the service during the day and the night. Therefore, to calculate the bill, you must ask the user to input the number of minutes the service was used during the day and the number of minutes the service was used during the night.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Constants
const double regOverfee = .20; // Price per minute of free for Regular service
const double dayOverfee = .10; // Price per minute of free for Premium Day service
const double nightOverfee = .05; // Price per minute of free for Premium Night service
const double regService = 10.00; // Price for regular service
const double premService = 25.00; // price for Premium service
const int regFreeMin = 50; // number of free minutes for Regular service
const int premDayFree = 75; // number of free minutes for Premium service days
const int premNightFree = 100; // number of free mintues for Premium service nights

int main()
{
	// Variables
	int acctNum; // total amount due
	char serviceCode; // service code R or P
	double totalMin, dayMin, nightMin, amtDue; // varibles for calculations

	cout << fixed << showpoint << setprecision(2); // set the output for money

	cout << "Please enter your account number: "; // ask user for accout number
	cin >> acctNum; // account number input
	cout << endl; // next line 
	cout << "Please enter your service code (R or P): "; // ask user for serice code
	cin >> serviceCode; // service code input
	cout << endl; // next line

	switch (serviceCode) // start switch
	{
	case 'r': // checks service code for a r or R
	case 'R':

		cout << "Please enter total amount of used minutes: "; // ask user for input based on regular service
		cin >> totalMin; // total mintues input
		cout << endl; // next line

		if (totalMin > regFreeMin) // checks to see if the user has gone over the free minutes
			amtDue = (totalMin - regFreeMin) * regOverfee + regService; // calculates amount due based on overage. 
		else // user was under the free minutes
			amtDue = regService; // no extra money is due

		cout << "Accout number: " << acctNum << " Service Code: " << serviceCode << " Total Minutes: " << totalMin << " Amount due: " << amtDue << endl; // output to the user

	break; // end the first case
	
	case 'p': // checks for service code for a p or P
	case 'P':

		cout << "Enter mintues used during the hours of 6 AM to 6 PM: "; // asks user for total daytime minutes
		cin >> dayMin; // day time minutes input
		cout << endl; // next line
		cout << "Enter mintues used during the hours of 6 PM to 6 AM: "; // asks user for total night time minutes
		cin >> nightMin; // night time minutes input
		cout << endl; // next line

		totalMin = dayMin + nightMin; // calculates total minutes

		if (dayMin <= premDayFree && nightMin <= premNightFree) { // checks to see if mintues are below the free minutes
			amtDue = premService; // no extra charge
		}
		else if (dayMin > premDayFree && nightMin <= premNightFree) // checks to see if daytime minutes are over the free minutes while night minutes are still below
			amtDue = (dayMin - premDayFree) * dayOverfee + premService; // calculates the free for having daytime over minutes

		else if (dayMin > premDayFree && nightMin > premNightFree) // checks to see if both day and night are over.
			amtDue = ((dayMin - premDayFree) * dayOverfee) + ((nightMin - premNightFree) * nightOverfee) + premService; // calculates if both are over

		else if(dayMin <= premDayFree && nightMin > premNightFree) // checks to see if day mintues are below while night mintues are more
			amtDue = (nightMin - premNightFree) * nightOverfee + premService; // calculates if night mintues are more

		cout << "Accout number: " << acctNum << " Service Code: " << serviceCode << " Total Minutes: " << totalMin << " Amount due: " << amtDue << endl; //output to the user

	break; // end 2nd case

	default: // if service code is not r, R, p, or P it goes to default
		cout << "Invalid Service type..." << endl; // output to user if one of the four letters is not used
	}


	system("pause");
		return 0;
}
