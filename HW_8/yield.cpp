//******************************************************************************
// yield.cpp
// Calculates the yield of a bond.
//******************************************************************************
// Name: Gabriel Etrata
// Class: MTH 3300
// Professor: Evan Fink
// Homework_8
//******************************************************************************
// Collaborators/outside sources used: NONE
//******************************************************************************
// @author Gabriel Etrata
// @version 1.0 04/28/17

#include <iostream>
#include <stdlib.h>
#include <cmath>


using namespace std;

/** Yield of a bond with 3 payments
 @param b bond
 @param c1 first cashflow
 @param c2 second cashflow
 @param c3 third cashflow
 @param t1 year 1
 @param t2 year 2
 @param t3 year 3
 @param x0 initial approximation
 
 @return f_x the value of f(x0)
 */
double f_x(double b,double c1, double c2, double c3, double t1, double t2, double t3, double x0){
    double f_x = (c1 * exp(-x0 * t1)) + (c2 * exp(-x0 * t2)) + (c3 * exp(-x0 * t3)) - b;

    return f_x;
}

/** Derivative of yield of a bond with 3 payments
 @param b bond
 @param c1 first cashflow
 @param c2 second cashflow
 @param c3 third cashflow
 @param t1 year 1
 @param t2 year 2
 @param t3 year 3
 @param x0 initial approximation
 
 @return f_prime_x the value of f'(x0)
 */
double f_prime_x(double b,double c1, double c2, double c3, double t1, double t2, double t3, double x0){
    double f_prime_x = (-t1 * c1 * exp(-x0 * t1)) - (t2 * c2 *exp(-x0 * t2)) - (t3 * c3 * exp(-x0 * t3));
    
    return f_prime_x;
}

/** Newton's method to numerically approximate the value of the function.
 @param func the function
 @param deriv the derivative of the function
 
 @return next_X the nth approimate value of the function at x_N
 */
double next_X(double func, double deriv, double x0){
    double next_X = x0 - (func/deriv);
    
    return next_X;
}

// Initializes the program and prompts user input.

int main()
{
    double b, c1, c2, c3, t1, t2, t3, x0, newX;
    
    cout << "Input the respective constants to calculate the yield of the bond." << endl;
    cout << "b: ";
    cin >> b;
    cout << "c1:";
    cin >> c1;
    cout << "c2:";
    cin >> c2;
    cout << "c3:";
    cin >> c3;
    cout << "t1:";
    cin >> t1;
    cout << "t2:";
    cin >> t2;
    cout << "t3:";
    cin >> t3;
    cout << "Give an approximation for x_0: ";
    cin >> x0;
    
    for(int i = 0; i < 100; i++){
    newX = next_X(f_x(b, c1, c2, c3, t1, t2, t3, x0), f_prime_x(b, c1, c2, c3, t1, t2, t3, x0), x0);
    x0 = newX;
    }
    cout << "Output yield: " << newX * 100 << "%" << endl;
    
    //checks if solution a good approximation
    if(f_x(b, c1, c2, c3, t1, t2, t3, newX) > -0.0000001 && f_x(b, c1, c2, c3, t1, t2, t3, newX) < 0.0000001){
        cout << "Error: 0.0000001 < f(x_100) < 0.0000001. Good solution!" << endl;
    }

    system("pause");
    return 0;   
}

