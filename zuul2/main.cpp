#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"
#include "Room.h"

using namespace std;

//winning condition: player has to collect all items and put them in the victory room.

//function prototypes
void setUpRooms(vector<Room*> & rooms, vector<Item*> & items);
void displayRoom(Room* room);
Room* move(Room* currentRoom, char* direction);
bool checkWinCondition(vector<Item*> & invetory, Room* vectoryRoom);

int main()
{
  vector<Room*> rooms;
  vector<Item*> items;
  vector<Item*> inventory;

  setUpRooms(rooms, items);

  Room* currentRoom = rooms[0];
  Room* victoryRoom = rooms[15];

  bool gameRunning = true;
  while(gameRunning)
    {
      displayRoom(currentRoom);

      char command[10];
      cout << "Enter command (NORTH/SOUTH/EAST/WEST/PICKUP/DROP/QUIT): " << endl;
      cin.get(command, 10);
      cin.get();

      if(strcmp(command, "QUIT") == 0)
        gameRunning = false;

      else if(strcmp(command, "NORTH") == 0 || strcmp(command, "SOUTH") == 0 || strcmp(command, "EAST") == 0 || strcmp(command, "WEST") == 0)
        Room* nextRoom = move(currentRoom, command);

      else if(strcpy(command, "PICKUP") == 0)
        {
          if(!currentRoom->getItems().empty())
            {
            Item* item = currentRoom->getItems().back();
            inventory.push_back(item);
            currentRoom->removeItem(item);
            cout << "Picked up: " << item->getName() << endl;
            }
          else
            cout << "No items to pick up." << endl;
        }

      else if(strcmp(command, "DROP") == 0)
        {
          if(!inventory.empty())
            {
              Item* item = inventory.back();
              inventory.pop_back();
              currentRoom->addItem(item);
              cout << "Dropped: " << item -> getName() << endl;
            }
          else
            cout << "No items to drop." << endl;
        }
    }

  return 0;
}

void setUpRooms(vector<Room*> & rooms, vector<Item*> & items)
{
  rooms.push_back(new Room("Starting room with exits in all directions.", false));//#1
  rooms.push_back(new Room("1 Hall", false));//#2
  rooms.push_back(new Room("Library", false));//#3
  rooms.push_back(new Room("Classroom", false));//#4
  rooms.push_back(new Room("Gym", false));//#5
  rooms.push_back(new Room("Science lab", false));//#6
  rooms.push_back(new Room("2 Hall", false));//#7
  rooms.push_back(new Room("Cafeteria", false));//#8
  rooms.push_back(new Room("Bathroom", false));//#9
  rooms.push_back(new Room("Art room", false));//#10
  rooms.push_back(new Room("Auditorium", false));//#11
  rooms.push_back(new Room("3 Hall", false));//#12
  rooms.push_back(new Room("Band room", false));//#13
  rooms.push_back(new Room("Choir room", false));//#14
  rooms.push_back(new Room("Computer lab (VICTORY ROOM!!!!!)- drop all items here to win.", true));//#15

  //link room with exits
  rooms[0]->setExit("NORTH", rooms[1]);//exit from room 0 to 1
  rooms[0]->setExit("EAST", rooms[2]);//exit from room 0 to 2
  rooms[0]->setExit("SOUTH", rooms[3]);//exit from room 0 to 3
  rooms[0]->setExit("WEST", rooms[4]);//exit from room 0 to 4
  rooms[1]->setExit("SOUTH", rooms[0]);//exit from room 1 to 0
  rooms[2]->setExit("WEST", rooms[0]);//exit from room 2 to 0
  rooms[3]->setExit("NORTH", rooms[0]);//exit from room 3 to 0
  rooms[4]->setExit("EAST", rooms[0]);//exit from room 4 to 0
  rooms[4]->setExit("WEST", rooms[5]);//exit from room 4 to 5
  rooms[5]->setExit("EAST", rooms[4]);//exit from room 5 to 4
  rooms[5]->setExit("NORTH", rooms[6]);//exit from room 5 to 6
  rooms[5]->setExit("SOUTH", rooms[7]);//exit from room 5 to 7
  rooms[6]->setExit("SOUTH", rooms[5]);//exit from room 6 to 5
  rooms[7]->setExit("NORTH", rooms[5]);//exit from room 7 to 5
  rooms[7]->setExit("SOUTH", rooms[8]);//exit from room 7 to 8
  rooms[7]->setExit("WEST", rooms[9]);//exit from room 7 to 9
  rooms[8]->setExit("NORTH", rooms[7]);//exit from room 8 to 7
  rooms[9]->setExit("EAST", rooms[7]);//exit from room 9 to 7
  rooms[9]->setExit("EAST", rooms[10]);//exit from room 9 to 10
  rooms[10]->setExit("WEST", rooms[9]);//exit from room 10 to 9
  rooms[10]->setExit("SOUTH", rooms[11]);//exit from room 10 to 11
  rooms[11]->setExit("NORTH", rooms[10]);//exit from room 11 to 10
  rooms[11]->setExit("EAST", rooms[12]);//exit from room 11 to 12
  rooms[11]->setExit("SOUTH", rooms[13]);//exit from room 11 to 13
  rooms[12]->setExit("WEST", rooms[11]);//exit from room 12  to 11
  rooms[11]->setExit("NORTH", rooms[11]);//exit from room 13 to 11
  rooms[13]->setExit("SOUTH", rooms[14]);//exit from room 13 to 14
  rooms[13]->setExit("WEST", rooms[15]);//exit from room 13 to 15
  rooms[14]->setExit("NORTH", rooms[13]);//exit from room 14 to 13
  rooms[15]->setExit("EAST", rooms[13]);//exit from room 15 to 13

  //create items and pace them in rooms
  items.push_back(new Item("backpack"));
  items.push_back(new Item("pencil"));
  items.push_back(new Item("eraser"));
  items.push_back(new Item("highlighter"));
  items.push_back(new Item("notebook"));

  rooms[2]->addItem(items[0]);
  rooms[6]->addItem(items[1]);
  rooms[8]->addItem(items[2]);
  rooms[10]->addItem(items[3]);
  rooms[14]->addItem(items[4]);
}


void displayRoom(Room* room)
{
  cout << room->getDescription() << "\nExits: ";
  if(room->getExit("NORTH"))
    cout << "NORTH ";
  else if (room->getExit("SOUTH"))
    cout << "SOUTH ";
  else if(room->getExit("EAST"))
    cout << "EAST ";
  else if (room->getExit("WEST"))
    cout << "WEST ";

  cout << "\nItems: ";
    
  
}

Room* move(Room* currentRoom, char* direction)
{
  return currentRoom->getExit(direction);
}

bool checkWinCondition(vector<Item*>& inventory, Room* victoryRoom)
{
  bool foundInRoom;
  
  for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++)
    {
      foundInRoom = false;

      if(strcmp((*it)->getName(), victoryRoom->getItems()) == 0)
	{
	  foundInRoom = true;
	  break;
	}
    }
  if(!foundInRoom)
    return false;
  return true;
}


  
