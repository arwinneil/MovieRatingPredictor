#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED
#include <iostream>
#include <string>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include <cstddef>
#include<structs.h>
#include<display.h>

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

    cout<<"Enter movie title: ";getline(cin.ignore(),new_movie.title);
    cout<<"Enter movie genres (Separate genres with '|', no spaces ): ";getline(cin.ignore(),new_movie.genre);
    cout<<"Enter movie duration (min): ";cin>>new_movie.duration;
    cout<<"Enter movie age rating : ";cin>>new_movie.age_rating;
    cout<<"Enter movie budget ($): ";cin>>new_movie.budget;

    return new_movie;
}

movie toMovie(string line){
     //function takes in a csv format data row and coverts it an object of type movie
        string comma=",";
        movie new_movie;

        new_movie.title= line.substr(0,(line.find(","))); //Reads title up to first comma
        line.erase(0,(line.find(",")+1));//erases string until and including first comma

        new_movie.genre= line.substr(0,(line.find(","))); //Reads genre up to first comma
        line.erase(0,(line.find(",")+1));//erases string until and including first comma

        new_movie.duration= (strtol((line.substr(0,(line.find(",")))).c_str(),0,10)); //Reads duration up to first comma
        line.erase(0,(line.find(",")+1));//erases string until and including first comma

        new_movie.age_rating= line.substr(0,(line.find(","))); //Reads age_rating up to first comma
        line.erase(0,(line.find(",")+1));//erases string until and including first comma

        new_movie.budget= strtol(line.substr(0,(line.find(","))).c_str(),0,10); //Reads budget up to first comma
        line.erase(0,(line.find(",")+1));//erases string until and including first comma

        new_movie.rating= strtof((line.substr(0,(line.find(",")))).c_str(),0); //Reads rating up to first comma

        return new_movie;
}

equation computeL2(string dataset,string independent_var){

    double SUMx = 0;     //sum of x values
    double SUMy = 0;     //sum of y values
    double SUMxy = 0;    //sum of x * y
    double SUMxx = 0;    //sum of x^2
    double SUMres = 0;   //sum of squared residue
    double res = 0;      //residue squared
    double slope = 0;    //slope of regression line
    double y_intercept = 0; //y intercept of regression line
    double SUM_Yres = 0; //sum of squared of the discrepancies
    double AVGy = 0;     //mean of y
    double AVGx = 0;     //mean of x
    double Yres = 0;     //squared of the discrepancies
    double Rsqr = 0;     //coefficient of determination

    point Point;

    int dataSize =0;

    movie movie_data;
    ifstream file(dataset); //Opening file input
    string buffer;

    getline(file,buffer);

    while (getline(file,buffer)){
            movie movie_buffer=toMovie(buffer);



            Point.y=movie_buffer.rating;
            if (independent_var=="duration"){
                Point.x=movie_buffer.duration;

            }else{
                Point.x=movie_buffer.budget;

            }

            SUMx = SUMx+Point.x;

            SUMy = SUMy+ Point.y;

            SUMxy = SUMxy + (Point.x*Point.y);

            SUMxx = SUMxx +(Point.x*Point.x);

            dataSize++;
    }
    file.close();



    cout<<endl<<"Least-Square Linear Regression of "<<independent_var<<" : " <<dataSize<<" records being processed..."<<endl;

        //calculate the means of x and y
        AVGy = SUMy / dataSize;
        AVGx = SUMx / dataSize;



    cout<<"Average "<<independent_var<<" is "<<SUMx<<endl;
    cout<<"Average rating is "<<AVGy<<endl;

     //slope or a1
   slope = (dataSize * SUMxy - SUMx * SUMy) / (dataSize * SUMxx - SUMx*SUMx);

   //y itercept or a0
   y_intercept = AVGy - slope * AVGx;



    cout<< ("The linear equation that best fits the given data:\n");
    cout<< "       y = "<<slope<<"x + "<<y_intercept<<endl;

    equation eqn;
    eqn.coeff=slope;
    eqn.y_intercept=y_intercept;
    return eqn;


}

void predictRating(string dataset){

    cout<<endl<<"*******************   Movie Rating Prediction   ***********************"<<endl<<endl;

    movie new_movie=getMovieDetails();

    equation eqn=computeL2(dataset,"duration");
    double duration_based_rating=new_movie.duration*eqn.coeff+eqn.y_intercept;
    cout<< "Predicted rating from duration : "<<duration_based_rating<<endl<<endl;

    eqn=computeL2(dataset,"budget");
    double budget_based_rating=new_movie.budget*eqn.coeff+eqn.y_intercept;
    cout<< "Predicted rating from budget : "<<budget_based_rating<<endl;


    system("pause");

}

void addNewData(string path){
    //gets movie details
    //appends details to dataset
    cout<<endl<<"*******************   Movie Dataset Update   ***********************"<<endl<<endl;

    movie new_movie=getMovieDetails(); //retrieve movie details from getMovieDetail functions
    cout<<"Enter movie rating (0.0-10.0) : ";cin>>new_movie.rating;

    ofstream file(path,ios::app); //Opening file for append

    file<<endl<<new_movie.title<<","<<new_movie.genre<<","<<new_movie.duration<<","<<new_movie.age_rating<<","<<new_movie.budget<<","<<new_movie.rating;

    file.close();

    cout<<endl<<"Dataset updated, program will return to main menu.";
    system("pause");
}

#endif // OPERATION_H_INCLUDED
