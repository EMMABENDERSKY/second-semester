#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

item::item()
{

}

item::item(char* newName)
{
  name = new char[80];
  strcpy(name, newName);
}
