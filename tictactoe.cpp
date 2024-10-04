#include <iostream>
#include <cstring>

using namespace std;

void resetBoard(char grid[4][4], int gridSize);
void drawGrid(char grid[4][4]);
void getMove(char grid[4][4], char player);
bool isMoveLegal(char grid[4][4], int row, int col);
bool checkWin(char grid[4][4], char player);
bool checkTie(char grid[4][4]);
void updateWins(char winner, int & Xwins, int & Owins);

int main()
{
  char grid[4][4] = {{' ', '1', '2', '3'},
		     {'a', ' ', ' ', ' '},
		     {'b', ' ', ' ', ' '},
		     {'c', ' ', ' ', ' '}};
  int Xwins = 0, Owins = 0;
  bool gameOngoing = true;

  while(true)
    {
      char currentPlayer = 'X';
      resetBoard(grid, 4);
      gameOngoing = true;

      cout << "drawing the board: " << endl;
      drawGrid(grid);
      
      while(gameOngoing)
	{
	  getMove(grid, currentPlayer);

	  cout << "drawing board: " << endl;
	  drawGrid(grid);
  
	  //Check if the current player wins
	  if(checkWin(grid, currentPlayer))
	    {
	      cout << "Player " << currentPlayer << " wins!" << endl;
	      updateWins(currentPlayer, Xwins, Owins);
	      gameOngoing = false;
	    }

	  //Check if its a tie
	  if(checkTie(grid))
	    {
	      cout << "It's a tie!";
	      gameOngoing = false;
	    }

	  //Switch player
	  if(currentPlayer == 'X')
	    currentPlayer = 'O';
	  else
	    currentPlayer = 'X';
	}

      //Show winning totals
      cout << "X wins: " << Xwins << ", O wins: " << Owins << endl;
    }
    
  return 0;
}

//Functions//

//Reset the board
void resetBoard(char grid[4][4], int gridSize)
{
  for(int i = 0; i < 4; i++)
    {
      for(int j  = 0; j < 4; j++)
	{
	  grid[i][j] = ' ';
	}
    }
  grid[0][1] = '1';
  grid[0][2] = '2';
  grid[0][3] = '3';
  grid[1][0] = 'a';
  grid[2][0] = 'b';
  grid[3][0] = 'c';
}

//Draw the grid
void drawGrid(char grid[4][4])
{
  for(int i = 0; i < 4 ; i++)
    {
      for(int j = 0; j < 4; j++)
	{
	  cout << " | " << grid[i][j];
	}
      cout << endl;
    }
}

//Get the player's move
void getMove(char grid[4][4], char player)
{
  int row = -1, col = -1;
  char rowChar;

  do
    {
    cout<< "Player " << player << "'s turn. Enter your move (e.g. a1, b3): " << endl;
    cin >> rowChar >> col;

    switch (rowChar)
      {
      case 'a':
	row = 1;
	break; 
      case 'b':
	row = 2;
	break;
      case 'c':
	row = 3;
	break;
      }
      
    }while(isMoveLegal(grid, row, col) == false);
  
    grid[row][col] = player;
}

//Check if the move is legal 
bool isMoveLegal(char grid[4][4], int row, int col)
{
  if ((row >= 1 && row <= 4) && (col >= 1 && col <= 4) && (grid[row][col] == ' '))
    return true;
  return false;
}

//Check if a player has won
bool checkWin(char grid[4][4], char player)
{
  for (int i = 1; i < 3; i++)
    {
      for(int j = 1; j < 3; j++)
	{
	  if((grid[i][1] == player && grid[i][2] == player && grid[i][3] == player) || (grid[1][i] == player && grid[2][i] == player && grid[3][i] == player) || (grid[1][1] == player && grid[2][2] == player && grid[3][3] == player) || (grid[1][3] == player && grid[2][2] == player && grid[3][1] == player)) 
	return true;
	}
    }
  return false;
}

//Check if there's a tie
bool checkTie(char grid[4][4])
{
  for(int i = 1; i < 4; i++)
    {
      for(int j = 1; j < 4; j++)
	{
	  if(grid[i][j] == ' ')
	    return false; //Found an empty spot, there is no tie
	}
    }
  return true;
}

//Update win totals
void updateWins(char winner, int & Xwins, int & Owins)
{
  if(winner == 'X')
    Xwins++;
  else
    Owins++;
}

 
