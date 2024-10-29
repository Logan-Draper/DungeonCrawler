#include "item_list.cpp"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Merchant {
public:
  string name;
  string welcome_statement;
  int inventory_generic_size = rand() % 10 + 1;
  int inventory_healing_size = rand() % 3 + 1;
  vector<item_generic> inventory;
  vector<healing> healing_inventory;
  // NOTE: General Constructor
  Merchant(string n, string ws) { name = n, welcome_statement = ws; }

  Merchant(){};
  void populate_list_generic(vector<item_generic> list) {
    for (int i = 0; i < inventory_generic_size; i++) {
      inventory.push_back(generate_random_item(list));
    }
  }
  void populate_list_healing(vector<healing> list) {
    for (int i = 0; i < inventory_healing_size; i++) {
      inventory.push_back(generate_random_item(list));
    }
  }
  void print_list() {
    cout << name << "'s shop! " << endl;
    cout << welcome_statement << endl;
    cout << "==================================" << endl;
    cout << "General Items: " << endl;
    cout << endl;
    for (int i = 0; i < inventory_generic_size; i++) {
      cout << inventory[i].name << " ";
    }
    cout << endl;
    cout << "Healing Items: " << endl;
    for (int i = 0; i < inventory_healing_size; i++) {
      cout << healing_inventory[i].name
           << " healing: " << abs(healing_inventory[i].health);
    }
    cout << endl;
    cout << "==================================" << endl;
    cout << endl;
  }
};

int main() {

  Merchant logan("Logan the great", "Welcome to my shop!");
  logan.populate_list_generic(generics_list_1);
  logan.populate_list_healing(healing_list_1);
  logan.print_list();
}
