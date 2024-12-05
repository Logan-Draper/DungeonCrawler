#include "loot_gen.h"
#include <iostream>
#include <vector>
using namespace std;
// Adds a generic item like feathers or iron to the players inventory.
void LG::add_item(vector<ITEM_LIST::item_generic> &list,
                  ITEM_LIST::item_generic item, int quantity) {
  for (size_t i = 0; i < list.size(); i++) {
    if (list[i].name == item.name) {
      list[i].quantity += quantity;
      return;
    }
  }
  for (size_t i = 0; i < reference_list.size(); i++) {
    if (reference_list[i].name == item.name) {
      list.push_back(reference_list[i]);
      list[i].quantity = quantity;
      return;
    }
  }
  ITEM_LIST::item_generic PLACE_HOLDER = {item.name, "", 0, quantity};
  cout << "We should not be here. But I will add the PLACEHOLDER regardless.."
       << endl;
  list.push_back(PLACE_HOLDER);
  return;
}
// Adds a healing item to the player's inventory.
void LG::add_item_healing(vector<HEALING_ITEM::healing> &list,
                          HEALING_ITEM::healing h_item, int quantity) {
  if (list.size() != 0) {
    for (size_t i = 0; i < list.size(); i++) {
      if (list[i].name == h_item.name) {
        list[i].quantity += quantity;
      }
    }
  }
  for (size_t i = 0; i < reference_healing_list.size(); i++) {
    if (reference_healing_list[i].name == h_item.name) {
      list.push_back(reference_healing_list[i]);
      list[i].quantity += quantity;
      return;
    }
  }
  cout << "UNKNOWN ITEM" << endl;
  return;
}
// Updates the players inventory based on the enemy ID of the defeated enemy.
void LG ::produce_loot(int enemy_num, Player &P1) {

  switch (enemy_num) {

  case 200: {
    cout << "The goblin dropped: " << endl;

    int temp = (rand() % 100 + 1);
    if (temp > 0 && temp <= 80) {
      cout << "2 gold pieces" << endl;
      add_item(P1.player_inventory_generic, gold, 2);
      return;
    } else if (temp > 80 && temp <= 95) {
      cout << "2 gold pieces" << endl;
      cout << "And some leather" << endl;
      add_item(P1.player_inventory_generic, gold, 2);
      add_item(P1.player_inventory_generic, leather, 2);
      return;
    }

    else {
      cout << "2 gold pieces" << endl;
      cout << "And some leather" << endl;
      cout << "And a tibia? I think? Gross." << endl;
      add_item(P1.player_inventory_generic, gold, 2);
      add_item(P1.player_inventory_generic, leather, 2);
      add_item(P1.player_inventory_generic, bones, 1);
      return;
    }
  }

  case 100:
  case 101:
  case 102: {
    cout << "The skeleton dropped: " << endl;

    int temp = (rand() % 100 + 1);
    if (temp > 0 && temp <= 55) {
      cout << "3 gold pieces" << endl;
      add_item(P1.player_inventory_generic, gold, 3);
      return;
    }

    else if (temp > 55 && temp <= 90) {
      cout << "3 gold pieces" << endl;
      cout << "And 3 withered bones" << endl;
      add_item(P1.player_inventory_generic, gold, 3);
      add_item(P1.player_inventory_generic, bones, 3);
      return;
    }

    else {
      cout << "3 gold pieces" << endl;
      cout << "3 withered bones" << endl;
      cout << "And a rusty broad sword" << endl;
      add_item(P1.player_inventory_generic, gold, 3);
      add_item(P1.player_inventory_generic, bones, 3);
      return;
    }
  }

  case 502: {
    cout << "The Ogre dropped: " << endl;

    int temp = (rand() % 100 + 1);
    if (temp > 0 && temp <= 55) {
      cout << "1 gold piece" << endl;
      add_item(P1.player_inventory_generic, gold, 1);
      return;
    }

    else if (temp > 55 && temp <= 90) {
      cout << "1 gold piece" << endl;
      cout << "An Ogre Eye" << endl;
      return;
    }

    else {
      cout << "1 gold piece" << endl;
      cout << "An Ogre Eye" << endl;
      cout << "And a Club" << endl;
      add_item(P1.player_inventory_generic, gold, 1);
      return;
    }
  }

  case 005: {

    cout << "The Spirit faded away." << endl;
    int temp = (rand() % 100 + 1);

    if (temp <= 99) {
      cout << "The spirit left no remnant" << endl;
      cout << "You monster." << endl;
    } else {
      cout << "WOW IT DROPPED ECTOPLASAM" << endl;
    }
    return;
  }

  case 401:
  case 402:
    cout << "The Vampire Dropped a lot of gold" << endl;
    cout << "And a lot of blood.. gross" << endl;
    add_item(P1.player_inventory_generic, gold, 15);
    return;

  case 103:
    cout << "Wow! You killed a necromancer and it just fades away.." << endl;
    return;
  case 301:
    cout << "The Sun Praiser Falls.." << endl;
    cout << "They had no use for money.." << endl;
    return;

  case 302:
    cout << "The werebear hadn't a dime on him. Sad.." << endl;
    return;
  case 303:
    cout << "The sun itself must always fall.. " << endl;
    return;

  case 304:
    cout << "The ghost clad in metal falls." << endl;
    return;
  case 501:
    cout << "Back to the swamp with you foul thing.." << endl;
    return;
  default: {
  }
  };
}
// Prints the item description.
void LG::selected_item(ITEM_LIST::item_generic &item) {
  system("clear");
  cout << "==================================" << endl;
  cout << "                                  " << endl;
  cout << item.description << endl;
  cout << "                                  " << endl;
  cout << "==================================" << endl;
}
// Uses the item passed and removes it from the players inventory.
void LG::selected_healing_item(Player &P1, HEALING_ITEM::healing &item) {
  system("clear");
  char input;
  cout << "==================================" << endl;
  cout << "                                  " << endl;
  cout << item.description << endl;
  cout << "                                  " << endl;
  cout << "==================================" << endl;
  cout << "(U) to use Item" << endl;
  cin >> input;

  if (input == 'u' || input == 'u') {
    P1.current_health += item.health;
    if (P1.current_health > P1.MAX_HEALTH) {
      P1.current_health = P1.MAX_HEALTH;
    }
    for (size_t i = 0; i < P1.player_inventory_healing.size(); i++) {
      if (P1.player_inventory_healing[i].name == item.name) {
        P1.player_inventory_healing[i].quantity -= 1;
      }
      if (P1.player_inventory_healing[i].quantity <= 0) {
        P1.player_inventory_healing.erase(P1.player_inventory_healing.begin() +
                                          i);
      }
    }
  }
  return;
}
// Prints Players inventory and lets you look at items.
void LG::print_inventory(Player &P1) {
  system("clear");
  char c_input;
  int input;
  int counter = 1;
  cout << "           INVENTORY:                 " << endl;
  cout << "======================================" << endl;
  for (size_t i = 0; i < P1.player_inventory_generic.size(); i++) {
    cout << "[" << counter << "]" << P1.player_inventory_generic[i].name << ": "
         << P1.player_inventory_generic[i].quantity << endl;
    counter++;
  }
  for (size_t i = 0; i < P1.player_inventory_healing.size(); i++) {
    cout << "[" << counter << "]" << P1.player_inventory_healing[i].name << ": "
         << P1.player_inventory_healing[i].quantity << endl;
    counter++;
  }
  cout << endl;
  cout << "======================================" << endl;
  cout << "Would you like to select an item?" << endl;
  cout << "(N) for No." << endl;
  cin >> c_input;
  if (c_input == 'N' || c_input == 'n') {
    return;
  }
  input = c_input - '0';
  if ((size_t)input <= P1.player_inventory_generic.size() && input != 0) {
    selected_item(P1.player_inventory_generic[input - 1]);
  } else if ((size_t)input > P1.player_inventory_generic.size() &&
             input - P1.player_inventory_generic.size() <=
                 P1.player_inventory_healing.size()) {
    selected_healing_item(P1, P1.player_inventory_healing[input - 1]);
  } else {
    cout << "I couldn't process this input.." << endl;
    return;
  }
  return;
}
