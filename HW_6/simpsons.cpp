//******************************************************************************
// simpsons.cpp
// Approximates the integral of the probability density function using Simpson's rule.
//******************************************************************************
// Name: Gabriel Etrata
// Class: MTH 3300
// Professor: Evan Fink
// Homework_6
//******************************************************************************
// Collaborators/outside sources used: NONE
//******************************************************************************
// @author Gabriel Etrata
// @version 1.0 03/27/17

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

double exp (float);
double const pi = 4 * atan(1);

/** Probability density function
    @param x input value 
 
    @return phi value of the function at x
 */
double PDF(double x){
    double phi = (1/sqrt(2*pi)) * exp( -0.5 * pow(x, 2));
    return phi;
}

/** Simpson's rule for approximating an integral
 
 @param a lower limit
 @param b upper limit
 @param n number of intervals
 
 @return sum
 */
double simpson(double a, double b, int n){
    double deltaX = (b - a) / n;
    double sum = 0;
    
    for(int i = 0; i <= n; i++){
        double x_i = a + i * deltaX;
        if(i == 0 || i == n){ // checks if i the first or last term of the sum (coefficient of 1)
            sum += PDF(x_i);
        } else if (i % 2 == 0 && i != 0 && i != n) { // checks if i is an even term of the of the sum (multiply by coefficient of 2)
            sum += 2 * PDF(x_i);
        } else {
            sum += 4 * PDF(x_i); // checks if i is an odd term of the of the sum (multiply by coefficient of 4)
        }
    }
    
    sum *= (deltaX / 3); //multiply the sum of terms by (delta x) / 3
    cout << "The area under the curve is approximately: " << sum << endl;
    return sum;

}

//Initializes the program and prompts user input
int main()
{
    double a, b;
    int n;

    cout << "Input the upper limit." << endl;
    cin >> b;
    
    cout << "Input the lower limit." << endl;
    cin >> a;
    
    cout << "How many intervals? (N must be even)." << endl;
    cin >> n;

    simpson(a, b, n);
    
    system("pause");
    return 0;   
}

