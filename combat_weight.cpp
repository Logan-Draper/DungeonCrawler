#include "combat_weight.h"

COM_WEIGHT::COM_WEIGHT() : EPSILON(.10){};
COM_WEIGHT::COM_WEIGHT(float e) : EPSILON(e){};

int COM_WEIGHT::sum_stats(entity E) {
  return E.MAX_HEALTH + E.MAX_MANA + E.armor + E.speed + E.attack;
}

int COM_WEIGHT::sum_stats(vector<entity> E) {
  int sum;
  for (int i = 0; i < E.size(); i++) {
    sum += sum_stats(E[i]);
  }
  return sum;
}

int COM_WEIGHT::calculate_epsilon(entity player) {

  int player_stat_sum = sum_stats(player);

  if (rand() % 2 == 0) {
    return player_stat_sum * (1 + EPSILON);
  } else {
    return player_stat_sum * (1 - EPSILON);
  }

  return 0;
}

void COM_WEIGHT::generate_enemies(vector<entity> &E, entity Player,
                                  vector<entity> reference_list) {
  int counter = 0;
  int stat_points = calculate_epsilon(Player);
  cout << "made it to enemy_generation." << endl;
  while (stat_points >= 0 && counter < 10) {
    counter++;

    int random_enemy = rand() % reference_list.size();
    int random_enemy_sum = sum_stats(reference_list[random_enemy]);

    if ((stat_points - random_enemy_sum) > 0) {
      cout << "made it to the: " << counter + 1 << " pushback" << endl;
      E.push_back(reference_list[random_enemy]);
      cout << "made it AFTER the: " << counter + 1 << " pushback" << endl;
      stat_points -= random_enemy_sum;
      continue;
    } else {
      break;
    }
  }
  cout << "exited enemy_generation." << endl;
}

/*
void print(vector<Entity> E) {
  for (int i = 0; i < E.size(); i++) {
    cout << E[i].name << " ";
  }
  cout << endl;
}


int main() {

  vector<Entity> list;
  int input;
  cout << "Player Stat Controller: " << endl;
  cin >> input;
  Entity Player = {"Player", input, 10, 10, 000, 50, 50, 100, 100};
  generate_enemies(list, Player);
  print(list);
}
*/
