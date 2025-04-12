#include "RedBlackTree.h"
#include <iostream>
#include <fstream>

using namespace std;

Node::Node(int value)
{
  data = value;
  color = RED;
  left = right = parent = NULL;
}

RedBlackTree::RedBlackTree()
{
  NIL = new Node(0);
  NIL->color = BLACK;
  NIL->left = NIL->right = NIL->parent = NULL;
  NIL->data = 0;
  root = NIL;
}

void RedBlackTree::rotateLeft(Node* x)
{
  Node* y = x->right;
  x->right = y->left;

  if (y->left != NIL)
    y->left->parent = x;

  y->parent = x->parent;

  if (x->parent == nullptr)
    root = y;

  else if (x == x->parent->left)
    x->parent->left = y;

  else
    x->parent->right = y;

  y->left = x;
  x->parent = y;
}

void RedBlackTree::rotateRight(Node* y)
{
  Node* x = y->left;
  y->left = x->right;

  if (x->right != NIL)
    x->right->parent = y;

  x->parent = y->parent;

  if (y->parent == nullptr)
    root = x;

  else if (y == y->parent->right)
    y->parent->right = x;

  else
    y->parent->left = x;

  x->right = y;
  y->parent = x;
}

void RedBlackTree::fixInsert(Node* z)
{
  while (z->parent && z->parent->color == RED)
    {
      if (z->parent == z->parent->parent->left)
	{
	  Node* y = z->parent->parent->right;
	  if (y->color == RED)
	    {
	      z->parent->color = BLACK;
	      y->color = BLACK;
	      z->parent->parent->color = RED;
	      z = z->parent->parent;
            }
	  else
	    {
	      if (z == z->parent->right)
		{
		  z = z->parent;
		  rotateLeft(z);
		}
	      z->parent->color = BLACK;
	      z->parent->parent->color = RED;
	      rotateRight(z->parent->parent);
            }
        }
      else
	{
	  Node* y = z->parent->parent->left;
	  if (y->color == RED)
	    {
	      z->parent->color = BLACK;
	      y->color = BLACK;
	      z->parent->parent->color = RED;
	      z = z->parent->parent;
            }
	  else
	    {
	      if (z == z->parent->left)
		{
		  z = z->parent;
		  rotateRight(z);
                }
	      z->parent->color = BLACK;
	      z->parent->parent->color = RED;
	      rotateLeft(z->parent->parent);
            }
        }
    }
  root->color = BLACK;
}

void RedBlackTree::insertNode(Node* z)
{
  Node* y = NULL;
  Node* x = root;

  while (x != NIL)
    {
      y = x;
      if(z->data < x->data)
	x = x->left;
      else
	x = x->right;
    }
  z->parent = y;

  if(y == NULL)
    root = z;

  else if(z->data < y->data)
    y->left = z;

  else
    y->right = z;

  z->left = z->right = NIL;
  z->color = RED;
  fixInsert(z);
}

void RedBlackTree::insert(int value)
{
  if(value < 1 || value > 999)
    return;

  Node* node = new Node(value);
  insertNode(node);
}

void RedBlackTree::readFromFile(const char* filename)
{
  ifstream file(filename);
  if (!file)
    {
      cout << "File not found!" << endl;
      return;
    }

  int num;
  while (file >> num)
    {
      if(num >= 1 && num <= 999)
	insert(num);
    }
  file.close();
}

void RedBlackTree::printHelper(Node* node, int space)
{
  if (node == NIL)
    return;
  
  space += 5;
  
  if (node->right != NIL) 
    printHelper(node->right, space); 
  
  for (int i = 5; i < space; i++)
    cout << " ";  
  
  cout << node->data;  

  if (node->color == RED)
    cout << "(R)" << endl;  

  else
    cout << "(B)" << endl; 
  
  if (node->left != NIL)
    printHelper(node->left, space);  
}

void RedBlackTree::print()
{
  if(root == NIL)
    cout << "Tree is empty." << endl;

  else
    printHelper(root, 0);
}

