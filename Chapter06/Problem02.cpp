/*
Problem 2: Please refer to Program 26 on page 447 of your text.

Jason opened a coffee shop at the beach and sells coffee in three sizes: small (9 oz), medium (12 oz), and large (15 oz). The cost of one small cup is $1.75, one medium cup is $1.90, and one large cup is $2.00. Write a menu-driven program that will make the coffee shop operational. Your program should allow the user to do the following:

Buy coffee in any size and in any number of cups.
At any time show the total number of cups of each size sold.
At any time show the total amount of coffee sold.
At any time show the total money made.
Your program should consist of at least the following functions: a function to show the user how to use the program, a function to sell coffee, a function to show the number of cups of each size sold, a function to show the total amount of coffee sold, and a function to show the total money made. Your program should not use any global variables.  Special values such as coffee cup sizes and cost of a coffee cup must be declared as named constants.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// user defined functions
void menu(); // main menu
void pos(double smCoffee, double mdCoffee, double lgCoffee); // Point of Sale (POS) menu
void cupsSold(int sumSM, int sumMD, int sumLG); // breaks down the sales by cup
void combinedCupsSold(int sumSM, int sumMD, int sumLG); // Combines all the cups sold
void totalMoneyEarned(double smIn, double mdIn, double lgIn); // shows total earnings
void help(); // instructions

// start main
int main()
{
    // variables needed by different functions
	int choice, sumSmCups = 0, sumMdCups = 0, sumLgCuos = 0;
	double sumSmMoney = 0, sumMdMoney = 0, sumLgMoney = 0;

		do // do...while loop to keep the menu/program running
		{
		    menu(); // calls menu function
            cin >> choice; // selection from the menu
            cout << endl;

			switch (choice) // switch for the menu selections
			{
            case 1:
                    int posSelect, numScups, numMcups, numLcups; // variables for section
                    do
                    {
                        cout << fixed << showpoint << setprecision(2); // formating
                        const double SMCOFFEE = 1.75, MDCOFFEE = 1.90, LGCOFFEE = 2.00; // constants
                        pos(SMCOFFEE, MDCOFFEE, LGCOFFEE); // point of sale menu
                        cin >> posSelect; // point of sale select
                        cout << endl;

                        switch (posSelect)
                        {
                        case 1:
                                cout << "You have chosen a small coffee.\n";
                                cout << "How many cups would you like? ";
                                cin >> numScups;
                                cout << endl;
                                cout << "The total for your coffee will be " << numScups * SMCOFFEE << endl;
                                sumSmCups = sumSmCups + numScups;
                                sumSmMoney = sumSmMoney + (numScups * SMCOFFEE);
                                break;
                        case 2:
                                cout << "You have chosen a medium coffee.\n";
                                cout << "How many cups would you like? ";
                                cin >> numMcups;
                                cout << endl;
                                cout << "The total for your coffee will be " << numMcups * MDCOFFEE << endl;
                                sumMdCups = sumMdCups + numMcups;
                                sumMdMoney = sumMdMoney + (numMcups * MDCOFFEE);
                                break;
                        case 3:
                                cout << "You have chosen a large coffee.\n";
                                cout << "How many cups would you like? ";
                                cin >> numLcups;
                                cout << endl;
                                cout << "The total for your coffee will be " << numLcups * LGCOFFEE << endl;
                                sumLgCuos = sumLgCuos + numLcups;
                                sumLgMoney = sumLgMoney + (numLcups * LGCOFFEE);
                                break;
                        case 99:
                                break;
                        default:
                                cout << "This is not a valid choice.\n";
                        }
                    }
                    while (posSelect != 99); // return to main menu
					break;
			case 2:
					cupsSold(sumSmCups, sumMdCups, sumLgCuos); // individual cups sold function is called
					system("Pause");
					break;
			case 3:
					combinedCupsSold(sumSmCups, sumMdCups, sumLgCuos);  // combined cups function is called
					system("Pause");
					break;
			case 4:
                    totalMoneyEarned(sumSmMoney, sumMdMoney, sumLgMoney); // total earning function is called
                    system("Pause");
					break;
            case 5:
                    help(); // help function is called
                    system("Pause");
                    break;
			case 99: // quits program
					break;
			default:
				cout << "That is not a valid choice.\n";
			}
		}
		while (choice != 99);


    system("Pause");
	return 0;
} // end main

void menu() // main menu
{
	cout << "***********MAIN MENU***********\n";
	cout << "**[1]:  POINT OF SALE MENU   **\n";
	cout << "**[2]:  INDIVIDUAL CUPS SOLD **\n";
	cout << "**[3]:  TOTAL CUPS SOLD      **\n";
	cout << "**[4]:  TOTAL EARNINGS       **\n";
	cout << "**[5]:  HELP                 **\n";
	cout << "**[99]: Exits the program.   **\n";
	cout << "*******************************\n";
	cout << "Your Choice: [1,2,3,4,5,99]? ";

	}

void pos(double smCoffee, double mdCoffee, double lgCoffee) // point of sale menu
{
    cout << "******POINT OF SALE MENU******\n";
	cout << "**[1]: Small Coffee  (9oz)  **\n";
	cout << "**[2]: Medium Coffee (12oz) **\n";
	cout << "**[3]: Large Coffee  (15oz) **\n";
	cout << "**[99]: Return to main menu **\n";
	cout << "******************************\n";
	cout << "Your Choice: [1,2,3,99]? ";
}

void cupsSold(int sumSM, int sumMD, int sumLG)
{
    cout << "*****CUPS SOLD*****\n";
    cout << "** SMALL:  " << setw(5) << sumSM << " **\n";
    cout << "** MEDIUM: " << setw(5) << sumMD << " **\n";
    cout << "** LARGE:  " << setw(5) << sumLG << " **\n";
    cout << "*******************\n";
}

void combinedCupsSold(int sumSM, int sumMD, int sumLG)
{
    cout << "******COMBINDED CUPS SOLD******\n";
    cout << "** TOTAL: " << setw(5) << sumLG + sumMD + sumSM << "              **\n";
    cout << "*******************************\n";
}

void totalMoneyEarned(double smIn, double mdIn, double lgIn)
{
    cout << "*****TOTAL SALES BREAKDOWN*****\n";
    cout << "** Small Coffee:       " << setw(5) << smIn << " **\n";
    cout << "** Medium Coffee:      " << setw(5) << mdIn << " **\n";
    cout << "** Large Coffee:       " << setw(5) << lgIn << " **\n";
    cout << "*******************************\n";
    cout << "** Total:              " << setw(5) << smIn + mdIn + lgIn << " **\n";
    cout << "*******************************\n";
}
void help()
{
    cout << "****************************************************************************\n";
    cout << "** Thank you for choosing my program!                                     **\n";
    cout << "** Use your keyboard to input the menu selections                         **\n";
    cout << "** [99] is used to quit the program and return to the main menu           **\n";
    cout << "** If you have any issues or suggestions with this Point of sale software **\n";
    cout << "** contact us at posmenu@possales.com  Thank you.                         **\n";
    cout << "****************************************************************************\n";
}
