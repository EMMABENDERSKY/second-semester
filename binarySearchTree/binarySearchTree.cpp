#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Node
{
  Node* left;
  Node* right;
  int value;
};

//Function prototypes
void addNum(Node* root, int num); 
void addFile(Node* root);
Node* getSuccessor(Node* curr);
void remove(Node* root, int value);
bool search(Node* root, int value);
void print(Node* root, int index, int depth);

int main()
{
  Node* root;
  
  
  while(true)
    {
      char command[80];
      cout << "Enter command (ADD/REMOVE/SEARCH/PRINT/QUIT):" << endl;
      cin.get(command, 80);
      cin.get();
      
      if(strcmp(command, "ADD") == 0)
	{
	  char source[80];
	  cout << "CONSOLE or FILE?" << endl;
	  cin.get(source, 80);
	  cin.get();

	  if(strcmp(source, "CONSOLE") == 0)
	    {
	      int num;
	      cout << "Emter a number between 1 and 999:" << endl;
	      cin >> num;
	      cin.ignore();
	      addNum(root, num);
	    } 
	  
	  if(strcmp(source, "FILE") == 0)
	    addFile(root);
	}

      else if(strcmp(command, "REMOVE") == 0)
	{
	  int number;
	  cout << "Enter number to remove:" << endl;
	  cin >> number;
	  cin.ignore();

	  remove(root, number);
	}
      
      else if(strcmp(command, "SEARCH") == 0)
	{
	  int number;
	  cout << "Enter number to search:" << endl;
	  cin >> number;
	  cin.ignore();

	  if(search(root, number) == true)
	    cout << "Found" << endl;
	  cout << "Not found" << endl;
	}
      
      else if(strcmp(command, "PRINT") == 0)
	{
	  print(root, 1, 0);
	}
      else if(strcmp(command, "QUIT") == 0)
	{
	  exit(0);
	  break;
	}
    }  
  return 0;
}

void addNum(Node* root, int num)
{
  //If the tree is empty, add a new node
  if(root == NULL)
    {
      Node* newNode = new Node;
      newNode->value = num;
    }

  //If the value is already present in the tree, return
  if(root->value == num)
    return;

  //Otherwise, recur down the tree
  //If the value is greater than the current node's value, insert it in the right subtree
  if(root->value < num)
    root->right = addNum(root->right, num);

  //If the value is smaller than the current node's value, insert it in the left subtree
  else
    root->left = addNum(root->left, num);
}

void addFile(Node* root)
{
  cout << "Enter filename:" << endl;
  char filename[80];
  cin.get(filename, 80);
  cin.get();
  ifstream file(filename);
  if(file)
    {
      int num;
      while(file >> num)
	if(num >= 1 && num <= 999)
	  addNum(root);
      file.close();
    }
  else
    cout << "File doesn't exist" << endl;
}

//Return the smallest node that is larger than the given node
Node* getSuccessor(Node* curr)
{
  curr = curr->right;
  while(curr != NULL && curr->left != NULL)
    curr = curr->left;
  return curr;
}

void remove(Node* root, int value)
{
  //Base case
  if (root == NULL)
    return;

  //If the value is in a subtree
  if(root->value > value)
    root->left = remove(root->left, value);
  else if(root->value < value)
    root->right = remove(root->right, value);

  //If the root matches with the value
  else
    {
      //When root has only right child
      if(root->left == NULL)
	{
	  Node* temp = root->right;
	  delete root;
	  return temp;
	}

      //When root had only left child
      if(root->right == NULL)
	{
	  Node* temp = root->left;
	  delete root;
	  return temp;
	}

      //When both children are present
      Node* succ = getSuccessor(root);
      root->value = succ->value;
      root->right = remove(root->right, succ->value);
    }
}

bool search(Node* root, int value)
{
  //Base case: root is NULL or value is present in the root
  if(root == NULL || root->value = value)
    return true;

  //If value is greater than the root
  if(root->value < value)
    search(root->right, value);

  //If value is smaller than the root
  if(root->value > value)
    search(root->left, value);

  return false;
}

void print(Node* root, int index, int depth)
{
  if (root == NULL)
    return;

  
}
