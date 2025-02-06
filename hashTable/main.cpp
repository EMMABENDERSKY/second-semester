#include <iostream>
#include "HashTable.h"
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

//Load names from file
void loadNames();

//Random student generator
void generateStudents(HashTable & table, char firstNames[20], char lastNames[20]);

int main()
{
  srand(time(0));
  HashTable table;
  
  while(true)
    {
      char command[10];
      cout << "Enter a command (ADD/PRINT/DELETE/AVERAGE/QUIT): " << endl;
      cin.get(command, 10);
      cin.get();

      if(strcmp(command, "ADD") == 0)
        {
	  char firstName, lastName;
	  float GPA;

	  cout << "Enter first and last name: " << endl;
	  cin >> firstName << lastName;
	  cin.ignore();
	  cout << "Enter GPA: " << endl;
	  cin >> GPA;
	  cin.ignore();

	  table.addStudent(firstName, lastName, GPA);
        }

      if(strcmp(command, "PRINT") == 0)
        {
	  table.printStudents();
        }

      if(strcmp(command, "DELETE") == 0)
        {
	  int ID;
	  cout << "Enter ID to delete: " << endl;
	  cin >> ID;
	  cin.ignore();

	  table.deleteStudent(ID);
        }

      if(strcmp(command, "QUIT") == 0)
        {
	  exit(0);
	  break;
        }
    }
  return 0;
}


void loadNames()
{
  
}

void generateStudents(HashTable & table, char firstNames[20], char lastNames[20])
{
  for(int i = 0; int i < 40; i++)
    {
      
}


