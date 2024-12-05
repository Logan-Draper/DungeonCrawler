#include "room_bank.h"

// General Constructor
RB::RB(){};

// Searches the room and randomly gives gold, spawns enemies, or does nothing.
char RB::search(Player &P1, room CR) {
  LG loot;
  cout << "=================================" << endl;
  cout << "||You chose to INSPECT the room||" << endl;
  cout << "=================================" << endl;
  cout << endl << CR.inspection_text << endl << endl;
  int random_event = rand() % 4;
  switch (random_event) {
  case (0): {
    cout << "Oh!! You found some gold on the floor.. " << endl;
    cout << "Who was here before you then..?" << endl;
    int random_gold_amount;
    if (CR.room_level <= 1) {
      random_gold_amount = rand() % 51;
    }
    if (CR.room_level == 2) {
      random_gold_amount = rand() % 101;
    }

    if (CR.room_level >= 3) {
      random_gold_amount = rand() % 250;
    }

    loot.add_item(P1.player_inventory_generic, gold, random_gold_amount);
    this_thread::sleep_for(chrono::milliseconds(2500));
    return 'L';
  }
  case (1):
    cout << "Looks like some straggling enemies are still here!" << endl;
    cout << "Take em down would you?" << endl;
    this_thread::sleep_for(chrono::milliseconds(2500));
    return 'C';
  case (2):
  case (3):
  default:
    cout << "Oh.. Nothing Happened.. Okay.. " << endl;
    this_thread::sleep_for(chrono::milliseconds(2500));
  };
  return ' ';
}
// Prints the room description.
char RB::print_room(Player &P1, room CR) {
  system("clear");
  char input;
  cout << "==========================================" << endl;
  cout << "                                          " << endl;
  cout << CR.description << endl;
  cout << "                                          " << endl;
  cout << "==========================================" << endl;
  cout << "(I) to inspect the room" << endl;
  cout << "(B) to go back to map.." << endl;
  cin >> input;
  char inspect_input = ' ';
  if (input == 'I' || input == 'i') {
    inspect_input = search(P1, CR);
  }
  return inspect_input;
}

// Room Generated Instances.
RB::room room_1_1("Its a dark dusty brick room..",
                  "The walls seem to be oozing a little..", 1);
RB::room room_1_2("A portrait of Dr. Marz hangs on the wall..",
                  "You know I had to do it", 1);
RB::room room_1_3("Spongebob is here? But he looks.. freaky? ",
                  "Is this Dante's inferno?", 1);
RB::room room_1_4("There is a large fountain in the middle of the room.. ",
                  "The fountain seems to have grease pouring out of it..", 1);

RB::room room_1_5("Jackson Mowry? What are you doing here?",
                  "Linked Lists Suck! Just use vectors!", 1);

RB::room room_1_6("Damp air fills the room",
                  "Rusty swords lay abandoned in the corner.", 1);

RB::room room_1_7("A dust-covered stone altar stands in the center",
                  "stubbed candles lay beside the alter..", 1);

RB::room room_1_8("Broken weapons and armor litter the floor: an old "
                  "forge,cold in the corner.",
                  "A well worn hammer lay in the corner..", 1);

RB::room room_1_9("Thick webs drape the room",
                  "You hear something scuttering nearby..", 1);

RB::room room_1_10("You have a soul-reaching feeling to turn back..",
                   "You catch a glimpse of something scurrying away..", 1);

vector<RB::room> room_level_1 = {room_1_1, room_1_2, room_1_3, room_1_4,
                                 room_1_5, room_1_6, room_1_7, room_1_8,
                                 room_1_9, room_1_10};
