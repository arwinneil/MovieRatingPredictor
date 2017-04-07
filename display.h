#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void displaySplash (){
//function displays splash from file
    string line;//line buffer
    ifstream splash("splash.txt");

        while (getline(splash,line)){
            cout<<line<<endl;
        }

        splash.close();
}
#endif // DISPLAY_H_INCLUDED
