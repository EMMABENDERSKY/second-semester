#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

void addNum(int heap[101], int & size, int num); //Function to add a number to the heap
void swap(int heap[101], int childIndex, int parentIndex); //Function to swap two elements in the heap
void display(int heap[101], int size, int index, int depth); //Function to display the heap structure
void removeRoot(int heap[101], int & size); //Function to remove the root (maximum element) from the heap
void removeAll(int heap[101], int & size); //Function to remove all elements from the heap
void handleInput(int heap[101], int & size); //Function to handle user input for heap creation

int main ()
{
  int heap[101];
  int size = 0;
  
  handleInput(heap, size);
  cout << "Heap structure: " << endl;
  display(heap, size, 1, 0);

  cout << "Removing all elements: " << endl;
  removeAll(heap, size);
  
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

void swap(int heap[101], int childIndex, int parentIndex)
{
  int temp = heap[childIndex];
  heap[childIndex] = heap[parentIndex];
  heap[parentIndex] = temp;
}

void display(int heap[101], int size, int index, int depth)
{
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

void handleInput(int heap[101], int & size)
{
  cout << "Enter space-separated numbers (1-1000) or filename: " << endl;
  char input[101];
  cin.getline(input, 101);

  if(input[0] >= '1' && input[0] <= '9') //If input is space-separated numbers
    {
      int num;
      char *ptr = input;
      
      while(*ptr != '\0')
	{
	  while(*ptr == ' ')
	    ptr++;
	  
	  num = 0;
	  while(*ptr >= '0' && *ptr <= '9')
	    {
	      num = num * 10 + (*ptr - '0');
	      ptr++;
	    }

	  if(num >= 1 && num <= 1000)
	    addNum(heap, size, num);
	}
    }
  else //If input is a filename
    {
      ifstream file(input);
      if (file)
	{
	  int num;
	  while(file >> num)
	    if(num >= 1 && num <= 1000)
	      addNum(heap, size, num);

	  file.close();
	}
      else //if file doesn't exist
	cout << "File doesn't exist" << endl;
    }
}
