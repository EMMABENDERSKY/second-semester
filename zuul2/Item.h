#include <iostream>
#include <cstring>
#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item
{
 private:
  const char* name;

public:
  Item(const char*);
  const char* getName() const;
  };
#endif
