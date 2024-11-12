#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

room::room()
{
  description = new char[80];
  
}

room::room(char* newDescription)
{
  description = new char[80];
  strcpy(description, newDescription);
  
}

char* room::getDescription()
{
  return description;
}

room* getExits()
{
  
}

vector<item*> room::getItems()
{
  for(vector<item*>::iterator it = items.begin(); it != items.end(); it++)
    {
      
    }
}

void room::getItems()



void room::pickUpItem()
{

}

void room::dropItem(item* item)
{
  
}
