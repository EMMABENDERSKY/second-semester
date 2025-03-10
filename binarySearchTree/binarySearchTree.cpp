#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
  Node* left;
  Node* right;
  int value;
};

//Function prototypes
void addConsole(Node* root); 
void addFile(Node* root);
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
	    addConsole(root);
	  
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

	  search(root, number);
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

void addConsole(Node* root)
{

}

void addFile(Node* root)
{

}

void remove(Node* root, int value)
{

}

bool search(Node* root, int value)
{

}

void print(Node* root, int index, int depth)
{
  if (root == NULL)
    return;

  
}
