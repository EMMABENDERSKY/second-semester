#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "movie.h"
#include "music.h"
#include "videogame.h"

using namespace std;

//function prototypes
void addMedia(vector<media*> & mediaList);
void searchMedia(vector<media*> & mediaList);
void deleteMedia(vector<media*> & mediaList);

int main()
{
  vector<media*> mediaList; //vector to store media items

  while(true)
    {
      char command[10];
      cout << "Enter a command (ADD, SEARCH, DELETE, QUIT): " << endl;
      cin.get(command, 10);
      cin.get();

      //handle different commands
      if(strcmp(command, "ADD") == 0)
	addMedia(mediaList);
      else if(strcmp(command, "SEARCH") == 0)
	{
	  searchMedia(mediaList);
	}
       else if(strcmp(command, "DELETE") == 0)
	 {
	   deleteMedia(mediaList);
	 }
       else if(strcmp(command, "QUIT") == 0)
	 {
	   exit(0);
	   break;
	 }
    }
  return 0;
}

//function to add media item
void addMedia(vector<media*> & mediaList)
{
  //variables for media attributes
  char* title = new char[80 ];
  char* publisher = new char[80];
  char* artist = new char[80];
  char* director = new char[80];
  int year;
  int rating;
  int duration;           

  cout << "Enter title: " << endl;
  cin.get(title,   80);
  cin.get();
  cout << "Enter year: " << endl;
  cin >> year;   
  cin.ignore();
  
  char type[10];
  cout << "Enter media type (videoGame/music/movie): " << endl;
  cin.get(type, 10);
  cin.get();

  //handle input based on media type
  if(strcmp(type, "videoGame") == 0)
    {
      cout << "Enter publisher: " << endl;
      cin.get(publisher, 80);
      cin.get();
      cout << "Enter rating: " << endl;
      cin >> rating;
      cin.ignore(); 
      mediaList.push_back(new videogame(title, year, publisher, rating));
    }
  else if(strcmp(type, "music") == 0)
    {
      cout << "Enter artist: " << endl;
      cin.get(artist, 80);
      cin.get();
      cout << "enter duration: " << endl;
      cin >> duration;
      cin.ignore();
      cout << "Enter publisher: " << endl;
      cin.get(publisher, 80);
      cin.get();
      mediaList.push_back(new music (title, year, artist, duration, publisher));
    }
  else if(strcmp(type, "movie") == 0)
    {
      cout << "Enter director: " << endl;
      cin.get(director, 80);
      cin.get();
      cout << "Enter duration: " << endl;
      cin >> duration;
      cin.ignore();
      cout << "Enter rating: " << endl;
      cin >> rating;
      cin.ignore();
      mediaList.push_back(new movie(title, year, director, duration, rating));
    }
}

//function to search for media item
void searchMedia(vector<media*> & mediaList)
{
  cout << "Enter title: " << endl;
  char* title = new char[80];
  cin.get(title, 80);
  cin.get();
  cout << "Enter year: " << endl;
  int year;
  cin >> year;
  cin.ignore();

  //iterate through the media list and print matching items
  for(vector<media*>::iterator it = mediaList.begin(); it != mediaList.end(); it++)
    {
      if((strcmp(title, (*it)->getTitle()) == 0) && (year = (*it)->getYear()))
	{
	  (*it)->printStuff();
	}
    }
}

//function to delete media item by title and year
void deleteMedia(vector<media*> & mediaList)
{
  cout << "Enter title: " << endl;
  char* title = new char[80];
  cin.get(title, 80);
  cin.get();
  cout << "Enter year: " << endl;
  int year;
  cin >> year;
  cin.ignore();

  //iterate through the media list and delete matching items
  for(vector<media*>::iterator it = mediaList.begin(); it != mediaList.end(); it++)
    {
      if((strcmp(title, (*it)->getTitle()) == 0) && (year = (*it)->getYear()))
	{
	  (*it)->~media();
	}
      mediaList.erase(it);
      break;
    }
}
