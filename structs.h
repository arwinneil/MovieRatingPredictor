#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include <iostream>
#include <string>
#include<fstream>
using namespace std;



struct movie {  //Structure for movie

    string title;
    string genre;
    int duration;
    string age_rating;
    int budget;
    float rating;
} ;

struct point{  //Structure representing two points on a graph
   double x;
   double y;
};




#endif // STRUCTURES_H_INCLUDED
