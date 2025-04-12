#include "RedBlackTree.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
  RedBlackTree tree;

  while(true)
    {
      char command[80];
      cout <<"Enter command (ADD/READ/PRINT/QUIT): " << endl;
      cin.get(command, 80);
      cin.get();

      if(strcmp(command, "ADD") == 0)
	{
	  int num;
	  cout << "Enter a number between 1 and 999:" << endl;
	  cin >> num;
	  cin.ignore();
	  tree.insert(num);
	}

      else if(strcmp(command, "READ") == 0)
	{
	  char filename[80];
	  cout << "Enter filename:" << endl;
	  cin.get(filename, 80);
	  cin.get();
	  tree.readFromFile(filename);
	}
      
      else if(strcmp(command, "PRINT") == 0)
	{
	  tree.print();
	}
      
      else if(strcmp(command, "QUIT") == 0)
	{
	  exit(0);
	  break;
	}
    }
  
  return 0;
}
