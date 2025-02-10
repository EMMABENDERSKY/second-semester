#include <iostream>
#include "HashTable.h"
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

//Function to load names from file into arrays
void loadNames(char* firNames[20], char* lastNames[20]);

//Function to generate random students
void generateStudents(HashTable & table, char* firstNames[20], char* lastNames[20], int num);

int main()
{
  srand(time(0));
  HashTable table(100);

  char* firstNames[20];
  char* lastNames[20];
  loadNames(firstNames, lastNames);
  
  while(true)
    {
      char command[10];
      cout << "Enter a command (ADD/PRINT/DELETE/GENERATE/QUIT): " << endl;
      cin.get(command, 10);
      cin.get();

      if(strcmp(command, "ADD") == 0)
        {
	  char firstName[50], lastName[50];
	  float GPA;

	  cout << "Enter first and last name: " << endl;
	  cin >> firstName >> lastName;
	  cin.ignore();
	  cout << "Enter GPA: " << endl;
	  cin >> GPA;
	  cin.ignore();

	  table.addStudent(firstName, lastName, GPA);
        }

      else if(strcmp(command, "PRINT") == 0)
        {
	  table.printStudents();
        }

      else if(strcmp(command, "GENERATE") ==0)
	{
	  int num;
	  cout << "Enter number of students to generate: " << endl;
	  cin >> num;
	  cin.ignore();

	  generateStudents(table, firstNames, lastNames, num);
	}

      else if(strcmp(command, "DELETE") == 0)
        {
	  int ID;
	  cout << "Enter ID to delete: " << endl;
	  cin >> ID;
	  cin.ignore();

	  table.deleteStudent(ID);
        }

      else if(strcmp(command, "QUIT") == 0)
        {
	  exit(0);
	  break;
        }
    }

  for(int i = 0; i < 20; i++)
    {
      delete[] firstNames[i];
      delete[] lastNames[i];
    }
  
  return 0;
}


void loadNames(char* firstNames[20], char* lastNames[20])
{
  ifstream firstFile("firstNames.txt");
  ifstream lastFile("lastNames.txt");

  int i = 0;
  char temp[50];

  while(i < 20 && firstFile.getline(temp, 50))
    {
      firstNames[i] = new char[strlen(temp) + 1];
      strcpy(firstNames[i], temp);
      i++;
    }
  firstFile.close();

  i = 0;
  while (i < 20 && lastFile.getline(temp, 50))
    {
      lastNames[i] = new char[strlen(temp) + 1];
      strcpy(lastNames[i], temp);
      i++;
    }
  lastFile.close();
}

void generateStudents(HashTable & table, char* firstNames[20], char* lastNames[20], int num)
{
  for(int i = 0; i < num; i++)
    {
      int firstIndex = rand() % 20;
      int lastIndex = rand() % 20;
      float GPA = ((rand() % 301) / 100.0) + 1.0;

      table.addStudent(firstNames[firstIndex], lastNames[lastIndex], GPA);
    }
}


