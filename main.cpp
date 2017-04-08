#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <operation.h>
#include <display.h>
using namespace std;

string data_path; //Stores path to movie database


int main(){

    displaySplash();

    data_path=getDataPath();

    do{displayMenu();

        string choice =getMenuInput();
        if(choice=="1"){

            predictRating(data_path);

        }else if (choice=="2"){

             addNewData(data_path);

        }else if (choice=="0"){

           break;

        }else{
            cout<<endl<<"Choice Invalid"<<endl;

        }

    }while(true);

    cout<<endl<<"Movie Rating Predictor will now exit..."<<endl;
    system("pause");

    return 0;
}



