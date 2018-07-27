//******************************************************************************
// payroll.cpp
// Computes bi-weekly paycheck of employees.
//******************************************************************************
// Name: Gabriel Etrata
// Class: MTH 3300
// Professor: Evan Fink
// Homework_5
//******************************************************************************
// Collaborators/outside sources used: NONE
//******************************************************************************
// @author Gabriel Etrata
// @version 1.0 03/19/17

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/** Computes employee's paycheck.
 
 @param week1 Hours worked during first week
 @param week2 Hours worked during second week
 @param rate Worker's hourly wage
 
 @return totalPay
 */
double paycheckCalculator(int week1, int week2, double rate){
    double weekOnePay;
    double weekTwoPay;
    double totalPay;
    
    //Computes the first week's paycheck and will adjust for time-and-a-half ( > 40hrs/week)
    if(week1 > 40) {
        weekOnePay = (40 * rate) + ((rate * 1.5 * (week1 - 40)));
    }else {
        weekOnePay = week1 * rate;
    }
    
    if(week2 > 40) {
        weekTwoPay = (40 * rate) + ((rate * 1.5 * (week2 - 40)));
    }else {
        weekTwoPay = week2 * rate;
    }
    
    totalPay = weekOnePay + weekTwoPay;

    return totalPay;
}

//Initializes the program, reads in "timesheet.txt" and writes to "checks.txt."
int main()
{
    string firstName, lastName; //first and last name of the employee
    int week1, week2; //hours worked during the first and second weeks
    double payRate; //worker's hourly wage
    
    ifstream timeSheet;
    timeSheet.open("timesheet.txt");
    ofstream checks;
    checks.open("checks.txt");
    
    for(int i = 0; i < 5; i++){ //reads 5 lines of the text file, since there are 5 employees
    timeSheet >> firstName >> lastName >> week1 >> week2 >> payRate;
    checks << lastName << ", " << firstName << ": " << "$"  << setprecision(2) << fixed << paycheckCalculator(week1, week2, payRate) << endl;
    }
    
    timeSheet.close();
    checks.close();
   
    system("pause");
    return 0;   
}

