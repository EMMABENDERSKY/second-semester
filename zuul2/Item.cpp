#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

Item::Item(const char* newName)
{
  name = newName;
}

const char* Item::getName() const
{
  return name;
}
