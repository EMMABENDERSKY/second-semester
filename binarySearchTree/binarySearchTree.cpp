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
Node* addNum(Node* root, int num); 
void addFile(Node* & root);
Node* getSuccessor(Node* curr);
Node* remove(Node* root, int num);
bool search(Node* root, int num);
void print(Node* root, int space);

int main()
{
  Node* root = NULL;
  
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
	      cout << "Enter a number between 1 and 999:" << endl;
	      cin >> num;
	      cin.ignore();
	      
	      root = addNum(root, num);
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

	  root = remove(root, number);
	}
      
      else if(strcmp(command, "SEARCH") == 0)
	{
	  int number;
	  cout << "Enter number to search:" << endl;
	  cin >> number;
	  cin.ignore();

	  if(search(root, number))
	    cout << "Found" << endl;
	  else
	    cout << "Not found" << endl;
	}
      
      else if(strcmp(command, "PRINT") == 0)
	{
	  print(root, 0);
	}
      else if(strcmp(command, "QUIT") == 0)
	{
	  exit(0);
	  break;
	}
    }  
  return 0;
}

Node* addNum(Node* root, int num)
{ 
  //If the tree is empty, add a new node
  if(root == NULL)
    {
      Node* newNode = new Node;
      newNode->value = num;
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode;
    }

  //Otherwise, recur down the tree
  if(num < root->value)  
    root->left = addNum(root->left, num); //If num is less than the current node value, go left
  
  else if(num > root->value)  
    root->right = addNum(root->right, num); //If num is greater than the current node value, go right
  
  //Return the (unchanged) root
  return root;
}

void addFile(Node* & root)
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
	{
	  if(num >= 1 && num <= 999)
	    root = addNum(root, num);
	}
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

Node* remove(Node* root, int num)
{
  //Base case
  if (root == NULL)
    return root;

  //If the value is in a subtree
  if(root->value > num)
    root->left = remove(root->left, num);
  else if(root->value < num)
    root->right = remove(root->right, num);

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
  return root;
}

bool search(Node* root, int num)
{
  if(root == NULL)
    return false; //Not found

  if(root->value == num)
    return true; //Found

  if(root->value < num)
    return search(root->right, num); //Continue searching right
  else
    return search(root->left, num); //Continue searching left
}

void print(Node* root, int space)
{
  //Base case
  if(root == NULL)
    return;

  //Increase distance between levels
  space += 5;

  //Process left child first
  print(root->right, space);

  //Print current node after space count
  for(int i = 5; i < space; i++)
    cout << " ";
  cout << root->value << "\n";

  //Process left child
  print(root->left, space);
}
