#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"
#include "Room.h"

using namespace std;

//winning condition: player has to reach the "computer lab" (room 15) while having at least one item in their inventory

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
  initializeRooms();

  return 0;
}

void initializeRooms()
{
   room1->addExit("NORTH", room2);
    room2->addExit("SOUTH", room1);
    room2->addExit("EAST", room3);
    room3->addExit("WEST", room2);
    room3->addExit("NORTH", room4);
    room4->addExit("DOWN", room3);
    room4->addExit("WEST", room5);
    room5->addExit("EAST", room4);
    room5->addItem(backpack);
    room6->addItem(pencil);
    room7->addItem(eraser);
    room8->addItem(highlighter);
    room9->addItem(notebook);
    room10->addExit("EAST", room11);
    room11->addExit("WEST", room10);
    room12->addExit("NORTH", room13);
    room13->addExit("SOUTH", room12);
    room14->addExit("EAST", room15);
    room15->addExit("WEST", room14); 
}

void playGame(0)
{
  char command[80];
  char directior[80];

  while(true)
    {
      cout <<currentRoom->getDescription() << endl;
      
      cout << "Exits: ";
      for (map<const char*, Room*>::iterator it = currentRoom->getExits().begin(); it != currentRoom->getExits().end(); ++it)
	cout << it->first << " ";
      cout << endl;

      cout << "Items in the room: ";
      for (vector<Item*>::iterator it = currentRoom->getItems().begin(); it != currentRoom->getItems().end(); ++it) 
	cout << (*it)->getName() << " "; 
      cout << endl;
      cout << "Inventory: ";
      for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) 
	cout << (*it)->getName() << " ";

      cout << "Enter command (GO <direction>, LOOK, GET <item>, DROP <item>, QUIT): ";
      cin >> command;
      cin.ignore();

      if(strcmp(command, "QUIT") == 0)
	{
	  cout << "Goodbye!" << endl;
	  exit(0);
	  break;
	}
      else if(strcmp(command "GO") == 0)
	{
	  cin >> direction;
	  cin.ignore();
	  map<comst char*, Room*

}

