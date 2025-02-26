#include <iostream>
#include "Node.h"
#include <cstring>

using namespace std;

Node::Node()
{
  value = new char[1];
  left = NULL;
  right = NULL;
}

Node::Node(char* v, Node* l, Node* r)
{
  value = new char[1];
  strcpy(value, v);
  left = l;
  right = r;
}

Node::~Node()
{
  delete [] value;
  delete left;
  delete right;
}

char* Node::getValue()
{
  return value;
}

Node* Node::getLeft()
{
  return left;
}

Node* Node::getRight()
{
  return right;
}

Node* Node::getNext()
{
  return next;
}

void Node::setValue(char* v)
{
  value = v;
}

void Node::setLeft(Node* l)
{
  left = l;
}

void Node::setRight(Node* r)
{
  right = r;
}

void Node::setNext(Node* n)
{
  next = n;
}
