#include "AllnAll.h"

AllnAll::AllnAll() : SPELL(0, "NA"), costNdamage(0){};
AllnAll::AllnAll(int cost, string n) : SPELL(cost, n), costNdamage(cost){};

void AllnAll::attack(vector<entity> &list, int index) const {
  if (index >= 0 && index < list.size()) {
    list[index].current_health -= costNdamage;
  }
};
