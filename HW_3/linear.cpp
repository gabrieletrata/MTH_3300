//******************************************************************************
// linear.cpp
// Program that determines the equation of a line, given two points.
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

using namespace std;

/** Computes the slope (m) of the line.
    
 @param x1 x-coordinate of first point
 @param x2 x-coordinate of second point
 @param y1 y-coordinate of first point
 @param y2 y-coordinate of second point
 
 @return slope
*/
double slope(double x1, double x2, double y1, double y2)
{
    double slope = (y2 - y1)/(x2 - x1);
    return slope;
}

/** Computes the constant (b) of the line.
 
 @param x2 x-coordinate of second point
 @param y2 y-coordinate of second point
 
 @return constant
 */
double constant(double x2, double y2, double m)
{
    double constant =  y2 - (m*x2);
    return constant;
}

//Initializes the program and prompts user input.
int main()
{
    double x1; //holds value for x-coordinate of first point
    double x2; //holds value for x-coordinate of second point
    double y1; //holds value for y-coordinate of first point
    double y2; //holds value for y-coordinate of second point
    double m; //holds value for the slope (m) of the line
    double b; //holds value for the constant of the line
    char leftParen; //holds value for the char '('
    char rightParen; //holds value for the char ')'
    char comma; //holds value for the char ','
    char sign; //holds value for the sign of the constant, b of the line (either positive, or negative)
    
    cout << "Input two points in the form (x,y)." << endl;
    cout << "First point: ";
    cin >> leftParen >> x1 >> comma >> y1 >> rightParen;
    
    if(leftParen != '(' || comma != ',' || rightParen != ')')
    {
        cerr << "Error message : " << "Your input could not be read." << endl;
    }
    
    cout << "Second point: ";
    cin >> leftParen >> x2 >> comma >> y2 >> rightParen;
    
    if(leftParen != '(' || comma != ',' || rightParen != ')')
    {
        cerr << "Error message : " << "Your input could not be read." << endl;
    }
    
    m = slope(x1, x2, y1, y2);
    b = constant(x2, y2, m);
    
    if(b < 0) //checks for sign of b
    {
        sign = '-';
    
    }else{
        sign = '+';
    }
    
    if(m != 0) //checks if slope is not equal to zero and if so, include all terms of the line
    {
        cout << "Equation: " << "y = " << m << "x" << " " << sign << " " << abs(b) << endl;
    
    }else if (m == 0){ //checks if slope is not equal to zero and if so, exclude the 1st-degree term of the line
    
        if (sign == '+')
        {
            cout << "Equation: " << "y = " << " " << abs(b) << endl;
        }else{
            cout << "Equation: " << "y = " << sign << " " << abs(b) << endl;
        }
    }
    
    system("pause");
    return 0;   
}

