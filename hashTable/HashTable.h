#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>

using namespace std;

struct Student
{
  int ID;
  char firstName[80];
  char lastName[80];
  float GPA;
  Student* next;
};
  
class HashTable
{
private:
  Student** table;
  int tableSize;
  int IDcounter;

public:
  HashTable(int);
  ~HashTable();
  int hashFunction(int);
  void rehash();
  void addStudent(char, char, float);
  void printStudents();
  void deleteStudent(int);
};
#endif
