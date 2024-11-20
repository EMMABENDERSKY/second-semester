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
  char* description;
  map<char*, Room*> exists;
  vector<Item*> items;
  bool isVictoryRoom;
 public:
  Room(char*);
  char* getDescription();
  void setExit(char*, Room*);
  Room* getExit(char*);
  vector<Item*> getItems();
  void addItem(Item*);
  void removeItem(Item*);
  void setVictoryRoom(bool);
  bool isVictory();
};
#endif
