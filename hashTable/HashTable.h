#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>

using namespace std;

struct Student
{
  char firstName[80];
  char lastName[80];
  int ID;
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
  void deleteStudent();
  void printStudent(int);
};
#endif
