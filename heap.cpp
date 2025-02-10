#include <iosteam>

using namespace std;

void addNum(int heap[101], int heapSize, int num);
void swap(int heap[101], int child, int parent); // swapping child with parent
void display(int heap[101], int heapSize);
int removeRoot(int heap[101]);
void removeAll(int heap[101]);



int main ()
{
  int heap[101];

  
  return 0;
}

void addNum(int heap[101], int heapSize, int num)
{
  int i = heapSize + 1;
  heap[i] = num
  if(heap[i] > heap[floor(heap[i] / 2)])
    swap(heap, heap[i], heap[floor(heap[i] /2)]);
  else
    return;
  addNum(heap, heapSize + 1, num);
}

void swap(int heap[101], int childIndex, int parentIndex)
{
  int temp = heap[floor(childIndex / 2)];
  heap[parentIndex] = heap[childIndex];
  heap[childIndex] = temp;
}

void display(int heap[101], int heapSize)
{
  cout << "    " << heap[i] << endl;
  for(int i = 1; i < heapSize; i++)
    {
      cout << heap[i * 2] << "        " << heap [i * 2 + 1] << endl;
    }
}

int removeRoot(int heap[101])
{
  int temp = heap[1];
  if(heap[3] > heap[2])
    {
      heap[1] = heap[3];
      
      
}

void removeAll(int heap[101])
{

}
