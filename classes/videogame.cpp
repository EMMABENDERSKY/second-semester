#include <iostream>
#include <cstring>
#include "videogame.h"

using namespace std;

videogame::videogame()
{
  publisher = new char[80];
  rating = 0;
}

videogame::~videogame()
{
  delete publisher;
  cout << "Videogame deleted!" << endl;
}

videogame::videogame(char* newPublisher, int newRating)
{
  publisher = new char[80];
  strcpy(publisher, newPublisher);
  rating = newRating;
}

char* videogame::getPublisher()
{
  return publisher;
}

int videogame::getRating()
{
  return rating;
}

void videogame::printStuff()
{
  cout << "Publisher: " << publisher << ", Rating: " << rating << endl;
}
