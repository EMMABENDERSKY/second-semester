#include <iostream>
#include <cstring>
#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "media.h"

using namespace std;

class videogame : public media
{
 private:
  char* publisher;
  int rating;
 public:
  videogame();
  ~videogame();
  videogame(char*, int, char*, int);
  char* getPublisher();
  int getRating();
  void printStuff();
};
#endif
