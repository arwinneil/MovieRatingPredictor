#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <UserInput.h>
#include <display.h>
using namespace std;

string data_path; //Stores path to movie database


int main(){

    displaySplash();

    data_path=getDataPath();

    return 0;
}



