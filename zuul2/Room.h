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
  const char* description;
  const char* name;
  map< const char*, Room*> exits;
  vector<Item*> items;
 public:
  Room(const char*, const char*);
  void addExit(const char*, Room*);
  const char* getDescription();
  const char* getName();
  const map<const char*, Room> & getExits();
  void addItem(Item*);
  void removeItem(Item*);
  const vector<Item*> & getItems();
};
#endif
