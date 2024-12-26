#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

Room::Room(const char* newDescription, const char* newName)
{
  description = new char[80];
  strcpy(description, newDescription);
  name = new char[80];
  strcpy(name, newName);
}

void addExit(const char* direction, Room* room)
{
  exits[direction] = room;
}

const char* getDescription()
{
  return description;
}

const char* getName()
{
  return name;
}

const map<const char*, Room*> & getExits()
{
  return exits;
}

void addItem(Item* item)
{
  items.push_back(item);
}

void removeItem(Item* item)
{
  for (vector<Item*>::iterator it = items.begin(); it != items.end(); ++it) {
    if (*it == item) {
      items.erase(it);
      break; 
    }
  }
}

const vector<Item*> & getItems()
{
  return items;
}

