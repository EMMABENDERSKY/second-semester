#include "Node.h"

using namespace std;

Node::Node(Student* newStudent)
{
  student = newStudent;
  next = NULL;
}

Node::~Node()
{
  delete &student;
  next = NULL;
}

Node* Node::getNext()
{
  return next;
}

void Node::setNext(Node* newNext)
{
  next = newNext;
}

Student* Node::getStudent()
{
  return student;
}
