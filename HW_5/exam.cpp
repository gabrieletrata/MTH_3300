//******************************************************************************
// exam.cpp
// Computes the probability of passing an exam.
// This exam is 35 multiple choice questions, with 5 choices per question.
// A score of 11, or greater is considered a pass.
//******************************************************************************
// Name: Gabriel Etrata
// Class: MTH 3300
// Professor: Evan Fink
// Homework_5
//******************************************************************************
// Collaborators/outside sources used: @Evan Fink
//******************************************************************************
// @author Gabriel Etrata
// @version 1.0 03/19/17

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <iomanip>

using namespace std;

//Initializes program
int main()
{
    srand ((time(NULL))); //ignore precision error;
    int trials = 1e6;
    double questions[35];
    int questionsRight = 0;
    double numOfPasses = 0;
    double probability;
    
    for(int i = 0; i < trials; i++){ //runs 1e6 simulations
        questionsRight = 0; //reset questionsRight to 0 after each simulation
        for(int j = 0; j < 35; j++){ //runs through 35 questions
            questions[j] = ((rand() % 5) + 1);
            if(questions[j] == 5){
                questionsRight++; //if choice 5 is picked, increment questionsRight
            }
            if(questionsRight >= 11){
                numOfPasses++; //if questionsRight >= 11, increment numOfPasses
                questionsRight = 0; //reset questionsRight back to 0 after each exam trial is finished
            }
        }
     }
    
    probability = numOfPasses/trials; //compute the probability of event
    cout << setprecision (3) << probability << endl;

    system("pause");
    return 0;   
}

