#include "npc.h"
#include "healing_item.h"
#include "loot_gen.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// NOTE: General Constructor
MERCH ::MERCH(string n, string ws) { name = n, welcome_statement = ws; };

MERCH ::MERCH(string n, string ws, int i_size, int h_size) {
  name = n, welcome_statement = ws;
  populate_list_generic(generic_list_1, i_size, inventory);
  populate_list_healing(healing_list_1, h_size, healing_inventory);
};
void MERCH ::populate_list_generic(vector<ITEM_LIST::item_generic> list,
                                   int num_items,
                                   vector<ITEM_LIST::item_generic> &inventory) {

  for (int i = 0; i < num_items; i++) {
    inventory.push_back(HI.generate_random_item(list));
  }
}
void MERCH::populate_list_healing(
    vector<HEALING_ITEM::healing> list, int num_items,
    vector<HEALING_ITEM::healing> &healing_inventory) {
  for (int i = 0; i < num_items; i++) {
    healing_inventory.push_back(HI.generate_random_healing(list));
    cout << "looped: " << i << endl;
  }
}
void MERCH::buy(vector<ITEM_LIST::item_generic> player_inventory) {
  int selection;
  while (true) {
    print_list();
    do {
      cin >> selection;
      if (selection == 'N' || selection == 'n') {
        return;
      }
    } while (selection < 0 ||
             selection > inventory.size() + healing_inventory.size());
    if (selection > inventory.size() &&
        selection - inventory.size() < healing_inventory.size()) {
      // NOTE: if the players gold player_inventory[0] is less than the price of
      // item, you can't buy it.

      if (player_inventory[0].quantity <
          healing_inventory[selection - inventory.size() - 1].price) {
        cout << "You don't have the money for "
             << healing_inventory[selection - inventory.size() - 1].name << " !"
             << endl;
        continue;
      } else {
        cout << "we would've pushed back a healing item.. TBD" << endl;
        return;
      }
    }
    if (selection < inventory.size() && selection > 0) {
      cout << "made it to inventory logic" << endl;
      if (player_inventory[0].quantity < inventory[selection - 1].price) {
        cout << "You don't have the money for " << inventory[selection - 1].name
             << " !" << endl;
        continue;
      } else {
        cout << "made it to the else of inventory logic " << endl;
        player_inventory[0].quantity -= inventory[selection - 1].price;
        player_inventory.push_back(inventory[selection - 1]);
        inventory.erase(inventory.begin() + selection);
      }
    }
  }
}

void MERCH::print_list() {

  int counter = 1;
  cout << name << "'s shop! " << endl;
  cout << welcome_statement << endl;
  cout << "==================================" << endl;
  cout << "General Items: " << endl;
  cout << endl;
  for (int i = 0; i < inventory.size(); i++) {
    cout << "[" << counter << "]" << inventory[i].name << " " << endl;
    counter++;
  }
  cout << endl;
  cout << "Healing Items: " << endl;
  for (int i = 0; i < healing_inventory.size(); i++) {
    cout << "[" << counter << "]" << healing_inventory[i].name
         << " healing: " << abs(healing_inventory[i].health) << endl;
    counter++;
  }
  cout << endl;
  cout << "==================================" << endl;
  cout << endl;
  cout << "You wanna buy something or not kid?('N' to exit shop)" << endl;
}
/*
int main() {

MERCH logan("Logan the great", "Welcome to my shop!");
logan.populate_list_generic(generic_list_1, 20, logan.inventory);
logan.populate_list_healing(healing_list_1, 1, logan.healing_inventory);
logan.print_list();
}
*/
