#include <iostream>
#include "Node.h"
#include <cstring>

using namespace std;

Node::Node()
{
  value = '\0';
  left = NULL;
  right = NULL;
  next = NULL;
}

Node::Node(char v, Node* l, Node* r)
{
  value = v;
  left = l;
  right = r;
  next = NULL;
}

Node::~Node()
{
  delete left;
  delete right;
}

char Node::getValue()
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

void Node::setValue(char v)
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
