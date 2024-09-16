#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
  const int maxLength = 80;
  char str[maxLength + 1]; //+1 for null terminator
  
  cout << "Enter a string (up to 80 characters): " << endl;
  cin.get(str, maxLength + 1);
  
  char cleaned[maxLength + 1];
  int cleanedIndex = 0;
  
  char reversed[maxLength + 1];
  
  //Remove all spaces and punctuation, and covert letters to lowercase
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
  
  cleaned[cleanedIndex] = '\0'; 
  
  //Create a reversed version of the cleaned string
  int length = strlen(cleaned);
  
  for(int i = 0; i < length; i++)
    {
      reversed[i] = cleaned[length - i - 1];
    }
  
  //Compare the cleaned string with its reversed version
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
