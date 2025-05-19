#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <iostream>

using namespace std;

//Define color enum for red-black tree nodes 
enum Color { RED, BLACK };

//Node structure for red black tree
struct Node
{
  int data; //Value stored in the node
  Color color; //Colot of the node (RED or BLACK)
  Node* left; //Pointer to left child
  Node* right; //pointer to right child
  Node* parent; //Pointer to parent

  Node(int value); //Constructor
};

//Red-Black Tree class
class RedBlackTree
{
private:
  Node* root; //Root of the tree
  Node* NIL; //A special node used instead of NULL for empty children and to mark the end of branches

  void rotateLeft(Node* x); //Left rotation arounf node x
  void rotateRight(Node* x); //Right rotation around node x
  void fixInsert(Node* z); //Fix the tree after insertion to maintain red-black properties
  void insertNode(Node* z); //Insert a new node into the tree 
  void printHelper(Node* node, int space); //Recursize helper to print the tree top-down with indentation

  void transplant(Node* u, Node* v); //Helper for replacing nodes
  Node* minimum(Node* node); //Gets minimum node from a subtree
  void fixDelete(Node* x); //Balances tree after deletion
  void deleteNode(Node* z); //Deletes the node z
  Node* searchNode(Node* node, int val); //Recursive search
  
  
public:
  RedBlackTree(); //Constructor
  void insert(int value); //Public insert function 
  void readFromFile(const char* filename); //Reads values from a file and inserts them into the tree
  void print(); //Print the tree visually

  bool search(int value); //Returns truew if value exists
  void remove(int value); //Removes a value from the tree
};

#endif
