#include <iostream>
#include <cstring>
#ifndef MUSIC_H
#define MUSIC_H
#include "media.h"

using namespace std;

class music : public media
{
 private:
  char* artist;
  int duration;
  char* publisher;
 public:
  music();
  music(char*, int, char*);
  char* getArtist();
  int getDuration();
  char* getPublisher();
};
#endif
