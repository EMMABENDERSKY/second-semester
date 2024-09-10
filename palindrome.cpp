#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
  char str[80];
  cin.get(str, 80); 
  char cleaned[80];
  int cleanedIndex = 0;
  char reversed[80];
  for (int i = 0; str[i] != '\0'; i++)
  {
    if(isalnum(str[i]))
      {
	if(isupper(str[i]))
	  {
	    tolower(str[i]);
	  }
	cleaned[cleanedIndex] = str[i];
	cleanedIndex++;
      } 
  }

  for(int i = 0; i < strlen(cleaned); i--)
    {
      reversed[i] = cleaned[strlen(cleaned) - i];
    }

  if(strcmp(cleaned, reversed) == 0)
    {
      cout << "Palindrome" << endl;
    }

  else
    {
      cout << "Not a palindrome" << endl;
    }

  return 0; 
}
