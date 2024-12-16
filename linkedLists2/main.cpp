#include <iostream>
#include <cstring>

using namespace std;

void addStudent(Node*& head);
void printStudents(Node* next);
void deleteStudent(Node*& head);
void averageGPA(Node* next);

int main()
{
  Node* head = NULL;
  
  while(true)
    {
      char command[10];
      cout << "Enter a command (ADD/PRINT/DELETE/AVERAGE/QUIT): " << endl;
      cin.get(command, 10);
      cin.get();

      if(strcmp(command, "ADD") == 0)
	addStudent(head);
      else if(strcmp(command, "PRINT") == 0)
	printStudents(head);
      else if(strcmp(command, "DELETE") == 0)
	deleteStudent(head);
      else if(strcmp(command, "AVERAGE") == 0)
	averageGPA(head);
      else if(strcmp(command, "QUIT") == 0)
	{
	  exit(0);
	  break;
	}
    }
  return 0;
}

void addStudent(Node*& head)
{
  char* firstName = new char[80];
  char* lastName = new char[80];
  int ID;
  double GPA;
  
  cout << "Enter first name: " << endl;
  cin.get(firstName, 80);
  cin.get();
  cout << "Enter last name: " << endl;
  cin.get(lastName, 80);
  cin.get();
  cout << "Enter ID: " << endl;
  cin >> ID;
  cin.ignore();
  cout << "Enter GPA: " << endl;
  cin >> GPA;
  cin.ignore();

  Student* newStudent = new Student(firstName, lastName, ID, GPA);

  if(head == NULL)
    head = new Node(newStudent);
  else
    {
      Node* prev = head;
      Node* curr = head->getNext();
      while(curr != NULL)
	{
	  if(curr->getStudent()->getID() < prev->getStudent()->getID())
	    {
	      
}

void printStudents(Node* next)
{

}

void deleteStudent(Node*& head)
{

}

void averageGPA(Node* next)
{

}
