#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <operation.h>
#include <display.h>
using namespace std;

string data_path;               //Stores path to movie database

int main(){

    displaySplash();             //Displays MRP Splash logo

    data_path=getDataPath();     //Gets Dataset path

    do{displayMenu();             //Displays main menu until user choses to exit

        string choice =getMenuInput();
        if(choice=="1"){

            predictRating(data_path);   //Calls the the rating prediction function

        }else if (choice=="2"){

             addNewData(data_path);     //calls the function which will update dataset

        }else if (choice=="0"){

           break;                       //goes out of loop if 0 entered

        }else{

            cout<<endl<<"Choice Invalid"<<endl; //error message if input invalid

        }

    }while(true);

    cout<<endl<<"Movie Rating Predictor will now exit..."<<endl; //exit message
    system("pause");

    return 0;
}



