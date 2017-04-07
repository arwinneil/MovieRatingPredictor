#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED
#include <iostream>
#include <string>
#include<fstream>

using namespace std;

string getDataPath(){
    //function prompts user to input file path, gets the path and
    //checks input for correct file extension, then checks if file
    //exists. Errors are displayed for appropriate scenarios.

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

                                cout<<"Internal file structure validated!"<<endl;
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


#endif // OPERATION_H_INCLUDED
