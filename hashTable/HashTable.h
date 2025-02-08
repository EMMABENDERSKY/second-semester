#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>

using namespace std;

//Stucture to represent a student
struct Student
{
  int ID;
  char* firstName;
  char* lastName;
  float GPA;
  Student* next; //Pointer to next student
};
  
class HashTable
{
private:
  Student** table; //Pointer to array of student pointers (table)
  int tableSize;
  int IDcounter; //Counter for generating unique student IDs

public:
  HashTable(int); //Constuctor: Initializes the hash table wioth a given size 
  ~HashTable(); //Destructor: Deallocates the memory for the has table and students
  int hashFunction(int); //Hash finction: Computes a has value for a given student ID
  void rehash(); //Rehashing: Resizes the hash table anf redistributes students in case of too many collisions 
  void addStudent(char*, char*, float); //Function do add a student to the hash table
  void printStudents(); //Function to print the details of all students in the hash table
  void deleteStudent(int); //Function to delete a student from the has tabple by their ID
};
#endif
