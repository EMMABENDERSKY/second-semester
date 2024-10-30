#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "movie.h"
#include "music.h"
#include "videogame.h"

using namespace std;

void addMedia(vector<media*> & mediaList);
void searchMedia(vector<media*> & mediaList);

int main()
{
  vector<media*> mediaList;
  while(true)
    {
      char command[10];
      cout << "Enter a command (ADD, SEARCH, DELETE, QUIT): " << endl;
      cin.get(command, 10);

      if(strcmp(command, "ADD") == 0)
	addMedia(mediaList);
      else if(strcmp(command, "SEARCH") == 0)
	{

	}
       else if(strcmp(command, "DELETE") == 0)
	 {

	 }
       else if(strcmp(command, "QUIT") == 0)
	 {
	   exit(0);
	   break;
	 }
	 
    }
  return 0;
}

void addMedia(vector<media*> & mediaList)
{
  char* title = new char[80];
  char* publisher = new char[80];
  char* artist = new char[80];
  char* director = new char[80];
  int year;
  int rating;
  int duration;

  cout << "Enter title: " << endl;
  cin.get(title, 80);
  cout << "Enter year: " << endl;
  cin >> year;
  
  char type[10];
  cout << "Enter media type (videoGame, music, movie): " << endl;
  cin.get(type, 10);

  if(strcmp(type, "videoGame") == 0)
    {
      cout << "Enter publisher: " << endl;
      cin.get(publisher, 80);
      cout << "Enter rating: " << endl;
      cin >> rating;
      media* movie = new movie(title, year, publisher, rating);
      mediaList.push_back(movie);
    }
  else if(strcmp(type, "music") == 0)
    {
      cout << "Enter artist: " << endl;
      cin.get(artist, 80);
      cout << "enter duration: " << endl;
      cin >> duration;
      cout << "Enter publisher: " << endl;
      cin.get(publisher, 80);
      media* music = new music(title, year, artist, duration, publisher);
      mediaList.push_back(music);
    }
  else if(strcmp(type, "movie") == 0)
    {
      cout << "Enter director: " << endl;
      cin.get(director, 80);
      cout << "Enter duration: " << endl;
      cin >> duration;
      cout << "Enter rating: " << endl;
      cin >> rating;
      media* movie = new movie(title, year, director, duration, rating);
      mediaList.push_back(movie);
    }
}

void searchMedia(vector<media*> & mediaList)
{
  char* title = new char[80];
  cin.get(title, 80);
  int year;
  cin >> year;
  
  for(vector<media*>::iterator it = media.begin(); it != media.end(); it++)
    {
      if((strcmp(title, (*it)->getTitle()) == 0) && (year = (*it)->getYear()))
	{

	}
      cout << (*it)-> << ", " << (*it)-> << ", " << (*it)-> << endl;
    }
}
  
