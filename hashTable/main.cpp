#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Student
{
  char firstName[80];
  char lastName[80];
  int ID;
  float GPA;
};

int main()
{
  srand(time(0));

  while(true)
    {
      char command[10];
      cout << "Enter a command (ADD/PRINT/DELETE/AVERAGE/QUIT): " << endl;
      cin.get(command, 10);
      cin.get();

      if(strcmp(command, "ADD") == 0)
        {

        }

      if(strcmp(command, "PRINT") == 0)
        {

        }

      if(strcmp(command, "DELETE") == 0)
        {

        }

      if(strcmp(command, "QUIT") == 0)
        {

        }
    }
  return 0;
}





