#include <iostream>
#include <cstring>
#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item
{
 protected:
  char name[80];
 public:
  Item(const char*);
  const char* getName();
  };
#endif
