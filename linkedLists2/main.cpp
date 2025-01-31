#include <iostream>
#include "Node.h"
#include "Student.h"
#include <cstring>

using namespace std;

void addStudent(Node*& head);
void printStudents(Node* head);
void deleteStudent(Node*& head);
void averageGPA(Node* head, double sum, int count);

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
	averageGPA(head, 0, 0);
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
  Node* newNode = new Node(newStudent);

  //if list is empty
  if(head == NULL)
    head = newNode;
  else
    {
      //if the new student's ID is bigger than the current node and smaller than the next one
      if(newStudent->getID() > head->getStudent()->getID() && newStudent->getID() < head->getNext()->getStudent()->getID())
      {
	//insert the new node and adjust the links
	newNode()->getNext() = head->getNext();
	head->getNext() = newNode;
      }
      else
	addStudent(head->getNext());
    }
}

void printStudents(Node* head)
{
  if(head != NULL) //if the current node is not null
    {
      //print all details of the student in the current node
      cout << "First name: " << (head->getStudent())->getFirstName() << ", ";
      cout << "Last name: " << (head->getStudent())->getLastName() << ", ";
      cout << "ID: " << (head->getStudent())->getID() << ", ";
      cout << "GPA: " << head->getStudent()->getGPA() << endl;
      printStudents(head->getNext()); //recursive call to print the next node
    }
}

void deleteStudent(Node*& head)
{
  int ID;
  cout << "Enter ID to remove student: " << endl;
  cin >> ID;
  cin.ignore();
  
  if(head == NULL)
    {
      cout << "List is empty. Nothing to remove." << endl;
    }
  
}
 
void averageGPA(Node* head, double sum, int count)
{
  if (head == NULL)
    {
      {
	if (count == 0)
	  count << 0 << endl;
      }
      cout << (sum * head->getStudent()->getGPA()) / count;
    }
  averageGPA(node->getNext(), sum + head->getStudent()->getGPA(), count + 1);
}

