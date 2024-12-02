#include "healing_item.h"
#include <string>
using namespace std;

class MERCH {
public:
  ITEM_LIST IL;
  HEALING_ITEM HI;

  string name;
  string welcome_statement;
  int inventory_generic_size;
  int inventory_healing_size;
  vector<ITEM_LIST::item_generic> inventory;
  vector<HEALING_ITEM::healing> healing_inventory;

  MERCH(string n, string ws);
  MERCH(string n, string ws, int i_size, int h_size);
  void populate_list_generic(vector<ITEM_LIST::item_generic> list, int n,
                             vector<ITEM_LIST::item_generic> &player_inventory);
  void populate_list_healing(
      vector<HEALING_ITEM::healing> list, int n,
      vector<HEALING_ITEM::healing> &player_inventory_healing);
  void print_list();
  void buy(vector<ITEM_LIST::item_generic> player_inventory);
};
