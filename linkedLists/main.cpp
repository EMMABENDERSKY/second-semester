#include "Node.h"
#include <iostream>
#include <cstring>

using namespace std;

void add(Node* head, Student* newStudent);
void remove(Node* head, Student* student);
void print(Node* next);

int main()
{
  Node* head = NULL;

  char* name = new char[80];
  int ID;
  double GPA;

  cout << "Enter Name: " << endl;
  cin.get(name, 80);
  cin.get();
  cout << "Enter ID: " << endl;
  cin >> ID;
  cin.ignore();
  cout << "Enter GPA: " << endl;
  cin >> GPA;
  cin.ignore();
  
  Student* student1 = new Student(name, ID, GPA);

  add(head, student1);

  cout << "Enter Name: " << endl;
  cin.get(name, 80);
  cin.get();
  cout << "Enter ID: " << endl;
  cin >> ID;
  cin.ignore();
  cout << "Enter GPA: " << endl;
  cin >> GPA;
  cin.ignore();

  Student* student2 = new Student(name, ID, GPA);

  add(head, student2);
  
  print(head);

  return 0;
}

void add(Node* head, Student* newStudent)
{
  Node* current = head;
  if(current == NULL)
    {
      head = new Node(newStudent);
    }
  else
    {
      while(current->getNext() != NULL)
	current = current->getNext();
      current->setNext(new Node(newStudent));
    }
}

void print(Node* next)
{
  cout << "List: ";
  if(next != NULL)
    {
      (next->getStudent())->getName();
      (next->getStudent())->getID();
      (next->getStudent())->getGPA();
      print(next->getNext());
    }
  else
    {
      //nothing
    }
}
