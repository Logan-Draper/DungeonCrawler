#include "spells.h"

class AllnAll : public SPELL {
public:
  int costNdamage;

  AllnAll();
  AllnAll(int h, string n);
  void attack(vector<entity> &, int) const override;
};
