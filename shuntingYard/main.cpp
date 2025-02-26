#include <iostream>
#include "Node.h"
#include <cstring>

using namespace std;

struct Stack
{
  Node* top = NULL;

  void push(char* value)
  {
    Node* newNode = new Node();
    newNode->setValue(value);
    newNode->setNext(top);
    top = newNode;
  }

  char* pop()
  {
    if(top == NULL)
      return NULL;
    char* value = top->getValue();
    Node* temp = top;
    top = top->getNext();
    delete temp;
    return value;
  }

  char* peek()
  {
    if (top == NULL)
      return NULL;
    return top->getValue();
  }

  bool isEmpty()
  {
    if(top == NULL)
      return true;
    return false;
};

struct Queue
{
  Node* front = NULL;
  Node* back = NULL;

  void enqueue(char* value)
  {
    Node* newNode = new Node();
    newNode->setValue(value);
    if(back == NULL)
      {
	front = back = newNode;
	return;
      }
    back->setNext(newNode);
    back = newNode;
  }

  char* dequeue()
  {

  }
};

void printPrefix();
void printInfix();
void printPostfix();

int main()
{

  return 0;
}
