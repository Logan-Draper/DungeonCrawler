#include "fireball.h"

// NOTE: Default Constructor
Fireball::Fireball() : SPELL(0, "NA") { damage = 0; };

// NOTE:General Constructor
Fireball::Fireball(int d, int m, string n) : damage(d), SPELL(m, n){};

void Fireball::attack(vector<entity> &list, int index) const {
  if (index <= list.size() - 1 && list[index + 1].name != "") {
    list[index + 1].current_health -= Fireball::damage;
  }
  if (index != 0 && list[index - 1].name != "") {
    list[index - 1].current_health -= damage;
  }
  list[index].current_health -= damage;
};
