#include <iostream>
#include <vector>
using namespace std;

struct Entity {
  string name;
  int attack;
  int armor;
  int speed;
  int8_t ID;
  int current_mana;
  int MAX_MANA;
  int current_health;
  int MAX_HEALTH;
  int weighting;
};

int sum_stats(Entity E) {
  return E.MAX_HEALTH + E.MAX_MANA + E.armor + E.speed + E.attack;
}

int sum_stats(vector<Entity> E) {
  int sum;
  for (int i = 0; i < E.size(); i++) {
    sum +=
        E[i].MAX_HEALTH + E[i].MAX_MANA + E[i].armor + E[i].speed + E[i].attack;
  }
  return sum;
}

const float EPSILON = 0.15;
int calculate_epsilon(Entity player) {

  int player_stat_sum = sum_stats(player);

  if (rand() % 2 == 0) {
    return player_stat_sum * (1 + EPSILON);
  } else {
    return player_stat_sum * (1 - EPSILON);
  }

  return 0;
}

Entity Goblin = {"GOBLIN", 5, 2, 3, 001, 0, 0, 10, 10, 9};
Entity Boss_Goblin = {"BOSS GOBLIN", 10, 5, 10, 002, 0, 0, 25, 25, 1};
Entity Bat = {"BAT", 3, 0, 5, 003, 0, 0, 10, 10, 9};
Entity GOD = {"GOD", 999, 999, 999, 004, 999, 999, 999, 999, 9};

void generate_enemies(vector<Entity> &E, Entity Player) {
  int counter;
  int stat_points = calculate_epsilon(Player);
  cout << stat_points << endl;
  while (stat_points > 0) {
    counter++;
    if (counter == 200) {
      break;
    }
    int random = rand() % 4;
    int weighted_random = rand() % 10;
    if (random == 0 && (stat_points - sum_stats(GOD)) > 0 &&
        weighted_random - GOD.weighting >= 0) {
      E.push_back(GOD);
      stat_points -= sum_stats(GOD);
      continue;
    }
    if (random == 1 && (stat_points - sum_stats(Boss_Goblin)) > 0 &&
        weighted_random - Boss_Goblin.weighting >= 0) {
      E.push_back(Boss_Goblin);
      stat_points -= sum_stats(Boss_Goblin);
      continue;
    }
    if (random == 2 && (stat_points - sum_stats(Goblin)) > 0 &&
        weighted_random - Goblin.weighting >= 0) {
      E.push_back(Goblin);
      stat_points -= sum_stats(Goblin);
      continue;
    }
    if (random == 3 && (stat_points - sum_stats(Bat)) > 0 &&
        weighted_random - Bat.weighting >= 0) {
      E.push_back(Bat);
      stat_points -= sum_stats(Bat);
      continue;
    }
  }
}

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
