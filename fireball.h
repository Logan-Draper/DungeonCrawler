#include "spells.h"
using namespace std;

class Fireball : public SPELL {
public:
  int damage;
  Fireball();
  Fireball(int, int, string);
  void attack(vector<entity> &, int) const override;
};
