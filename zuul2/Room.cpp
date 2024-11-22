#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

Room::Room(const char* desc, bool VictoryRoom)
{
  strcpy(description, desc);
  isVictoryRoom = VictoryRoom;
}

char* Room::getDescription()
{
  return description;
}

void Room::setExit(const char* direction, Room* neighbor)
{
  exits[direction] = neighbor;
}

Room* Room::getExit(const char* direction)
{
  return exits; ////change////
}

vector<Item*> Room::getItems()
{
  return items;
}

void Room::addItem(Item* item)
{
  items.push_back(item);
}

void Room::removeItem(Item* item)
{
  for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++)
    {
      if(strcmp((*it)->getName(), item->getName()) == 0)
	{
      items.erase(it);
      break;
	}
    }
}

void Room::setVictoryRoom(bool victoryRoom)
{
  isVictoryRoom = victoryRoom;
}

bool Room::isVictory()
{
  return isVictoryRoom;
}
