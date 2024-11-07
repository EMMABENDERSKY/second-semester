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
 public:
  room();
  room(char*, char*);
  
};
#endif
