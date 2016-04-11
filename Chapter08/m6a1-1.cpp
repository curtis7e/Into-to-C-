#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void fillArrayRoot(double list[], int listsize); //Function take the index's square root
void fillArrayTimes(double list[], int listsize); // function to multiply the index by 3
void printArray(double list[], int listsize); // Function to Print array in rows of 10

int main()
{
    double alpha[50]; // initialize the array

	fillArrayRoot(alpha, 25); // call function to fill array with first 25
	fillArrayTimes(alpha, 50); // call function to fill array with the last 25
	printArray(alpha, 50); // prints array in rows of 10

    cout << endl;

	system("Pause");
    return 0;
}

void fillArrayRoot(double list[], int listsize)
{
	// int index;

	for (int index = 0; index < listsize; index++)
		list[index] = sqrt(index);
}

void fillArrayTimes(double list[], int listsize)
{
	//int index;

	for (int index = 25; index < listsize; index++)
		list[index] = 3 * index;
}

void printArray(double list[], int listsize)
{
    int j = 1;
	for (int index = 0; index < listsize; index++){
        if(!(j % 11)) {j = 1; cout << "\n";}
        cout << list[index] << " ";
        ++j;
	}
}
