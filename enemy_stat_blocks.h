#include <iostream>
#include <string>
#include <vector>
#pragma once
using namespace std;

class entity {
public:
  string name;
  int attack;
  int armor;
  int speed;
  int16_t ID;
  int current_mana;
  int MAX_MANA;
  int current_health;
  int MAX_HEALTH;
  int weighting;
};

extern vector<entity> enemy_list_1;
