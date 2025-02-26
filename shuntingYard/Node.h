#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class Node
{
 public:
  Node();
  Node(char*, Node*, Node*);
  ~Node();
  char* getValue();
  Node* getLeft();
  Node* getRight();
  Node* getNext();
  void setValue(char*);
  void setLeft(Node*);
  void setRight(Node*);
  void setNext(Node*);
  
 private:
  char* value;
  Node* left;
  Node* right;
  Node* next;
};
#endif
