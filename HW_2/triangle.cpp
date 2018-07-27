//******************************************************************************
// triangle.cpp
// Computes the angles of any triangle, given the sides in descending order and
// using the Laws of Sines and Cosines.
//******************************************************************************
// Name: Gabriel Etrata
// Class: MTH 3300
// Professor: Evan Fink
// Homework_2
//******************************************************************************
// Collaborators/outside sources used:
// https://www.tutorialspoint.com/cplusplus/cpp_functions.htm
//******************************************************************************
// @author Gabriel Etrata
// @version 1.0 02/14/17

#include<iostream>
#include<stdlib.h>
#include<cmath>

using namespace std;

const double PI = 3.14159265358979323846; //the mathematical constant pi
double largestAngle; // variable that holds the value of the largest angle
double middleAngle; // variable that holds the value of the second-largest angle
double smallestAngle; // variable that holds the value of the smallest angle

/**
    Computes the Law of Cosines for angle a of the triangle.
 
    @param sideA the side of largest value
    @param sideB the side of second-largest value
    @param sideC the side of least value
    @return gamma angle a
 
*/
double lawOfCosines(double sideA, double sideB, double sideC)
{
    double gamma = (acos( (pow(sideB, 2) + pow(sideC, 2) - pow(sideA, 2) ) / (2 * sideB * sideC) ));
    largestAngle = gamma;
    
    return gamma;
}

/**
 Computes the Law of Sines for angle b of the triangle.
 
    @param largestAngle angle opposite side A
    @param sideA the side of largest value
    @param sideB the side of second-largest value
    @return theta angle b
 
*/
double lawOfSines(double largestAngle, double sideA, double sideB)
{
    double theta = asin( (sideB * sin(largestAngle) ) / (sideA) );
    middleAngle = theta;
    
    return theta;
}

/**
 Computes the smallest angle of the triangle.
 
    @param largestAngle the largest angle
    @param middleAngle the second-largest angle
    @return smallAngle the smallest angle
 
 */
double computeSmallestAngle(double largestAngle, double middleAngle)
{
    double smallAngle = PI - largestAngle - middleAngle;
    smallestAngle = smallAngle;
    
    return smallAngle;
}

/**
 Converts a value from radians to degrees.
 
    @param rad the value in radians
    @return degrees the value in degrees
*/
double convertToDegrees(double rad)
{
    double degrees = rad * (180/PI);
    
    return degrees;
}

//Initializes the program
int main()
{
    cout << "Welcome to Triangle_Angle_Calculator_v1.0." << endl;
    double sideA;
    double sideB;
    double sideC;
    
    cout << "In descending order, enter values for the sidelengths of a triangle." << endl;
    cin >> sideA >> sideB >> sideC;
   
    lawOfCosines(sideA, sideB, sideC);
    lawOfSines(largestAngle, sideA, sideB);
    computeSmallestAngle(largestAngle, middleAngle);
    largestAngle = convertToDegrees(largestAngle);
    middleAngle = convertToDegrees(middleAngle);
    smallestAngle = convertToDegrees(smallestAngle);
    
    cout << "Angle a = " << largestAngle << " degrees." << endl;
    cout << "Angle b = " << middleAngle << " degrees." << endl;
    cout << "Angle c = " << smallestAngle << " degrees." <<endl;
    
    system("pause");
    return 0;   
}

