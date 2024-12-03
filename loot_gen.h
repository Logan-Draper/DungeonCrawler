#pragma once
#include "enemy_stat_blocks.h"
#include "healing_item.h"
#include "player.h"
using namespace std;

class LG {
public:
  vector<ITEM_LIST::item_generic> reference_list = generic_list_1;

  void add_item(vector<ITEM_LIST::item_generic> &list, ITEM_LIST::item_generic,
                int q);

  void produce_loot(int enemy_num, Player);

  void print_inventory(vector<ITEM_LIST::item_generic> list_generics,
                       vector<HEALING_ITEM::healing> list_healing);
};
extern ITEM_LIST::item_generic bones;
extern HEALING_ITEM::healing apple;
extern HEALING_ITEM::healing potion;
