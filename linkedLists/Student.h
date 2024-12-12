#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
 public:
  Student();
  Student(char*, int, double);
  char* getName();
  int getID();
  double getGPA();
  
 private:
  char* name;
  int ID;
  double GPA;
};

#endif
