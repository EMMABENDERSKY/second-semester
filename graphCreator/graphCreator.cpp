#include <iostream>
#include <cstring>
#include <climits>

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
int findShortestPath(char* from, char* to);
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
	  char lable[2];

	  cout << "Enter lable: " << endl;
	  cin.get(lable, 2);
	  cin.get();
	  
	  addVertex(lable);
	}

      else if(strcmp(command, "AE") == 0)
	{
	  char from[2];
	  char to[2];
	  int weight;

	  cout << "Enter first vertex lable (from): " << endl;
	  cin.get(from, 2);
	  cin.get();

	  cout << "Enter second vertex lable (to): " << endl;
	  cin.get(to, 2);
	  cin.get();

	  cout << "Enter weight: " << endl;
	  cin >> weight;
	  cin.ignore();
	  
	  addEdge(from, to, weight);
	}
      
      else if(strcmp(command, "RV") == 0)
	{
	  char lable[2];

	  cout << "Enter lable: " << endl;
	  cin.get(lable, 2);
	  cin.get();

	  removeVertex(lable);
	}
      
      else if(strcmp(command, "RE") == 0)
	{
	  char from[2];
	  char to[2];

	  cout << "Enter first vertex lable (from): " << endl;
	  cin.get(from, 2);
	  cin.get();

	  cout << "Enter second vertex lable (to): " << endl;
	  cin.get(to, 2);
	  cin.get();

	  removeEdge(from, to);
	}
      
      else if(strcmp(command, "FSP") == 0)
	{
	  char from[2];
	  char to[2];

	  cout << "Enter start vertex lable: " << endl;
	  cin.get(from, 2);
	  cin.ignore();
	  cout << "Enter end vertex lable: " << endl;
	  cin.get(to, 2);
	  cin.ignore();

	  findShortestPath(from, to);
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
      if(strcmp(vertices[i], lable) == 0)
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
  vertices[vertexCount] = new char[strlen(lable) + 1];
  strcpy(vertices[vertexCount], lable);
  vertexCount++;
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

  for(int i = index; i < vertexCount - 1; i++)
    vertices[i] = vertices[i + 1];

  for(int i = index; i < vertexCount - 1; i++)
    for(int j = index; j < vertexCount; j++)
      adj[i][j] = adj[i + 1][j];

  for(int i = index; i < vertexCount; i++)
    for(int j = index; j < vertexCount - 1; j++)
      adj[i][j] = adj[i][j + 1];

  vertexCount--;
  
}

void removeEdge(char* from, char* to)
{
  int i = getIndex(from);
  int j = getIndex(to);

  if(i != -1 && j != -1)
    adj[i][j] = 0;
}

int findShortestPath(char* from, char* to)
{
  int start = getIndex(from);
  int end = getIndex(to);
  if(start == -1 || end == -1)
    {
      cout << "Start or end vertex not found." << endl;
      return -1;
    }

  int dist[MAX];
  bool visited[MAX];
  int previous[MAX];

  for( int i = 0; i < vertexCount; i++)
    {
      dist[i] = INT_MAX;
      visited[i] = false;
      previous[i] = -1;
    }

  dist[start] = 0;

  for(int count = 0; count < vertexCount - 1; count ++)
    {
      int u = -1;
      int minDist = INT_MAX;

      //Find unvisited vertex with smalles dist
      for(int i = 0; i < vertexCount; i++)
	{
	  if(!visited[i] && dist[i] < minDist)
	    {
	      minDist = dist[i];
	      u = i;
	    }
	}

      if(u == -1) //No more reachable vertices
	break;
      visited[u] = true;

      //update beighbors
      for(int v = 0; v < vertexCount; v++)
	{
	  if(adj[u][v] != 0 && !visited[v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v])
	    {
	      dist[v] = dist[u] + adj[u][v];
	      previous[v] = u;
	    }
	}
    }

  if(dist[end] == INT_MAX)
    {
      cout <<"No path exists from " << from << " to " << to << endl;
      return -1;
    }

  //Reconstruct path by going backwards from wnd to start
  int path[MAX];
  int count = 0;
  for(int at = end; at != -1; at = previous[at])
    path[count++] = at;

  cout << "Shortest path distance: " << dist[end] << endl;
  cout << "Path: ";
  for(int i = count - 1; i >= 0; i--)
    {
      cout <<vertices[path[i]];
      if(i != 0)
	cout << " -> ";
    }
  cout << endl;

  return 0;
}

void printAdjacencyTable()
{
  cout << "  ";

  for(int i = 0; i < vertexCount; i++)
    cout << vertices[i] << " ";
  cout << endl;

  for(int i = 0; i < vertexCount; i++)
    {
      cout << vertices[i] << " ";
      for(int j = 0; j < vertexCount; j++)
	cout << adj[i][j] << " ";
      cout << endl;
    }
}
