#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

room::room()
{

}

room::room(char* newName, char* newDescription)
{
  name = new char[80];
  strcpy(name, newName);
  description = new char[80];
  strcpy(description, newDescription);
}
