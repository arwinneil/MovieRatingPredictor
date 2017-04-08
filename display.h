#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void displaySplash (){
//function displays splash stored in a  file
    string line;//line buffer
    ifstream splash("splash.txt"); //opens splash file for input

        while (getline(splash,line)){
            cout<<line<<endl;
        }

        splash.close(); //close the file
}

void displayMenu(){

    //function displays the main menu

    system("CLS");
    displaySplash();

    cout<<"1. PREDICT AN OUTPUT"<<endl;
    cout<<"2. UPDATE DATASET"<<endl<<endl;

    cout<<"0. EXIT"<<endl;
}
#endif // DISPLAY_H_INCLUDED
