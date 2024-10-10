#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Student
{
  char firstName[80];
  char lastName[80];
  int ID;
  float GPA;
};

void addStudent(vector<Student*> & students);
void printStudents(vector<Student*> & students);
void deleteStudent(vector<Student*> & students);

int main()
{
  vector<Student*> students;

  while(true)
    {
      char command;
      cout << "Enter a command (A for ADD, P for PRINT, D for DELETE, Q for QUIT): " << endl;
      cin >> command;

      switch (command)
	{
	case 'A':
	  addStudent(students);
	  break;
	case 'P':
	  printStudents(students);
	  break;
	case 'D':
	  deleteStudent(students);
	  break;
	case 'Q':
	  exit(0);
	  break;
	}
    }
  
  return 0;
}

//Function to add a sudent
void addStudent(vector<Student*> & students)
{
  Student* newStudent = new Student;

  cout << "Enter first name: " << endl;
  cin >> newStudent->firstName;
  cout << "Enter last name: " << endl;
  cin >> newStudent->lastName;
  cout << "Enter ID: " << endl;
  cin >> newStudent->ID;
  cout << "Enter GPA: " << endl;
  cin >> newStudent->GPA;

  students.push_back(newStudent);
}

//Function to print the student list
void printStudents(vector<Student*> & students)
{
  for(vector<Student*>::iterator it = students.begin(); it != students.end(); it++)
    {
      cout << (*it)->firstName << " " << (*it)->lastName << ", " << (*it)->ID << ", " << (*it)->GPA << endl;
    }
}

//Function to delete a student 
void deleteStudent(vector<Student*> & students)
{
  int ID;
  cout << "Enter student ID to delete: " << endl;
  cin >> ID;

  for(vector<Student*>::iterator it = students.begin(); it != students.end(); it++)
    {
      if((*it)->ID == ID)
	{
	  students.erase(it);
	  break;
	}
    }
}
