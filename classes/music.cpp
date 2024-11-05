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

music::~music()
{
  delete artist;
  delete publisher;
  cout << "Music deleted! " << endl;
}

music::music(char* newTitle, int newYear, char* newArtist, int newDuration, char* newPublisher)
{
  title = new char[80];
  strcpy(title, newTitle);
  year = newYear;
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

void music::printStuff()
{
  cout << "Artist: " << artist << " Duration: " << duration << ", Publisher: " << publisher << endl;
}
