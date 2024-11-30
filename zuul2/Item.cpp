#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

Item::Item()
{
  strcpy(name, " ");
}

Item::Item(const char* newName)
{
  strcpy(name, newName);
}

const char* Item::getName()
{
  return name;
}
