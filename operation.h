#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED
#include <iostream>
#include <string>
#include<fstream>
#include<structs.h>

using namespace std;

string getDataPath(){


    //function prompts user to input file path, gets the path and
    //checks input for correct file extension, then checks if file
    //exists,then check if the file is an appropriate dataset.
    // Errors are displayed for appropriate scenarios.

    string path;
    bool valid=0;

    do{

        cout<<"Please enter CSV dataset path to start : ";
        getline(cin,path);

        if (path.size()<4){

             cout<<"Invalid path, please input correct file path."<<endl<<endl;

        }else{

            if (path.substr((path.size()-4),4)!= ".csv"){
                cout<<"Wrong extension, please input correct file path."<<endl<<endl;

                }else{
                        const char* file_ = path.c_str(); //converts string to char*
                        ifstream checkfile(file_);

                        if(checkfile.good()){           //Checks if file exists

                            checkfile.close();

                             cout<<"Checking internal file structure..."<<endl;

                             ifstream file(path.c_str());
                             string checkline;
                             file>>checkline;

                             if (checkline=="movie_title,genres,duration,content_rating,budget,imdb_score"){

                                cout<<"Internal file structure validated!"<<endl<<endl;
                                valid=1;
                             }else{

                              cout<<"Internal file structure invalidate, CSV format is movie_title,genres,duration,content_rating,budget,imdb_score"<<endl<<endl;
                              valid=0;
                             }

                        }else{
                                cout<<"File does not exist or is corrupt."<<endl<<endl;
                                checkfile.close();

                             }
                    }
        }



    }while(valid==0);

        cout<<"File loaded successfully. ";
        system("pause");

    return path;
}

string getMenuInput(){

    //function prompts user to enter menu choice
    //loops until a valid choice is made
    string choice;
    bool valid=0; //for checking if user input is valid;

    do{

        cout<<endl<<"Please enter 1,2 or 0 :";
        cin>>choice;

        if((choice=="1")|(choice=="2")|(choice=="0")){
            valid=1;
        }else{
        cout<<endl<<"Invalid choice!";
        }

    }while(valid==0);


    return choice;

}

movie getMovieDetails(){
    //function gets movie details from user and returns it as movie
     movie new_movie;

    cout<<endl<<"*******************   Movie Dataset Update   ***********************"<<endl<<endl;

    cout<<"Enter movie title: ";getline(cin.ignore(),new_movie.title);
    cout<<"Enter movie genres (Separate genres with '|', no spaces ): ";getline(cin.ignore(),new_movie.genre);
    cout<<"Enter movie duration (min): ";cin>>new_movie.duration;
    cout<<"Enter movie age rating : ";cin>>new_movie.age_rating;
    cout<<"Enter movie budget ($): ";cin>>new_movie.budget;
    cout<<"Enter movie rating (0.0-10.0) : ";cin>>new_movie.rating;

}

void predictRating(string path){

}

void addNewData(string path){
    //gets movie details
    //appends details to dataset

    movie new_movie=getMovieDetails();

    ofstream file(path,ios::app); //Opening file for append

    file<<endl<<new_movie.title<<","<<new_movie.genre<<","<<new_movie.duration<<","<<new_movie.age_rating<<","<<new_movie.budget<<","<<new_movie.rating;

    file.close();

    cout<<endl<<"Dataset updated, program will return to main menu.";
    system("pause");
}

#endif // OPERATION_H_INCLUDED
