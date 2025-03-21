#include <iostream>
#include <cstring>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(int size = 100)
{
  tableSize = size;
  table = new Student*[tableSize];
  IDcounter = 1;

  for(int i = 0; i < tableSize; i++)
    table[i] = NULL;
}

HashTable::~HashTable()
{
  for(int i = 0; i < tableSize; i++)
    {
      Student* current = table[i];
      while(current != NULL)
	{
	  Student* temp = current;
	  current = current->next;
	  delete temp;
	}
    }
  delete[] table;
}

int HashTable::hashFunction(int ID)
{
  return ID % tableSize;
}

void HashTable::rehash() //when chain > 3 
{
  int newTableSize = tableSize * 2;
  Student** newTable = new Student*[newTableSize];

  for(int i = 0; i < newTableSize; i++)
    newTable[i] = NULL;
  
  for(int i = 0; i < tableSize; i++)
    {
      Student* current = table[i];
      while(current != NULL)
	{
	  int newHash = current->ID % newTableSize;
	  
	  Student* newStudent = new Student;
	  newStudent->ID = current->ID;
	  newStudent->firstName = new char[strlen(current->firstName) + 1];
	  newStudent->lastName = new char[strlen(current->lastName) + 1];
	  strcpy(newStudent->firstName, current->firstName);
	  strcpy(newStudent->lastName, current->lastName);
	  newStudent->GPA = current->GPA;
	  newStudent->next = newTable[newHash];
	  newTable[newHash] = newStudent;

	  Student* temp = current;
	  current = current->next;
	  delete[] temp->firstName;
	  delete[] temp->lastName;
	  delete temp;
	}
    }
  delete[] table;
  table = newTable;
  tableSize = newTableSize;
}

//Add a student
void HashTable::addStudent(char* first, char* last, float GPA)
{
  int ID = IDcounter++;
  int hash = hashFunction(ID);

  Student* newStudent = new Student;
  newStudent->ID = ID;
  newStudent->firstName = new char[strlen(first) + 1];
  newStudent->lastName = new char[strlen(last) + 1];
  strcpy(newStudent->firstName, first);
  strcpy(newStudent->lastName, last);
  newStudent->GPA = GPA;
  newStudent->next = table[hash];

  table[hash] = newStudent;

  int chainLength = 0;
  Student* temp = table[hash];
  while(temp != NULL)
    {
      chainLength++;
      temp = temp->next;
    }
  
  if(chainLength > 3)
    rehash();
}

//Print students
void HashTable::printStudents()
{
  for(int i = 0; i < tableSize; i++)
    {
      Student* current = table[i];
      while(current != NULL)
        {
          cout << "ID: " << current->ID << endl;
          cout << "First name: " << current->firstName << endl;
          cout << "Last name: " << current->lastName << endl;
          cout << "GPA: " << current->GPA << endl;
          cout << endl << endl;

          current = current->next;
        }
    }
}

//Delete a student by ID
void HashTable::deleteStudent(int ID)
{
  int hash = hashFunction(ID);
  Student* current = table[hash];
  Student* prev = NULL;

  while(current != NULL)
    {
      if(current->ID == ID)
	{
	  if(prev == NULL)
	    table[hash] = current->next;
	  else
	    prev->next = current->next;
	  delete[] current->firstName;
	  delete[] current->lastName;
	  delete current;
	  cout << "Student " << ID << " deleted." << endl;
	  return;
	}
      prev = current;
      current = current->next;
    }
  cout << "Student " << ID << " not found." << endl;
}
