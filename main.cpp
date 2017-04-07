#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <operation.h>
#include <display.h>
using namespace std;

string data_path; //Stores path to movie database


int main(){

   // displaySplash();

   // data_path=getDataPath();

    displayMenu();

    string choice =getMenuInput();

    if(choice=="1"){

    }else if (choice=="2"){

    }else{
        cout<<endl<<"Movie Rating Predictor will now exit...";
        system("pause");
        return 0;
    }

    return 0;
}



