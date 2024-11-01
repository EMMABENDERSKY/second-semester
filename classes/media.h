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
  virtual ~media();
  media(char*, int);
  char* getTitle();
  int getYear();
  virtual void printStuff();
};
#endif
