#include "RedBlackTree.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
  RedBlackTree tree; //Create the red-black tree

  while(true)
    {
      char command[80];
      cout <<"Enter command (ADD/READ/PRINT/QUIT/SEARCH/REMOVE): " << endl;
      cin.get(command, 80);
      cin.get();

      if(strcmp(command, "ADD") == 0)
	{
	  int num;
	  cout << "Enter a number between 1 and 999:" << endl;
	  cin >> num;
	  cin.ignore();
	  tree.insert(num); //Add number to tree
	}

      else if(strcmp(command, "READ") == 0)
	{
	  char filename[80];
	  cout << "Enter filename:" << endl;
	  cin.get(filename, 80);
	  cin.get();
	  tree.readFromFile(filename); //Read numbers from file
	}
      
      else if(strcmp(command, "PRINT") == 0) //Print the tree
	{
	  tree.print();
	}
      
      else if(strcmp(command, "QUIT") == 0)
	{
	  exit(0); //Exit the program
	  break;
	}

      else if (strcmp(command, "SEARCH") == 0)
	{
	  int num;
	  cout << "Enter number to search:" << endl;
	  cin >> num;
	  cin.ignore();
	  if (tree.search(num))
	    cout << num << " found in the tree." << endl;
	  else
	    cout << num << " not found." << endl;
	}
      
      else if (strcmp(command, "REMOVE") == 0)
	{
	  int num;
	  cout << "Enter number to remove:" << endl;
	  cin >> num;
	  cin.ignore();
	  tree.remove(num);
	}
    }
  
  return 0;
}
