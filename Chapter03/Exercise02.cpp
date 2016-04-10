/*
Three employees in a company are up for a special pay increase. You are given a file, Ch3_Ex7Data.txt, with the following data:

Miller Andrew 65789.87 5

Green Sheila 75892.56 6

Sethi Amit 74900.50 6.1

Each input line consists of an employee's last name, first name, current salary, and percent pay increase. For example, in the first input line, the last name of the employee is Miller, the first name is Andrew, the current salary is 65789.87, and the pay increase is 5%. Write a program that reads data from the specified file and stores the output in the file Ch3_Ex7Output.dat. For each employee, the data must be output in the following form: firstName lastName updatedSalary. Format the output of decimal numbers to two decimal places.
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	ifstream inFile; //input file stream variable
	ofstream outFile; //output file stream variable

	string firstLast, secondLast, thirdLast, firstFirst, secondFirst, thirdFirst; // All names to be read from file
	double firstSal, secondSal, thirdSal, oneInc, twoInc, threeInc; // read numbers from file
	double updatedSalaryone, updatedSalarytwo, updatedSalarythree; // updated salary

	inFile.open("Ch3_Ex7Data.txt"); //opens the input file
	outFile.open("Ch3_Ex7Output.dat"); // creates output file

	outFile << fixed << showpoint << setprecision(2); //sets the format for the output file

	cout << "Calculating pay increase..." << endl; // not sure if this is needed or not

	inFile >> firstLast >> firstFirst >> firstSal >> oneInc >> secondLast >> secondFirst >> secondSal >> twoInc >> thirdLast >> thirdFirst >> thirdSal >> threeInc;
	// ^^^^^^ reading from file in order ^^^^^^^^^^^^^^^^^^

	updatedSalaryone = firstSal * (oneInc / 100); // 65789.87 * (5 / 100) = 3289.4935
	updatedSalaryone = firstSal + updatedSalaryone; // 65789.87 + 3289.4935 = 69079.3635
	updatedSalarytwo = secondSal * (twoInc / 100); // 75892.56 * (6 / 100) = 4553.5536
	updatedSalarytwo = secondSal + updatedSalarytwo; // 75892.56 + 4553.5536 = 80446.1136
	updatedSalarythree = thirdSal * (threeInc / 100); // 74900.50 * (6.1 / 100) = 4568.9305
	updatedSalarythree = thirdSal + updatedSalarythree; // 74900.50 + 4568.9305 = 79469.4305

	outFile << "Name" << setw(26) << "Updated Salary" << endl;// Top column
	outFile << firstFirst << " " << firstLast << setw(11) << updatedSalaryone << endl; // first person
	outFile << secondFirst << " " << secondLast << setw(12) << updatedSalarytwo << endl; // second person
	outFile << thirdFirst << " " << thirdLast << setw(14) << updatedSalarythree << endl; // third person

	// closing the files
	inFile.close();
	outFile.close();


	system("pause");
	return 0;
}
