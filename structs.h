#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include <iostream>
#include <string>
#include<fstream>


struct movie {  //Structure for movie
  int duration;
  int budget;
  string age_rating;
  string genre;
  float rating;
} ;

struct point{  //Structure representing two points on a graph
   double x;
   double y;
};




#endif // STRUCTURES_H_INCLUDED
