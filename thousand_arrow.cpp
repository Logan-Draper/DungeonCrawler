#include "thousand_arrow.h"

// General Constructors.
TARROWS::TARROWS() : SPELL(0, "NA"), damage(0){};
TARROWS::TARROWS(int d, int m, string n) : SPELL(m, n), damage(d){};

// Attack Virtual Class Implimentation.
void TARROWS::attack(vector<entity> &list, int j) const {
  for (size_t i = 0; i < list.size(); i++) {
    list[i].current_health -= damage;
  }
  return;
};
