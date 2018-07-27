//******************************************************************************
//parks.cpp
//Program that determines the closest park (Central Park, Prospect Park,
//or Corona Park) based on a given latitude and longitude.
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

double centralPark [] = {40.782800, -73.965269}; //coordinates for Central Park
double prospectPark [] = {40.660217, -73.968948}; //coordinates for Prospect Park
double coronaPark [] = {40.739694, -73.840793}; // coordinates for Corona Park

/** Computes the difference between the user's latitude and the park's latitude.
 
 @param userLatitude the user's latitude
 @param parkLatitude the park's latitude

 @return diff the difference between the user's latitude and the park's latitude
 */
double diffInLatitude(double userLatitude, double parkLatitude)
{
    double diff = (userLatitude - parkLatitude) * 111.048;
    return diff;
}

/** Computes the difference between the user's longitude and the park's longitude.
 
 @param userLongitude the user's longitude
 @param parkLongitude the park's longitude
 
 @return diff the difference between the user's longitude and the park's longitude
 */
double diffInLongitude(double userLongitude, double parkLongitude)
{
    double diff = (userLongitude - parkLongitude) * 84.515;
    return diff;
}

/** Computes the distance between the user's location and the park's location.
 
 @param userLatitude the user's latitude
 @param parkLatitude the park's latitude
 @param userLongitude the user's longitude
 @param parkLongitude the park's longitude
 
 @return distance the distance between the user's location and the park's location
 */
double distance(double userLatitude, double parkLatitude, double userLongitude, double parkLongitude)
{
    double distance = sqrt(pow((diffInLatitude(userLatitude, parkLatitude)), 2) + pow((diffInLongitude(userLongitude, parkLongitude)), 2));
    return distance;
}

//Initializes the program and prompts user input.
int main()
{
    double latitude; //holds user's inputed latitude
    double longitude; //holds user's inputed longitude
    double d1;
    double d2;
    double d3;
    string close = " is the closest park.";
    cout << "Enter Latitude: ";
    cin >> latitude;
    
    cout << "Enter Longitude: ";
    cin >> longitude;

    d1 = distance(latitude, centralPark[0], longitude, centralPark[1]); //distance between user's location and Central Park
    d2 = distance(latitude, prospectPark[0], longitude, prospectPark[1]); //distance between user's location and Prospect Park
    d3 = distance(latitude, coronaPark[0], longitude, coronaPark[1]); //distance between user's location and Corona Park
    
    cout << "Central Park is " << d1  << " km away." << endl;
    cout << "Prospect Park is " << d2 << " km away." << endl;
    cout << "Corona Park is " << d3 << " km away." << endl;
    
    if(d1 < d2 && d1 < d3){ //checks if Central Park has the shortest distance
        cout << "Central Park" << close  << endl;
    }else if(d2 < d1 && d2 < d3){ //checks if Prospect Park has the shortest distance
        cout << "Prospect Park" << close << endl;
    }else if(d3 < d1 && d3 < d2){ //checks if Corona Park has the shortest distance
        cout << "Corona Park" << close << endl;
    }

    system("pause");
    return 0;   
}

