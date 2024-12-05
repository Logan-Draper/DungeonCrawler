#include "fireball.h"

// NOTE: Default Constructor
Fireball::Fireball() : SPELL(0, "NA") { damage = 0; };

// NOTE:General Constructor
Fireball::Fireball(int d, int m, string n) : damage(d), SPELL(m, n){};

// Hits the enemy targeted, as well as the enemy one above and one below the
// target if possible.
void Fireball::attack(vector<entity> &list, int index) const {
  if ((size_t)index <= list.size() - 1 && list[index + 1].name != "") {
    list[index + 1].current_health -= Fireball::damage;
  }
  if ((size_t)index != 0 && list[index - 1].name != "") {
    list[index - 1].current_health -= damage;
  }
  list[index].current_health -= damage;
};
