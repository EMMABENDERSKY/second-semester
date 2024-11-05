#include <iostream>
#include <cstring>
#ifndef MOVIE_H
#define MOVIE_H
#include "media.h"

using namespace std;

class movie : public media
{
 private:
  char* director;
  int duration;
  int rating;
 public:
  movie();
  ~movie();
  movie(char*, int, char*, int, int);
  char* getDirector();
  int getDuration();
  int getRating();
  void printStuff();
};
#endif
