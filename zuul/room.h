#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"
#ifndef ROOM_H
#define ROOM_H

using namespace std;

class room : public item 
{
 private:
  char* description;
  map<char*, room*> exists;
  vector<item*> items;
  bool isVictoryRoom;
 public:
  room(char*);
  char* getDescription();
  void setExit(char*, room*);
  room* getExit(char*);
  vector<item*> getItems();
  void addItem(item*);
  void removeItem(item*);
  void setVictoryRoom(bool);
  bool isVictory();
};
#endif
