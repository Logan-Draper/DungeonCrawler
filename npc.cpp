#include "npc.h"
#include "healing_item.h"
#include "loot_gen.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// NOTE: General Constructors
MERCH ::MERCH(string n, string ws) { name = n, welcome_statement = ws; };

MERCH ::MERCH(string n, string ws, int i_size, int h_size) {
  name = n, welcome_statement = ws;
  populate_list_generic(generic_list_1, i_size, inventory);
  populate_list_healing(healing_list_1, h_size, healing_inventory);
};
// Populates the merchants inventory randomly full of generic items.
void MERCH ::populate_list_generic(vector<ITEM_LIST::item_generic> list,
                                   int num_items,
                                   vector<ITEM_LIST::item_generic> &inventory) {

  for (int i = 0; i < num_items; i++) {
    inventory.push_back(HI.generate_random_item(list));
  }
}
// Populates the merchants inventory randomly full of healing items.
void MERCH::populate_list_healing(
    vector<HEALING_ITEM::healing> list, int num_items,
    vector<HEALING_ITEM::healing> &healing_inventory) {
  for (int i = 0; i < num_items; i++) {
    healing_inventory.push_back(HI.generate_random_healing(list));
  }
}
// Updates the players gold and inventory based on whatever is bought.
void MERCH::buy(vector<ITEM_LIST::item_generic> &player_inventory) {
  LG LOOT;
  char c_selection;
  int selection;
  while (true) {
    cin >> c_selection;
    if (c_selection == 'N' || c_selection == 'n') {
      return;
    }
    selection = c_selection - '0';
    if ((size_t)selection > inventory.size() &&
        selection - inventory.size() < healing_inventory.size()) {
      // NOTE: if the players gold player_inventory[0] is less than the price of
      // item, you can't buy it.
      if (player_inventory[0].quantity <
          healing_inventory[selection - inventory.size() - 1].price) {
        cout << "You don't have the money for "
             << healing_inventory[(size_t)selection - inventory.size() - 1].name
             << " !" << endl;
      } else {
        return;
      }
    }
    if ((size_t)selection <= inventory.size() && selection > 0) {
      if (player_inventory[0].quantity < inventory[selection - 1].price) {
        cout << "You don't have the money for " << inventory[selection - 1].name
             << " !" << endl;
      } else {
        player_inventory[0].quantity -= inventory[selection - 1].price;
        LOOT.add_item(player_inventory, inventory[selection - 1], 1);
        inventory.erase(inventory.begin() + selection - 1);
      }
    }
  }
}
// Prints Merchants Inventory
void MERCH::print_list() {
  int counter = 1;
  cout << name << "'s shop! " << endl;
  cout << welcome_statement << endl;
  cout << "==================================" << endl;
  cout << "General Items: " << endl;
  cout << endl;
  for (size_t i = 0; i < inventory.size(); i++) {
    cout << "[" << counter << "]" << inventory[i].name << " " << endl;
    counter++;
  }
  cout << endl;
  cout << "Healing Items: " << endl;
  for (size_t i = 0; i < healing_inventory.size(); i++) {
    cout << "[" << counter << "]" << healing_inventory[i].name
         << " healing: " << abs(healing_inventory[i].health) << endl;
    counter++;
  }
  cout << endl;
  cout << "==================================" << endl;
  cout << endl;
  cout << "You wanna buy something or not kid?('N' to exit shop)" << endl;
}
