#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 20;
int adj[MAX][MAX]; //Adjacency table
char* vertices[MAX]; //Lables (like 'A', 'B', etc.)
int vertexCount = 0;

int getIndex(char* lable);
void addVertex(char* lable);
void addEdge(char* from, char* to, int weight);
void removeVertex(char* lable);
void removeEdge(char* from, char* to);
//int findShortestPath();
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
	  char lable[1];

	  cout << "Enter lable: " << endl;
	  cin.get(lable, 1);
	  cin.get();
	  
	  addVertex(lable);
	}

      else if(strcmp(command, "AE") == 0)
	{
	  char from[1];
	  char to[1];
	  int weight;

	  cout << "Enter first vertex lable (from): " << endl;
	  cin.get(from, 1);
	  cin.get();

	  cout << "Enter second vertex lable (to): " << endl;
	  cin.get(to, 1);
	  cin.get();

	  cout << "Enter weight: " << endl;
	  cin >> weight;
	  cin.ignore();
	  
	  addEdge(from, to, weight);
	}
      
      else if(strcmp(command, "RV") == 0)
	{
	  char lable[1];

	  cout << "Enter lable: " << endl;
	  cin.get(lable, 1);
	  cin.get();

	  removeVertex(lable);
	}
      
      else if(strcmp(command, "RE") == 0)
	{
	  char from[1];
	  char to[1];

	  cout << "Enter first vertex lable (from): " << endl;
	  cin.get(from, 1);
	  cin.get();

	  cout << "Enter second vertex lable (to): " << endl;
	  cin.get(to, 1);
	  cin.get();

	  removeEdge(from, to);
	}
      
      else if(strcmp(command, "FSP") == 0)
	{
	  
	}
      
      else if(strcmp(command, "PAT") == 0)
	{
	  printAdjacencyTable();
	}

      else if(strcmp(command, "Q") == 0)
	{
	  exit(0);
	  break;
	}
    }
  return 0;
}

int getIndex(char* lable)
{
  for(int i = 0; i < vertexCount; i++)
    {
      if(vertices[i] == lable)
	return i;
    }
  return -1;
}

void addVertex(char* lable)
{
  if(vertexCount >= MAX)
    {
      cout << "Max vertices reached" << endl;
      return;
    }
  vertices[vertexCount++] = lable;
}

void addEdge(char* from, char* to, int weight)
{
  int i = getIndex(from);
  int j = getIndex(to);
  if(i == -1 || j == -1)
    {
      cout << "Vertex not found" << endl;
      return;
    }
  adj[i][j] = weight;
}

void removeVertex(char* lable)
{
  int index = getIndex(lable);
  if(index == -1)
    return;

  
}

void removeEdge(char* from, char* to)
{

}

/*int findShortestPath()
{

}*/

void printAdjacencyTable()
{
  cout << "  ";

  for(int i = 0; i < vertexCount; i++)
    cout << endl << endl;

  for(int i = 0; i < vertexCount; i++)
    {
      cout << vertices[i] << " ";
      for(int j = 0; j < vertexCount; j++)
	cout << adj[i][j] << " ";
    }
  cout << endl;
}
