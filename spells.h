#pragma once

#include "enemy_stat_blocks.h"
#include <vector>
using namespace std;

class SPELL {
public:
  int mana_cost;
  string name;
  SPELL(int m, string n);
  virtual ~SPELL(){};
  virtual void attack(vector<entity> &, int) const = 0;
};
