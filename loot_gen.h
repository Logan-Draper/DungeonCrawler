#pragma once
#include "enemy_stat_blocks.h"
#include "healing_item.h"
#include "item_list.h"
#include "player.h"
using namespace std;

class LG {
public:
  vector<ITEM_LIST::item_generic> reference_list = generic_list_1;
  vector<HEALING_ITEM::healing> reference_healing_list = healing_list_1;

  void add_item(vector<ITEM_LIST::item_generic> &list, ITEM_LIST::item_generic,
                int q);

  void add_item_healing(vector<HEALING_ITEM::healing> &list,
                        HEALING_ITEM::healing item, int q);

  void produce_loot(int enemy_num, Player &P1);

  void print_inventory(Player &P1);
  void selected_item(ITEM_LIST::item_generic &item);
  void selected_healing_item(Player &P1, HEALING_ITEM::healing &item);
};
