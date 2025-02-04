#include <iostream>
#include "Node.h"
#include "Student.h"
#include <cstring>
#include <iomanip>

using namespace std;

//function prototypes
void addStudent(Node* & head, Node* newNode);
void printStudents(Node* head);
void deleteStudent(Node* & head, int ID);
void averageGPA(Node* head, double sum, int count);

int main()
{
  Node* head = NULL; //initialize the head of the linked list
  
  while(true)
    {
      char command[10];
      cout << "Enter a command (ADD/PRINT/DELETE/AVERAGE/QUIT): " << endl;
      cin.get(command, 10);
      cin.get();

      if(strcmp(command, "ADD") == 0)
	{
	  //variables to hold student information
	  char* firstName = new char[80];
	  char* lastName = new char[80];
	  int ID;
	  double GPA;

	  //get the student's first name, last name, ID, and GPA
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

	  //create new Student and Node objects
	  Student* newStudent = new Student(firstName, lastName, ID, GPA);
	  Node* newNode = new Node(newStudent);
	  
	  addStudent(head, newNode); //add student to the linked list
	}
      else if(strcmp(command, "PRINT") == 0)
	printStudents(head); //print the list of students
      else if(strcmp(command, "DELETE") == 0)
	{
	  int ID;
	  cout << "Enter ID to remove student: " << endl;
	  cin >> ID;
	  cin.ignore();
	  
	  deleteStudent(head, ID); //delete the student by ID
	}
      else if(strcmp(command, "AVERAGE") == 0)
	averageGPA(head, 0, 0); //calculate the average GPA
      else if(strcmp(command, "QUIT") == 0)
	{
	  exit(0); //exit the program
	  break;
	}
    }
  return 0;
}

void addStudent(Node* & head, Node* newNode)
{
  //if the list is empty or we have found the position to insert the new node 
  if (head == NULL || newNode->getStudent()->getID() < head->getStudent()->getID()) 
    { 
      //insert the new node and adjust the links
      newNode->setNext(head); 
      head = newNode;
    } 
  else 
    {
      //move to the next node is the ID is greater than the current one
      Node* nextNode = head->getNext();
      addStudent(nextNode, newNode);  //move to the next node and keep calling the function recursively
      head->setNext(nextNode); //re-link the current node
    }
}


void printStudents(Node* head)
{
  //if the list is empty, do nothing
  if (head == NULL)
    {
      return;
    }
  
  //print all details of the student in the current node
  cout << "First name: " << (head->getStudent())->getFirstName() << ", ";
  cout << "Last name: " << (head->getStudent())->getLastName() << ", ";
  cout << "ID: " << (head->getStudent())->getID() << ", ";
  cout << fixed << setprecision(2) << "GPA: " << (head->getStudent())->getGPA() << endl;
  
  printStudents(head->getNext()); //recursive call to print the next node
}

void deleteStudent(Node* & head, int ID)
{
  //if the list is empty, the student cannot be found
    if (head == NULL)
    {
        cout << "Student with ID " << ID << " not found. (List is empty)" << endl;
        return;
    }

    //check if the current node matches the ID to be deleted
    if (head->getStudent()->getID() == ID)
    {
        cout << "Found student with ID " << ID << ". Removing..." << endl;

        //temporary node to delete the current node
        Node* temp = head;
        head = head->getNext(); //update the head to point to the next node 
        delete temp; //delete the current node

        cout << "Student with ID " << ID << " removed." << endl;
        return;
    }

    //move to the next node is the current node's ID doesn't match
    Node* nextNode = head->getNext();
    deleteStudent(nextNode, ID); //recursive call to delete from the next node
    head->setNext(nextNode); //re-link the current node
}
    
void averageGPA(Node* head, double sum, int count) 
{
  //if the list is empty
  if (head == NULL) 
    { 
      if (count == 0) //if no students were found, return a message
	{
	  cout << "No students in the list." << endl; 
	  return; 	
	}	
      cout << fixed << setprecision(2) << "Average GPA: " << (sum / count) << endl; //calculaye the average GPA 
      return; 
    }
  averageGPA(head->getNext(), sum + head->getStudent()->getGPA(), count + 1); //add GPA anf move to the next node
}



