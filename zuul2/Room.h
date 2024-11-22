#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"
#ifndef ROOM_H
#define ROOM_H

using namespace std;

class Room : public Item
{
 private:
  char description[80];
  map<char*, Room*> exits;
  vector<Item*> items;
  bool isVictoryRoom;
 public:
  Room(const char*, bool);
  char* getDescription();
  void setExit(const char*, Room*);
  Room* getExit(const char*);
  vector<Item*> getItems();
  void addItem(Item*);
  void removeItem(Item*);
  void setVictoryRoom(bool);
  bool isVictory();
};
#endif
