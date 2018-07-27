//******************************************************************************
// entrances.cpp
// Find's the closest subway entrance, given a latitude and longitude.
//******************************************************************************
// Name: Gabriel Etrata
// Class: MTH 3300
// Professor: Evan Fink
// Homework_9
//******************************************************************************
// Collaborators/outside sources used: http://www.cplusplus.com/reference/algorithm/min_element/
//******************************************************************************
// @author Gabriel Etrata
// @version 1.0 05/20/17
//******************************************************************************
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

/** Computes the difference between the user's latitude and the subway entrance's latitude.
 
 @param userLatitude the user's latitude
 @param subwayLatitude the subway entrance's latitude
 
 @return diff the difference between the user's latitude and the subway entrance's latitude
 */
double diffInLatitude(double userLatitude, double subwayLatitude)
{
    double diff = (userLatitude - subwayLatitude) * 111.048;
    return diff;
}

/** Computes the difference between the user's longitude and the subway entrance's longitude.
 
 @param userLongitude the user's longitude
 @param subwayLongitude the subway entrance's longitude
 
 @return diff the difference between the user's longitude and the subway entrance's longitude
 */
double diffInLongitude(double userLongitude, double subwayLongitude)
{
    double diff = (userLongitude - subwayLongitude) * 84.515;
    return diff;
}

/** Computes the distance between the user's location and the subway entrance's location.
 
 @param userLatitude the user's latitude
 @param subwayLatitude the subway entrance's latitude
 @param userLongitude the user's longitude
 @param subwayLongitude the subway entrance's longitude
 
 @return distance the distance between the user's location and the subway entrance's location
 */
double distance(double userLatitude, double subwayLatitude, double userLongitude, double subwayLongitude)
{
    double distance = sqrt(pow((diffInLatitude(userLatitude, subwayLatitude)), 2) + pow((diffInLongitude(userLongitude, subwayLongitude)), 2));
    return distance;
}

//Initializes the program and prompts user input
int main(){
    
    
    vector<string> listOfNames; //holds a list of Subway Entrance names
    string line;
    ifstream names ("entrancenames.txt");
    if(names.is_open()){
        while ( getline (names ,line) )
            listOfNames.push_back(line);
    }
    
    
    vector<string> listOfSubwayLines; //holds a list of Subway Lines
    string station;
    ifstream subwayLines ("lines.txt");
    if(subwayLines.is_open()){
        while ( getline (subwayLines, station) ){
            listOfSubwayLines.push_back(station);
        }
    }
    
    vector<double> listOfLatitudes; //holds a list of Subway Station latitudes
    vector<double> listOfLongitudes; //holds a list of Subway Station longitudes
    double latitude;
    double longitude;
    ifstream coordinates ("coords.txt");
    if(coordinates.is_open()){
        while(coordinates >> latitude >> longitude){
            listOfLatitudes.push_back(latitude);
            listOfLongitudes.push_back(longitude);
        }
    }
    
    int numOfEntrances = 1905; //for speeding up the algorithm, since there are 1905 Subway Entrances
    double userLatitude;
    double userLongitude;
    cout << "Input your latitude: ";
    cin >> userLatitude;
    cout << "Input your longitude: ";
    cin >> userLongitude;
    
    vector<double> distancesFromUser;
    for(int i = 0; i < numOfEntrances - 1; i++){
        distancesFromUser.push_back( distance(userLatitude, listOfLatitudes.at(i), userLongitude, listOfLongitudes.at(i)) );
    }

    double minValue =  min_element(distancesFromUser.begin(), distancesFromUser.end()) - distancesFromUser.begin();
    cout << "Closest station: " <<  listOfNames.at(minValue) << endl;
    cout << "Trains: " << listOfSubwayLines.at(minValue) << endl;
    cout << "Distance is " << distance(userLatitude, listOfLatitudes.at(minValue), userLongitude, listOfLongitudes.at(minValue)) << "km" << endl;
    

    system("pause");
    return 0;   
}


