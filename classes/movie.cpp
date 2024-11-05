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

movie::~movie()
{
  delete director;
  cout << "Movie deleted!" << endl;
}

movie::movie(char* newTitle, int newYear, char* newDirector, int newDuration, int newRating)
{
  title = new char[80];
  strcpy(title, newTitle);
  year = newYear;
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

void movie::printStuff()
{
  cout << "Director: " << director << ", Duration: " << duration << ", Rating: " << rating << endl; 
}
