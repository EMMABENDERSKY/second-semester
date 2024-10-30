#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

music::music()
{
  artist = new char[80];
  duration = 0;
  publisher = new char[80];
}

music::music(char* newArtist, int newDuration, char* newPublisher)
{
  artist = new char[80];
  strcpy(artist, newArtist);
  duration = newDuration;
  publisher = new char [80];
  strcpy(publisher, newPublisher);
}

char* music::getArtist()
{
  return artist;
}

int music::getDuration()
{
  return duration;
}

char* music::getPublisher()
{
  return publisher;
}
