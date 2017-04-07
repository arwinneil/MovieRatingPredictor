#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <UserInput.h>
using namespace std;

string data_path; //Stores path to movie database

void displaySplash (){
//function displays splash from file
    string line;//line buffer
    ifstream splash("splash.txt");

        while (getline(splash,line)){
            cout<<line<<endl;
        }

        splash.close();
}

int main(){

    displaySplash();

    data_path=getDataPath();
    cout<<"File loaded successfully. ";
    system("pause");

    return 0;
}



