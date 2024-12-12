#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student()
{
  name = new char[80];
  ID = 0;
  GPA = 0;
}

Student::Student(char* newName, int newID, double newGPA)
{
  name = new char[80];
  strcpy(name, newName);
  ID = newID;
  GPA = newGPA;
}

char* Student::getName()
{
  return name;
}

int Student::getID()
{
  return ID;
}

double Student::getGPA()
{
  return GPA;
}
  
