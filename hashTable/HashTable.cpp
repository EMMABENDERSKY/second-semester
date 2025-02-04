#include <iostream>
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
	  int newHash = current->ID/newTableSize;
	  
	  Student* newStudent = new Student;
	  newStudent->ID = current->ID;
	  newStudent->firstName = current->firstName;
	  newStudent->lastName = current->lastName;
	  newStudent->GPA = current->GPA;
	  newStudent->next = newTable[newHash];
	  newTable[newHash] = newStudent;

	  Student* temp = current;
	  current = current->next;
	  delete temp;
	}
    }
  delete[] table;
  table = newTable;
  tableSize = newTableSize;
}

void HashTable::addStudent(char firstName, char lastName, float GPA)
{
  int ID = IDcounter++;
  int hash = hashFunction(ID);

  Student* newStudent = new Student;
  newStudent->ID = ID;
  newStudent->firstName = firstName;
  newStudent->lastName = lastName;
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

void HashTable::deleteStudent(int)
{

}
