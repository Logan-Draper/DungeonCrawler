#include "thousand_arrow.h"

TARROWS::TARROWS() : SPELL(0, "NA"), damage(0){};
TARROWS::TARROWS(int d, int m, string n) : SPELL(m, n), damage(d){};

void TARROWS::attack(vector<entity> &list, int j) const {
  for (int i = 0; i < list.size(); i++) {
    list[i].current_health -= damage;
  }
  return;
};
