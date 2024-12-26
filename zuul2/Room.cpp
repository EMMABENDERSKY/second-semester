#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

Room::Room(const char* newDescription, const char* newName) : Item(newName)
{
  description = newDescription;
  name = newName;
}

Room::~Room()
{
  delete[] description;
  delete[] name;
}

void Room::addExit(const char* direction, Room* room)
{
  exits[direction] = room;
}

const char* Room::getDescription()
{
  return description;
}

const char* Room::getName()
{
  return name;
}

const map<const char*, Room*>& Room::getExits() const
{
    return exits;
}

void Room::addItem(Item* item)
{
  items.push_back(item);
}

void Room::removeItem(Item* item)
{
  for (vector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
    {
      if (*it == item)
	{
	  items.erase(it);
	  break; 
	}
    }
}

const vector<Item*>& Room::getItems() const
{
    return items;
}


