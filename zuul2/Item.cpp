#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

Item::Item(char* newName)
{
  name = new char[80];
  strcpy(name, newName);
}

char* Item::getName()
{
  return name;
}
