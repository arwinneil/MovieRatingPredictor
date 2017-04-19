#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include <iostream>
#include <fstream>
#include<structs.h>
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
    cout<<"2. UPDATE DATASET"<<endl;
    cout<<"3. USE ANOTHER DATASET"<<endl<<endl;
    cout<<"0. EXIT"<<endl;
}

//USAGE : DEBUGGING PURPOSES

//void displayMovie(movie new_movie){

//    //displays movie information from a object of type movie
//
//    //use DisplayMovie(movie) to check contents of a movie object at any point.
//
//        cout<<endl<<new_movie.title<<endl;
//        cout<<new_movie.genre<<endl;
//        cout<<new_movie.duration<<endl;
//        cout<<new_movie.age_rating<<endl;
//        cout<<new_movie.budget<<endl;
//        cout<<new_movie.rating<<endl;
//}

#endif // DISPLAY_H_INCLUDED
