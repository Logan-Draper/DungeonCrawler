#pragma once
#include "spells.h"

class TARROWS : public SPELL {
public:
  int damage;
  TARROWS();
  TARROWS(int d, int m, string n);
  void attack(vector<entity> &, int) const override;
};
