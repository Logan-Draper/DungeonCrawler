#include "combat_weight.h"

// General Constructors
COM_WEIGHT::COM_WEIGHT() : EPSILON(.10){};
COM_WEIGHT::COM_WEIGHT(float e) : EPSILON(e){};

// Used to sum the player and enemies stats.
int COM_WEIGHT::sum_stats(entity E) {
  return E.MAX_HEALTH + E.MAX_MANA + E.armor + E.speed + E.attack;
}
// Overload to sum an entire list of entities.
int COM_WEIGHT::sum_stats(vector<entity> E) {
  int sum;
  for (size_t i = 0; i < E.size(); i++) {
    sum += sum_stats(E[i]);
  }
  return sum;
}
// Randomly generates a +x% or a -x% when calculating difficulty
int COM_WEIGHT::calculate_epsilon(entity player) {

  int player_stat_sum = sum_stats(player);

  if (rand() % 2 == 0) {
    return player_stat_sum * (1 + EPSILON);
  } else {
    return player_stat_sum * (1 - EPSILON);
  }

  return 0;
}
// Generates enemies from a reference list until the stat points drops below
// zero.
void COM_WEIGHT::generate_enemies(vector<entity> &E, entity Player,
                                  vector<entity> reference_list) {
  int counter = 0;
  int stat_points = calculate_epsilon(Player);
  while (stat_points >= 0 && counter < 10) {
    counter++;

    int random_enemy = rand() % reference_list.size();
    int random_enemy_sum = sum_stats(reference_list[random_enemy]);

    if ((stat_points - random_enemy_sum) > 0) {
      E.push_back(reference_list[random_enemy]);
      stat_points -= random_enemy_sum;
      continue;
    } else {
      break;
    }
  }
}
