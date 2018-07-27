//******************************************************************************
// twins.cpp
// Determines twin primes between a given range (inclusive) inputed by user.
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

using namespace std;

/**Determines if an integer is prime
    @param n an integer
 
    @return prime returns true if n is prime, otherwise false
 */
bool is_prime(int n){
    bool prime = true;
    for(int i = 2; i <= n / 2; i++){
        if(n % i == 0){
            prime = false;
        }
    }
    return prime;
}

//Initializes the program and prompts user input
int main()
{
    int p, q; //range of values

    cout << "Input two positive integers p and q; p > q." << endl;
    cin >> p >> q;
    
    cout << "Twin primes between " << p << " and " << q << ":" << endl;
    for(int i = p; i < q; i++){ //iterates through range of values
        if(is_prime(i) && is_prime(i+2)){ //checks if i and the second integer followed by it are prime
            cout << "(" << i << ", " << i + 2 <<  ")" << endl; //prints out twin primes
        }
    }
    
    system("pause");
    return 0;   
}

