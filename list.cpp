#include <iostream>
#include "list.h"

using namespace std;

void list::build(Node* & head)
{
  head->setValue(1 + (rand() % 20);
  for (int i = 0; i < 9; i++)
    {
      head->getNext()->setValue(1 + (rand() % 20));
      head = head->getNext();
    }
}

void list::copy()
{
  
}
