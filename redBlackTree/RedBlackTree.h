#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <iostream>

using namespace std;

enum Color { RED, BLACK };

struct Node
{
  int data;
  Color color;
  Node* left;
  Node* right;
  Node* parent;

  Node(int value);
};

class RedBlackTree
{
private:
  Node* root;
  Node* NIL;

  void rotateLeft(Node* x);
  void rotateRight(Node* x);
  void fixInsert(Node* z);
  void insertNode(Node* z);
  
public:
  RedBlackTree();
  void insert(int value);
  void readFromFile(const char* filename);
  void print();
};

#endif
