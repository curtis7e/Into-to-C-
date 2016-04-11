/*
 The history teacher at your school needs help in grading a True/False test.
 The students’ IDs and test answers are stored in a file. The first entry in the
 file contains answers to the test in the form:
 TFFTFFTTTTFFTFTFTFTT
 Every other entry in the file is the student ID, followed by a blank, followed by
 the student’s responses. For example, the entry:
 ABC54301 TFTFTFTT TFTFTFFTTFT
 indicates that the student ID is ABC54301 and the answer to question 1 is True,
 the answer to question 2 is False, and so on. This student did not answer question 9.
 The exam has 20 questions, and the class has more than 150 students. Each correct
 answer is awarded two points, each wrong answer gets one point deducted, and no
 answer gets zero points. Write a program that processes the test data.
 The output should be the student’s ID, followed by the answers, followed by
 the test score, followed by the test grade. Assume the following grade scale:
 90%–100%, A; 80%–89.99%, B; 70%–79.99%, C; 60%–69.99%, D; and 0%–59.99%, F.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// constant integers
const int QUESTIONS = 20;
const int STUDENTS = 150;

// initialize functions
void inputFile(ifstream& inFile); // opens the file
void gradeTest(char studentAnswers[][QUESTIONS], string studentIDs[], char answerKey[]); // grades the test
char assignGrade(int score); // assigns the grade

//main function
int main()
{
   string studentIDs[STUDENTS];
   char answerKey[QUESTIONS + 1];
   char studentAnswers[STUDENTS][QUESTIONS];
   ifstream inFile;

   inputFile(inFile);

   //read answer key
   inFile.getline(answerKey, '/n');

   // read student ID and answers
   for (int i = 0; i < STUDENTS; i++)
   {
       inFile >> studentIDs[i]; //store student IDS
       inFile.get(); // skips space
       for (int j = 0; j < QUESTIONS; j++)
            studentAnswers[i][j] = inFile.get(); // gets student answers
   }

   gradeTest(studentAnswers, studentIDs, answerKey);

    system("Pause");
    return 0;
} //end main

void gradeTest(char studentAnswers[][QUESTIONS], string studentIDs[], char answerKey[])
{
    for (int i = 0; i < STUDENTS; i++)
    {
        cout << "Student ID: " << studentIDs[i] << endl;
        int score = 0;
        cout << "Answers: ";
        for (int j = 0; j < QUESTIONS; j++)
        {
            cout << studentAnswers[i][j];
            if (studentAnswers[i][j] == answerKey[j])
                score += 2; // correct answer
            else if (studentAnswers[i][j] != answerKey[j] && studentAnswers[i][j] != ' ')
                score -= 1; // wrong answer
        }
        if (score < 0)
            score = 0; // no negative scores

        cout << endl;
        char grade = assignGrade(score);
        cout << "Grade: " << grade << endl << endl;
    }
}

char assignGrade(int score)
{
    double precentScore = static_cast<double>(score) / (QUESTIONS * 2);
    cout << "Score: " << precentScore*100 << "%" << endl;
    if (precentScore >= 0.9)
        return 'A';
    else if (precentScore >= 0.8)
        return 'B';
    else if (precentScore >= 0.7)
        return 'C';
    else if (precentScore >= 0.6)
        return 'D';
    else
        return 'F';
}

void inputFile(ifstream& inFile)
{
    inFile.open("testResults.txt");
    if (!inFile)
    {
        cout << "Could not open input file" << endl;
        exit(1);
    }
}
