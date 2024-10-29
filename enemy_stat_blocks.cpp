#include <iostream>
using namespace std;

struct Entity {
  string name;
  int attack;
  int armor;
  int speed;
  int16_t ID;
  int current_mana;
  int MAX_MANA;
  int current_health;
  int MAX_HEALTH;
};

Entity skeleton = {"Skeleton", 2, 0, 2, 100, 0, 0, 10, 10};
Entity skeleton_brute = {"Skeleton Brawler", 6, 0, 4, 101, 0, 0, 25, 25};
Entity skeleton_horse = {"Hemrich's Horse", 2, 0, 15, 102, 0, 0, 15, 15};
Entity goblin = {"Goblin", 3, 1, 4, 200, 0, 0, 15, 15};
Entity goblin_nerd = {"Goblin Nerd", 2, 0, 0, 201, 0, 0, 10, 10};
Entity goblin_brute = {"Goblin Bruiser", 8, 1, 2, 202, 0, 0, 30, 30};
Entity wraith = {"Wraith", 1, 9999, 0, 005, 0, 0, 999, 999};
Entity necromancer = {"Nercomancer", 15, 7, 5, 30};
Entity necro_skele;
Entity lich_boss;
Entity cultist_1;

int main() { cout << ""; }
