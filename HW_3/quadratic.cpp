//******************************************************************************
// quadratic.cpp
// Program that determines the roots of any given 2nd-degree polynomial.
//******************************************************************************
// Name: Gabriel Etrata
// Class: MTH 3300
// Professor: Evan Fink
// Homework_3
//******************************************************************************
// Collaborators/outside sources used: NONE
//******************************************************************************
// @author Gabriel Etrata
// @version 1.0 02/27/17

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <complex>

using namespace std;

/** Computes the determinant.
 
 @param a coefficient of 2nd-degree term
 @param b coefficient of 1st-degree term
 @param c coefficient of 0th degree term
 
 @return determinant the determinant
 */
double determinant(double a, double b, double c)
{
    double determinant = pow(b, 2) - 4*a*c;
    return determinant;
}

/** Computes the first root.
 
 @param a coefficient of 2nd-degree term
 @param b coefficient of 1st-degree term
 @param c coefficient of 0th degree term
 
 @return root1 first root
 */
double quadraticFormula_1(double a, double b, double c)
{
    double root1 = (-b - sqrt(determinant(a, b, c)) ) / (2*a);
    return root1;
}

/** Computes the second root.
 
 @param a coefficient of 2nd-degree term
 @param b coefficient of 1st-degree term
 @param c coefficient of 0th degree term
 
 @return root2 second root
 */
double quadraticFormula_2(double a, double b, double c)
{
    double root2 = (-b + sqrt(determinant(a, b, c) )) / (2*a);
    
    return root2;
}

/** Computes the real part of the 2nd-degree polynomial.
 
 @param a coefficient of 2nd-degree term
 @param b coefficient of 1st-degree term
 
 @return realPart the real part of the 2nd-degree polynomial
 */
double realPart(double a, double b)
{
    double realPart = -b/(2*a);
    return realPart;
}

/** Computes the complex part of the 2nd-degree polynomial.
 
 @param a coefficient of 2nd-degree term
 @param b coefficient of 1st-degree term
 @param c coefficient of 0th degree term
 
 @return complexPart the complex part of the 2nd-degree polynomial
 */
double complexPart(double a, double b, double c)
{
    double complexPart = sqrt(-determinant(a, b, c)) / (2*a);
    return complexPart;
}

//Initializes the program and prompts user input.
int main()
{
    double a; //coefficient of 2nd-degree term
    double b; //coefficient of 1st-degree term
    double c; //coefficient of 0th-degree term
    double r1; //first root
    double r2; //second root
    
    cout << "Enter 3 coefficients for the polynomial of the form: ax^2 + bx + c." << endl;
    cin >> a >> b >> c;
    if(a == 0)
    {
        cout << "Coefficient of x^2 = 0." << "\n" << "...";
        cout << "Interpreting input as linear function." << endl;
        cout << "The line y = " << b << "x + " << c << " equals zero at: " << -c/b << "." << endl;
        
    } else {
    
        cout << "Computing root(s) of the polynomial: " << "y = " << a << "x^2 + " << b << "x + " << c << endl;
        cout << "..." << endl;
    
        if(determinant(a, b, c) > 0) //checks if determinant is positive and if so, computes two, real roots
        {
            r1 = quadraticFormula_1(a, b, c);
            r2 = quadraticFormula_2(a, b, c);
            cout << setprecision(4) << "The first root = " << r1 << endl;
            cout << setprecision(4) << "The second root = " << r2 << endl;
        } else if(determinant(a, b, c) == 0) { //checks if determinant is equal to zero and if so, computes the single, real root
            r1 = quadraticFormula_2(a, b, c);
            cout << setprecision(4) << "The first and second root = " << r1 << endl;
        } else if(determinant(a, b, c) < 0){ //checks if determinant is negative, and if so, computes two, complex roots
            cout << setprecision(4) << "The first root = " << realPart(a, b) << " - " << complexPart(a, b, c) << "i" << endl;
            cout << setprecision(4) << "The second root = " << realPart(a, b) << " + " << complexPart(a, b, c) << "i" << endl;
        }
    }
    
    //system("pause");
    return 0;   
}

