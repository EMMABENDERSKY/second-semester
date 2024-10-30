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
  videogame(char*, int);
  char* getPublisher();
  int getRating();
};
#endif
