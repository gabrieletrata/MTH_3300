//******************************************************************************
// madlibs.cpp
// A simple program that simulates the popular phrasal template word game. 
//******************************************************************************
// Name: Gabriel Etrata
// Class: MTH 3300
// Professor: Evan Fink
// Homework_2
//******************************************************************************
// Collaborators/outside sources used:
// NONE
//******************************************************************************
// @author Gabriel Etrata
// @version 1.0 02/14/17


#include<iostream>
#include<stdlib.h>

using namespace std;

//Initializes the program and prompts user input.
int main()
{
    cout << "Let's play some Mad Libs!" << endl;
    cout << "WARNING: DO NOT USE WHITESPACE WHEN ENTERING WORDS!" << endl;
    string x; //first noun
    string y; //second noun
    string z; //third noun
    
    cout << "Enter a name, or person." << endl;
    cin >> x;
    
    cout << "Enter a noun that can be read (book, paper, etc)." << endl;
    cin >> y;
    
    cout << "Enter one more noun, particularly one that is a subject." << endl;
    cin >> z;
    
    cout << x << " read a " << y << " about " << z << "s." <<endl;
    cout << x << " read a " << z << " about " << y << "s." <<endl;
    cout << y << " read a " << x << " about " << z << "s." <<endl;
    cout << y << " read a " << z << " about " << x << "s." <<endl;
    cout << z << " read a " << y << " about " << x << "s." <<endl;
    cout << z << " read a " << x << " about " << y << "s." <<endl;
    
    
    cout << "What's your name?" << endl;
    cin >> x;
    
    cout << "What's your favorite food?" << endl;
    cin >> y;
    
    cout << "What's your favorite place?" << endl;
    cin >> z;
    
    cout << x << " smoked a " << y << " out of a " << z << "." <<endl;
    cout << x << " smoked a " << z << " out of a " << y << "." <<endl;
    cout << y << " smoked a " << x << " out of a " << z << "." <<endl;
    cout << y << " smoked a " << z << " out of a " << x << "." <<endl;
    cout << z << " smoked a " << y << " out of a " << x << "." <<endl;
    cout << z << " smoked a " << x << " out of a " << y << "." <<endl;
    
    system("pause");
    return 0;   
}

