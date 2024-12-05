#include "AllnAll.h"

// Constructor Implimentation
AllnAll::AllnAll() : SPELL(0, "NA"), costNdamage(0){};
AllnAll::AllnAll(int cost, string n) : SPELL(cost, n), costNdamage(cost){};

// Hits all enemies in the initiative list. Abstract Class Implimentation.
void AllnAll::attack(vector<entity> &list, int index) const {

  if ((size_t)index >= 0 && (size_t)index < list.size()) {
    list[index].current_health -= costNdamage;
  }
};
