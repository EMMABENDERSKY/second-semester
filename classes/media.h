#include <iostream>
#include <cstring>
#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class media
{
 protected:
  char* title;
  int year;
 public:
  media();
  media(char*, int);
  char* getTitle();
  int getYear();
};
#endif
