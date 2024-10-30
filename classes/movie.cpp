#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

movie::movie()
{
  director = new char[80];
  duration = 0;
  rating = 0;
}

movie::movie(char* newDirector, int newDuration, int newRating)
{
  director = new char[80];
  strcpy(director, newDirector);
  duration = newDuration;
  rating = newRating;
}

char* movie::getDirector()
{
  return director;
}

int movie::getDuration()
{
  return duration;
}

int movie::getRating()
{
  return rating;
}
