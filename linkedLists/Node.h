#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Node
{
 public:
  Node(Student*); //constructor that takes a student pointer and initializes the node
  ~Node(); //destructor that deletes the student object
  Node* getNext(); //function to return the next node pointer in the linked list
  Student* getStudent(); //function to return the student pointer stored un current node
  void setNext(Node*); //function to set the next pointer of the current node
  
 private:
  Student* student; //pointer to a atudent object (data of the node)
  Node* next; //pointer to the next node of the linked list
};

#endif
