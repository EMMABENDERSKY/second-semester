#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 20;
int adj[MAX][MAX]; //Adjacency table
char vertices[MAX]; //Lables (like 'A', 'B', etc.)
int vertexCount = 0;

void addVertex(char lable);
void addEdge(char from, char to);
void removeVertex(char lable);
void removeEdge(char from, char to);
int findShortestPath();
void printAdjacencyTable();

int main()
{
  while(true)
    {
      char command[5];
      cout << "Enter command: \n" << "AV - add vertex \n" << "AE - add edge \n" << "RV - remove vertex \n" << "RE - remove edge \n" << "FSP - find shortest path \n" << "PAT - print adjacency table\n" << "Q - quit" << endl;
      cin.get(command, 5);
      cin.get();

      if(strcmp(command, "AV") == 0)
	{

	}

      else if(strcmp(command, "AE") == 0)
	{

	}
      
      else if(strcmp(command, "RV") == 0)
	{

	}
      
      else if(strcmp(command, "RE") == 0)
	{

	}
      
      else if(strcmp(command, "FSP") == 0)
	{
	  
	}
      
      else if(strcmp(command, "PAT") == 0)
	{

	}

      else if(strcmp(command, "Q") == 0)
	{
	  exit(0);
	  break;
	}
    }
  return 0;
}

void addVertex(char lable)
{

}

void addEdge(char from, char to)
{

}

void removeVertex(char lable)
{

}

void removeEdge(char from, char to)
{

}

int findShortestPath()
{

}

void printAdjacencyTable()
{

}
