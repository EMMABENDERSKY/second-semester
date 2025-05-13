#include "RedBlackTree.h"
#include <iostream>
#include <fstream>

using namespace std;

//Constructor for a node
Node::Node(int value)
{
  data = value;
  color = RED; //New nodes start as red
  left = right = parent = NULL; //Children and parent are null for now
}

//Constructor for the RedBlackTree
RedBlackTree::RedBlackTree()
{
  NIL = new Node(0); //Create the shared NIL node
  NIL->color = BLACK; //NIL is always black
  NIL->left = NIL->right = NIL->parent = NULL;
  NIL->data = 0;
  root = NIL; //Start with empty tree
}

//Rotates x to the left, making its right child the new parent
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

//Rotates y to the right, making its left child the new parent
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

//Fix the tree after inserting a red node
void RedBlackTree::fixInsert(Node* z)
{
  while (z->parent && z->parent->color == RED)
    {
      if (z->parent == z->parent->parent->left)
	{
	  Node* y = z->parent->parent->right; //Uncle
	  if (y->color == RED)
	    {
	      //Case 1: Recoloring
	      z->parent->color = BLACK;
	      y->color = BLACK;
	      z->parent->parent->color = RED;
	      z = z->parent->parent;
            }
	  else
	    {
	      if (z == z->parent->right)
		{
		  //Case 2: left rotation needed
		  z = z->parent;
		  rotateLeft(z);
		}
	      //Case 3: right rotation needed
	      z->parent->color = BLACK;
	      z->parent->parent->color = RED;
	      rotateRight(z->parent->parent);
            }
        }
      else
	{
	  Node* y = z->parent->parent->left; //Uncle (mirror case)
	  if (y->color == RED)
	    {
	      //Case 1: recoloring
	      z->parent->color = BLACK;
	      y->color = BLACK;
	      z->parent->parent->color = RED;
	      z = z->parent->parent;
            }
	  else
	    {
	      if (z == z->parent->left)
		{
		  //Case 2: right rotation needed
		  z = z->parent;
		  rotateRight(z);
                }
	      //Case 3: left rotation needed
	      z->parent->color = BLACK;
	      z->parent->parent->color = RED;
	      rotateLeft(z->parent->parent);
            }
        }
    }
  root->color = BLACK; //Root is always black
}

//Insert, then call fexInsert to balance
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

//Public insert function
void RedBlackTree::insert(int value)
{
  if(value < 1 || value > 999)
    return; //Ignore invalid input

  Node* node = new Node(value);
  insertNode(node);
}

//Read numbers from a file and insert them into the tree
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

//Recursive print helper for the tree
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

//Print the full tree visually
void RedBlackTree::print()
{
  if(root == NIL)
    cout << "Tree is empty." << endl;

  else
    printHelper(root, 0);
}


Node* RedBlackTree::searchNode(Node* node, int val)
{
  if (node == NIL || val == node->data)
    return node;

  if (val < node->data)
    return searchNode(node->left, val);
  else
    return searchNode(node->right, val);
}

bool RedBlackTree::search(int value)
{
  Node* result = searchNode(root, value);
  return result != NIL;
}

void RedBlackTree::transplant(Node* u, Node* v)
{
  if (u->parent == nullptr)
    root = v;
  else if (u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;
  
  v->parent = u->parent;
}

Node* RedBlackTree::minimum(Node* node)
{
  while (node->left != NIL)
    node = node->left;
  return node;
}

void RedBlackTree::fixDelete(Node* x)
{
  while (x != root && x->color == BLACK)
    {
      if (x == x->parent->left)
	{
	  Node* w = x->parent->right;
	  if (w->color == RED)
	    {
	      w->color = BLACK;
	      x->parent->color = RED;
	      rotateLeft(x->parent);
	      w = x->parent->right;
	    }
	  
	  if (w->left->color == BLACK && w->right->color == BLACK)
	    {
	      w->color = RED;
	      x = x->parent;
	    }
	  else
	    {
	      if (w->right->color == BLACK)
		{
		  w->left->color = BLACK;
		  w->color = RED;
		  rotateRight(w);
		  w = x->parent->right;
		}
	      w->color = x->parent->color;
	      x->parent->color = BLACK;
	      w->right->color = BLACK;
	      rotateLeft(x->parent);
	      x = root;
	    }
	}
      else
	{
	  Node* w = x->parent->left;
	  if (w->color == RED) {
	    w->color = BLACK;
	    x->parent->color = RED;
	    rotateRight(x->parent);
	    w = x->parent->left;
	  }
	  
	  if (w->right->color == BLACK && w->left->color == BLACK)
	    {
	      w->color = RED;
	      x = x->parent;
	    }
	  else
	    {
	      if (w->left->color == BLACK)
		{
		  w->right->color = BLACK;
		  w->color = RED;
		  rotateLeft(w);
		  w = x->parent->left;
		}
	      w->color = x->parent->color;
	      x->parent->color = BLACK;
	      w->left->color = BLACK;
	      rotateRight(x->parent);
	      x = root;
	    }
	}
    }
  x->color = BLACK;
}

void RedBlackTree::deleteNode(Node* z)
{
  Node* y = z;
  Node* x;
  Color yOriginalColor = y->color;
  
  if (z->left == NIL)
    {
      x = z->right;
      transplant(z, z->right);
    }
  else if (z->right == NIL)
    {
      x = z->left;
      transplant(z, z->left);
    }
  else
    {
      y = minimum(z->right);
      yOriginalColor = y->color;
      x = y->right;
      if (y->parent == z)
	x->parent = y;
      else
	{
	  transplant(y, y->right);
	  y->right = z->right;
	  y->right->parent = y;
	}
      
      transplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
  
  if (yOriginalColor == BLACK)
    fixDelete(x);
  
  delete z;
}

void RedBlackTree::remove(int value)
{
  Node* z = searchNode(root, value);
  if (z == NIL)
    return;
  deleteNode(z);
}

