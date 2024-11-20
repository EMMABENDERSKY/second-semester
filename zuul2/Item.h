#include <iostream>
#include <cstring>
#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item
{
 protected:
  char* name;
 public:
  Item(char*);
  char* getName();
  };
#endif
