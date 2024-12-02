#include "loot_gen.h"
#include <iostream>
#include <vector>
using namespace std;

vector<ITEM_LIST::item_generic> player_inventory;

void LG::add_item(vector<ITEM_LIST::item_generic> &list, string name,
                  int quantity) {
  for (int i = 0; i < list.size(); i++) {
    if (list[i].name == name) {
      list[i].quantity += quantity;
      return;
    }
  }
  for (int i = 0; i < reference_list.size(); i++) {
    if (reference_list[i].name == name) {
      list.push_back(reference_list[i]);
      list[i].quantity = quantity;
      return;
    }
  }
  ITEM_LIST::item_generic PLACE_HOLDER = {name, "", 0, quantity};
  cout << "We should not be here. But I will add the PLACEHOLDER regardless.."
       << endl;
  list.push_back(PLACE_HOLDER);
  return;
}

void LG ::produce_loot(int enemy_num) {

  switch (enemy_num) {

  case 200: {
    cout << "The goblin dropped: " << endl;

    int temp = (rand() % 100 + 1);
    if (temp > 0 && temp <= 80) {
      cout << "2 gold pieces" << endl;
      add_item(player_inventory, "Gold", 2);
      return;
    }

    else if (temp > 80 && temp <= 95) {
      cout << "2 gold pieces" << endl;
      cout << "And some leather" << endl;
      add_item(player_inventory, "Gold", 2);
      add_item(player_inventory, "Leather", 2);
      return;
    }

    else {
      cout << "2 gold pieces" << endl;
      cout << "And some leather" << endl;
      cout << "And a tibia? I think? Gross." << endl;
      add_item(player_inventory, "Gold", 2);
      add_item(player_inventory, "Leather", 2);
      add_item(player_inventory, "Bones", 1);
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
      add_item(player_inventory, "Gold", 3);
      return;
    }

    else if (temp > 55 && temp <= 90) {
      cout << "3 gold pieces" << endl;
      cout << "And 3 withered bones" << endl;
      add_item(player_inventory, "Gold", 3);
      add_item(player_inventory, "Bones", 3);
      return;
    }

    else {
      cout << "3 gold pieces" << endl;
      cout << "3 withered bones" << endl;
      cout << "And a rusty broad sword" << endl;
      add_item(player_inventory, "Gold", 3);
      add_item(player_inventory, "Bones", 3);
      add_item(player_inventory, "Sword", 1);
      return;
    }
  }

  case 003: {
    cout << "The Ogre dropped: " << endl;

    int temp = (rand() % 100 + 1);
    if (temp > 0 && temp <= 55) {
      cout << "1 gold piece" << endl;
      add_item(player_inventory, "Gold", 1);
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
      add_item(player_inventory, "Gold", 1);
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
      cout << "HOLY SHIT IT DROPPED ECTOPLASAM" << endl;
    }
  }
  default: {
    cout << "Unknown ID" << endl;
  }
  };
}

void LG::print_inventory() const {
  cout << "           INVENTORY:                 " << endl;
  cout << "======================================" << endl;
  for (int i = 0; i < player_inventory.size(); i++) {
    cout << player_inventory[i].name << ": " << player_inventory[i].quantity
         << endl;
  }
  cout << endl;
  cout << "======================================" << endl;
}
