#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(char* newFirstName, char* newLastName, int newID, double newGPA)
{
  firstName = new char[80];
  strcpy(firstName, newFirstName);
  lastName = new char[80];
  strcpy(lastName, newLastName);
  ID = newID;
  GPA = newGPA;
}

char* Student::getFirstName()
{
  return firstName;
}

char* Student::getLastName()
{
  return lastName;
}

int Student::getID()
{
  return ID;
}

double Student::getGPA()
{
  return GPA;
}
