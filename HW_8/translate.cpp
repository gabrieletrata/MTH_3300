//******************************************************************************
// translate.cpp
// Translates .txt files from English to Spanish.
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
//******************************************************************************
// NOTE: THIS IS AN INCOMPLETE IMPLEMENTATION AND DOES NOT WORK

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

string translate(string wordToTranslate){
    string engWords[1000];
    ifstream engText;
    engText.open("english.txt");
    if(engText.is_open()){
        for(int i = 0; i < 1000; i++){
            engText >> engWords[i];;
        }
    }
    
    string espWords[1000];
    ifstream espText;
    espText.open("spanish.txt");
    string espWord;
    if(espText.is_open()){
        for(int i = 0; i < 1000; i++){
            espText >> espWords[i];
        }
    }
    
    int index = 0;
    for(int i = 0; i < 1000; i++){
        if(wordToTranslate == engWords[i]){
            index = i;
        }
    }
    
    return espWords[index];
}

int main(){
    
    string fileName;
    cout << "What is the filename?" << endl;
    cin >> fileName;
    ifstream engDoc;
    engDoc.open(fileName.c_str());
    if(engDoc.is_open()){
        string fileName2;
        cout << "What is the filename you are writing to?" << endl;
        cin >> fileName2;
        ofstream transDoc;
        transDoc.open(fileName2);
        string line;
        while(getline(engDoc,line)){
            transDoc << translate(line);
        }
    }
    
    //Tester code
    translate("afternoon");
    translate("alone");
    translate("hair");

    system("pause");
    return 0;   
}

