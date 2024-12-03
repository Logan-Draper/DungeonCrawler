#pragma once
#include "enemy_stat_blocks.h"
#include "loot_gen.h"

class Player : public entity {
public:
  vector<ITEM_LIST::item_generic> player_inventory_generic;
  vector<HEALING_ITEM::healing> player_inventory_healing;
  Player(string n, int a, int ar, int s, int16_t I, int CM, int MXM, int CH,
         int MXH);
  Player();
};
