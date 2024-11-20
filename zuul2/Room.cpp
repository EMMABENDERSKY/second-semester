#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

Room::Room(char* newDescription, bool newVictoryRoom)
{
  description = new char[80];
  strcpy(description, newDescription);
  isVictoryRoom = newVictoryRoom;
}

char* Room::getDescription()
{
  return description;
}

void Room::setExit(char* direction, room* neighbor)
{
  exits[direction] = neighbor;
}

Room* Room::getExit(char* direction)
{

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
  item.erase(remove(items.begin(), items.end(), item), items.end());
}

void Room::setVitoryRoom(bool victoryRoom);
{
  isVictoryRoom = victoryRoom();
}

bool Room::isVictory();
{
  return isVictoryRoom();
}
