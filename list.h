#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

struct Node
{
  Node* next;
  int value;
};

class list
{
 public:
  void build(Node* & head);
  void copy(Node* & head);

 private:
  Node* head;
};
#endif
