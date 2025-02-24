#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

void addNum(int heap[101], int & size, int num); //Function to add a number to the heap
void addFile(int heap[101], int & size); //Function to add numbers from a file to the heap
void swap(int heap[101], int childIndex, int parentIndex); //Function to swap two elements in the heap
void display(int heap[101], int size, int index, int depth); //Function to display the heap structure
void removeRoot(int heap[101], int & size); //Function to remove the root (maximum element) from the heap
void removeAll(int heap[101], int & size); //Function to remove all elements from the heap

int main ()
{
  int heap[101];
  int size = 0;

  while(true)
    {
      char command[80];
      cout << "Enter command(ADD NUMBER/ADD FILE/REMOVE/REMOVE ALL/DISPLAY/QUIT):" << endl;
      cin.get(command, 80);
      cin.get();

      if(strcmp(command, "ADD NUMBER") == 0)
	{
	  int num;
	  cout << "Enter a number between 1 and 1000: " << endl;
	  cin >> num;
	  cin.ignore();
	  addNum(heap, size, num);
	}
      else if(strcmp(command, "ADD FILE") == 0)
	{
	  addFile(heap, size);
	}
      else if(strcmp(command, "REMOVE") == 0)
	{
	  removeRoot(heap, size);
	}
      else if(strcmp(command, "REMOVE ALL") == 0)
	{
	  removeAll(heap, size);
	}
      else if(strcmp(command, "DISPLAY") == 0)
	{
	  display(heap, size, 1, 0);
	}
      else if(strcmp(command, "QUIT") == 0)
	{
	  exit(0);
	  break;
	}
    }
  return 0;
}

void addNum(int heap[101], int & size, int num)
{
  if (size == 100)
    {
      cout << "Heap is full!" << endl;
      return;
    }
  
  int i = ++size;
  heap[i] = num;
  
  while(i > 1 && heap[i] > heap[i / 2])
    {
      swap(heap, i, i / 2);
      i = i / 2;
    }
}

void addFile(int heap[101], int & size)
{
  cout << "Enter fileName: " << endl;
  char filename[80];
  cin.get(filename, 80);
  cin.get();
  ifstream file(filename);
  if (file)
    {
      int num;
      while(file >> num)
	if(num >= 1 && num <= 1000)
	  addNum(heap, size, num);
      
      file.close();
    }
  else 
    cout << "File doesn't exist" << endl;
}

void swap(int heap[101], int childIndex, int parentIndex)
{
  int temp = heap[childIndex];
  heap[childIndex] = heap[parentIndex];
  heap[parentIndex] = temp;
}

void display(int heap[101], int size, int index, int depth)
{
  if(size == 0)
    {
      cout << "heap is empty!" << endl;
      return;
    }
  
  if (index > size)
    return;
  
  display(heap, size, index * 2 + 1, depth + 1);

  for(int i = 0; i< depth; i++)
    cout << "\t";

  cout << heap[index] << endl;
  
  display(heap, size, index * 2, depth + 1);
}

void removeRoot(int heap[101], int & size)
{
  if(size == 0)
    return;
  
  int maxValue = heap[1];
  heap[1] = heap[size--];  

  int i = 1;
  while(i * 2 <= size) 
    {
      int leftChild = i * 2;
      int rightChild = i * 2 + 1;
      int largerChild = leftChild;

      if(rightChild<= size && heap[rightChild] > heap[leftChild])
	largerChild = rightChild;

      if(heap[i] >= heap[largerChild])
	break;

      swap(heap, i, largerChild);
      i = largerChild;
    }
  cout << maxValue << " removed" << endl;
}

void removeAll(int heap[101], int & size)
{
  while(size > 0)
      removeRoot(heap, size);
}
