#pragma once
#include "healing_item.h"
using namespace std;

class LG {
public:
  vector<ITEM_LIST::item_generic> reference_list = generic_list_1;

  void add_item(vector<ITEM_LIST::item_generic> &list, string n, int q);

  void produce_loot(int enemy_num);
  void print_inventory() const;
};
extern vector<ITEM_LIST::item_generic> player_inventory;
extern ITEM_LIST::item_generic bones;
extern HEALING_ITEM::healing apple;
extern HEALING_ITEM::healing potion;
