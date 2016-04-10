/*
Problem 2: Please refer to Program 13 on page 330 of your text.

The population of a town A is less than the population of town B. However, the population of town A is growing faster than the population of town B. Write a program that prompts the user to enter the population and growth rate of each town. The program outputs after how many years the population of town A will be greater than or equal to the population of town B and the populations of both the towns at that time. (A sample input is: Population of town A = 5000, growth rate of town A = 4%, population of town B = 8000, and growth rate of town B = 2%.)
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //init variables
    int popA, popB, numYears;
    double growRateA, growRateB;
    string cityNameA, cityNameB;

    //user input
    cout << "Please enter the name of the smaller city first: ";
    cin >> cityNameA;

    cout << "Please enter the population of " << cityNameA << ": ";
    cin >> popA;

    cout << "Please enter the growth rate percentage per year: ";
    cin >> growRateA;
    cout << endl;

    cout << "Please enter the name of the larger city: ";
    cin >> cityNameB;

    cout << "Please enter the population of " << cityNameB << ": ";
    cin >> popB;

    cout << "Please enter the growth rate percentage: ";
    cin >> growRateB;
    cout << endl;

    // return input data to user
    cout << "User input:" << endl;
    cout << left;
    cout << setfill(' ');
    cout << "City name: " << setw(11) << cityNameA << " Population: " << setw(11) << popA << " Growth rate percentage: " << growRateA << "%" << endl;
    cout << "City name: " << setw(11) << cityNameB << " Population: " << setw(11) << popB << " Growth rate percentage: " << growRateB << "%" << endl;

    cout << endl;

    // check to see if pop a is greater than popb
    if (popA >= popB)
    {
        cout << cityNameA << " is already larger than " << cityNameB << ".";
        return 0;
    }

    // check growth rates
    if (growRateA <= growRateB)
    {
        cout << cityNameA << " will never be larger than " << cityNameB << " at it's current growth rate." << endl;
        return 0;
    }

    // turns percentage into a decimal
    growRateA = growRateA / 100;
    growRateB = growRateB / 100;

    // for loop for counting years
    for (numYears = 0; popA <= popB; numYears++)
    {
    popA = (popA * growRateA) + popA;
    popB = (popB * growRateB) + popB;
    }

    // formatting for the word year/years
    if (numYears == 1){
        cout << "It will take " << numYears << " year for " << cityNameA << " to be larger in population than " << cityNameB << "." << endl;
        cout << left;
        cout << setfill(' ');
        cout << "City name: " << setw(11) << cityNameA << " Population: " << setw(11) << popA << endl;
        cout << "City name: " << setw(11) << cityNameB << " Population: " << setw(11) << popB << endl;
    }
    else{
        cout << "It will take " << numYears << " years for " << cityNameA << " to be larger in population than " << cityNameB << "." << endl;
        cout << left;
        cout << setfill(' ');
        cout << "City name: " << setw(11) << cityNameA << " Population: " << setw(11) << popA << endl;
        cout << "City name: " << setw(11) << cityNameB << " Population: " << setw(11) << popB << endl;
    }

return 0;

}
