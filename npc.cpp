#include "npc.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// NOTE: General Constructor
MERCH ::MERCH(string n, string ws) { name = n, welcome_statement = ws; };
/*
MERCH ::MERCH(string n, string ws, int i_size, int h_size) {
  name = n, welcome_statement = ws, inventory.resize(i_size),
  healing_inventory.resize(h_size);
};
*/
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
  }
}
void MERCH::print_list() {
  cout << name << "'s shop! " << endl;
  cout << welcome_statement << endl;
  cout << "==================================" << endl;
  cout << "General Items: " << endl;
  cout << endl;
  for (int i = 0; i < inventory.size(); i++) {
    cout << inventory[i].name << " " << endl;
  }
  cout << endl;
  cout << "Healing Items: " << endl;
  for (int i = 0; i < healing_inventory.size(); i++) {
    cout << healing_inventory[i].name
         << " healing: " << abs(healing_inventory[i].health) << endl;
  }
  cout << endl;
  cout << "==================================" << endl;
  cout << endl;
}

int main() {

  MERCH logan("Logan the great", "Welcome to my shop!");
  logan.populate_list_generic(generic_list_1, 20, logan.inventory);
  logan.populate_list_healing(healing_list_1, 1, logan.healing_inventory);
  logan.print_list();
}
