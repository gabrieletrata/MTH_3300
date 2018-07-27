//******************************************************************************
// population.cpp
// A program that calculates the exponential growth of population, n-number of
// times.
//******************************************************************************
// Name: Gabriel Etrata
// Class: MTH 3300
// Professor: Evan Fink
// Homework_2
//******************************************************************************
// Collaborators/outside sources used:
// https://www.tutorialspoint.com/cplusplus/cpp_do_while_loop.htm
// https://www.tutorialspoint.com/cplusplus/cpp_functions.htm
//******************************************************************************
// @author Gabriel Etrata
// @version 1.0 02/14/17

#include<iostream>
#include<stdlib.h>
#include<cmath>

using namespace std;

int n; //number of iterations
double p_0; //the inital population
double const e = 2.71828183; // Euler's constant
double r; //the relative growth rate
double t; // time period
double p; //calculated population
int counter = 0; // tracks number of iterations
double newVal; //stores the value of p

/** Returns the population of the exponential growth function, given the initial population, relative growth rate, and time.
 
    @param p_0 The initial population
    @param e Euler's constant
    @param r The relative growth rate
    @param t The time period
    @return p The final population at a given time
*/

double exponentialGrowth(double p_0, double const e, double r, double t)
    {
        counter += 1;
        double p = p_0 * pow(e, (r * 0.01) * t);
        cout << "Iteration (" << counter << "): " <<  "The current population is " << p  << " people." <<endl;
        newVal = p;
        return p;
    }

//Initializes the program and prompts user input.
int main()
{
    cout << "Welcome to Exponential_Growth_Calculator_v1.0" << endl;
    cout << "How many iterations would you like to go through?" << endl;
    cin >> n;
    cout << "Please enter a value for the initial population." << endl;
    cin >> p_0;

    do{
    
    if(counter > 0)
    {
        p_0 = newVal;
    }
        
    cout << "Please enter a value for the rate of growth as a percentage (omit the % symbol)." << endl;
    cin >> r;
    
    cout <<"Please enter a value for the time period in years." << endl;
    cin >> t;
    
    exponentialGrowth(p_0, e, r, t);
    
    }while(counter < n);

    system("pause");
    return 0;
}



