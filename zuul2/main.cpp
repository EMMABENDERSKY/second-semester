#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"
#include "Room.h"

using namespace std;

//winning condition: player has to reach the "computer lab" (room 15) while having at least one item in their inventory

//instructions for winning the game:
// GO NORTH
// GO EAST
// GO NORTH
// GO WEST
// GET backpack
// GO NORTH
// GET pencil
// GO EAST
// GET eraser
// GO NORTH
// GET highlighter
// GO EAST
// GET notebook
// GO NORTH
// GO EAST
// GO NORTH
// GO NORTH
// GO EAST
// GO EAST

//items:
Item* backpack = new Item("backpack");
Item* pencil = new Item("pencil");
Item* eraser = new Item("eraser");
Item* highlighter = new Item("highlighter");
Item* notebook = new Item("notebook");

//rooms:
Room* room1 = new Room("Starting room.", "Room 1");
Room* room2 = new Room("1 Hall", "Room 2");
Room* room3 = new Room("Library", "Room 3");
Room* room4 = new Room("Classroom", "Room 4");
Room* room5 = new Room("Gym", "Room 5");
Room* room6 = new Room("Science lab", "Room 6");
Room* room7 = new Room("2 Hall", "Room 7");
Room* room8 = new Room("Cafeteria", "Room 8");
Room* room9 = new Room("Bathroom", "Room 9");
Room* room10 = new Room("Art room", "Room 10");
Room* room11 = new Room("Auditorium", "Room 11");
Room* room12 = new Room("3 Hall", "Room 12");
Room* room13 = new Room("Band room", "Room 13");
Room* room14 = new Room("Choir room", "Room 14");
Room* room15 = new Room("Congratulations, you have reached the computer lab!!!", "Room 15");

vector<Item*> inventory; //player inventory
Room* currentRoom = room1; //currrent room

//function prototypes:
void initializeRooms(); //function toinitialize rooms and their connections
void playGame(); //game loop
		  
int main()
{
  // Display instructions
  cout << "Welcome to the game!" << endl;
  cout << "Instructions:" << endl;
  cout << "1. Use the 'GO <direction>' command to move to a new room." << endl;
  cout << "   Example: GO NORTH, GO EAST, etc." << endl;
  cout << "2. Use the 'GET <item>' command to pick up an item from the room." << endl;
  cout << "   Example: GET backpack, GET pencil, etc." << endl;
  cout << "3. Use the 'DROP <item>' command to drop an item from your inventory." << endl;
  cout << "   Example: DROP pencil, DROP backpack, etc." << endl;
  cout << "4. Use the 'QUIT' command to end the game." << endl;
  cout << "5. Your goal is to reach the Computer Lab (Room 15) with at least one item in your inventory." << endl;
  cout << "   Good luck!" << endl << endl;
  
  initializeRooms();
  playGame();
  
  //clean up memory
  delete backpack;
  delete pencil;
  delete eraser;
  delete highlighter;
  delete notebook;
  delete room1;
  delete room2;
  delete room3;
  delete room4;
  delete room5;
  delete room6;
  delete room7;
  delete room8;
  delete room9;
  delete room10;
  delete room11;
  delete room12;
  delete room13;
  delete room14;
  delete room15;
  
  return 0;
}

void initializeRooms()
{
  room1->addExit("NORTH", room2);  // Starting room to 1 Hall (Room 2)
  room2->addExit("SOUTH", room1);  // 1 Hall back to Starting room
  room2->addExit("EAST", room3);   // 1 Hall to Library (Room 3)
  room3->addExit("WEST", room2);   // Library back to 1 Hall
  room3->addExit("NORTH", room4);  // Library to Classroom (Room 4)
  room4->addExit("SOUTH", room3);  // Classroom back to Library
  room4->addExit("WEST", room5);   // Classroom to Gym (Room 5)
  room5->addExit("EAST", room4);   // Gym back to Classroom
  room5->addExit("NORTH", room6);  // Gym to Science lab (Room 6)
  room6->addExit("SOUTH", room5);  // Science lab back to Gym
  room6->addExit("EAST", room7);   // Science lab to 2 Hall (Room 7)
  room7->addExit("WEST", room6);   // 2 Hall back to Science lab
  room7->addExit("NORTH", room8);  // 2 Hall to Cafeteria (Room 8)
  room8->addExit("SOUTH", room7);  // Cafeteria back to 2 Hall
  room8->addExit("EAST", room9);   // Cafeteria to Bathroom (Room 9)
  room9->addExit("WEST", room8);   // Bathroom back to Cafeteria
  room9->addExit("NORTH", room10); // Bathroom to Art room (Room 10)
  room10->addExit("SOUTH", room9); // Art room back to Bathroom
  room10->addExit("EAST", room11); // Art room to Auditorium (Room 11)
  room11->addExit("WEST", room10); // Auditorium back to Art room
  room11->addExit("NORTH", room12);// Auditorium to 3 Hall (Room 12)
  room12->addExit("SOUTH", room12);// 3 hall back to Auditorim
  room12->addExit("NORTH", room13); // 3 Hall to Band room (Room 13)
  room13->addExit("SOUTH", room12); // Band room back to 3 Hall
  room13->addExit("EAST", room14);//Band room to choir room (Room 14)
  room14->addExit("WEST",room13);//Choir room back to band room
  room14->addExit("EAST", room15); // Choir room to Computer Lab (Room 15)
  room15->addExit("WEST", room14); // Computer Lab back to Choir room
  
  // Adding items to rooms
  room5->addItem(backpack);   // Gym has backpack
  room6->addItem(pencil);     // Science lab has pencil
  room7->addItem(eraser);     // 2 Hall has eraser
  room8->addItem(highlighter); // Cafeteria has highlighter
  room9->addItem(notebook);   // Bathroom has notebook
}

void playGame()
{
  char command[80];
  char direction[80];
  while(true)
    {
      cout << currentRoom->getDescription() << endl << endl;
      
      cout << "Exits: ";
      for (map<const char*, Room*>::const_iterator it = currentRoom->getExits().begin(); it != currentRoom->getExits().end(); ++it)
	cout << it->first << " ";
      cout << endl << endl;
      
      cout << "Items in the room: ";
      for (auto it = currentRoom->getItems().begin(); it != currentRoom->getItems().end(); ++it)
	cout << (*it)->getName() << " ";  
      cout << endl << endl;
      
      cout << "Inventory: ";
      for (vector<Item*>::const_iterator it = inventory.begin(); it != inventory.end(); ++it)	
        cout << (*it)->getName() << " ";
      cout << endl << endl;
      
      cout << "Enter command (GO <direction>, GET <item>, DROP <item>, QUIT): ";
      cin >> command;
      cin.ignore();
      
      if(strcmp(command, "QUIT") == 0)
	{
	  cout << "Goodbye!" << endl;
	  exit(0);
	  break;
	}
      else if(strcmp(command, "GO") == 0)
	{
	  cin >> direction;
	  cin.ignore();
	  bool found = false;
	  for (map<const char*, Room*>::const_iterator it = currentRoom->getExits().begin(); it != currentRoom->getExits().end(); ++it)
	    {
	      if(strcmp(direction, it->first) == 0)  // Compare the direction with the key in exits
		{
		  currentRoom = it->second;
		  found = true;
		  break;
		}
	    }
	  if (!found)
	    cout << "Invalid direction. Please enter a valid direction." << endl;
	}
      else if (strcmp(command, "GET") == 0)
	{
	  cin >> direction;
	  cin.ignore();
	  bool found = false;
	  for (auto it = currentRoom->getItems().begin(); it != currentRoom->getItems().end(); ++it)
	    {
	      if (strcmp(direction, (*it)->getName()) == 0)
		{
		  inventory.push_back(*it);
		  currentRoom->removeItem(*it);
		  found = true;
		  break;
		}
	    }
	  if(!found)
	    cout << "Item not found." << endl;
	}
      else if (strcmp(command, "DROP") == 0)
	{
	  cin >> direction;
	  cin.ignore();
	  bool found = false;
	  for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	    {
	      if (strcmp(direction, (*it)->getName()) == 0)
		{
		  currentRoom->addItem(*it);
		  inventory.erase(it); 
		  found = true;
		  break;
                }
            }
	  if (!found) 
	    cout << "Item not found in inventory." << endl;
        }
      else
	cout << "Invalid command." << endl;

      //winning condition
      if (currentRoom == room15 && !inventory.empty())
	{ 
	  cout << "Congratulations! You have won the game!" << endl;
	  break;
        }
    }
}
