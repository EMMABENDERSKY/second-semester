#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char phrase[80];
  cin.get(phrase, 80);
  
  char altered[strlen(phrase)];
  
  //altering the first word
  altered[0] = phrase[1];
  altered[1] = phrase[0];

  //altering the rest of the words
    for(int i = 2; i < phrase[i] != '\0'; i++)
    {
      if(phrase[i-1] == ' ')
	{
	  altered[i] = phrase[i+1];
	  altered[i+1] = phrase[i];
	  i++;
      	}
      else
	altered[i] = phrase[i]; 
    }

  //printing altered phrase
    for(int i = 0; i < altered[i] != '\0'; i++)
    cout << altered[i];
  
  return 0;
}
