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
  entity(string n, int a, int ar, int s, int16_t I, int CM, int MXM, int CH,
         int MXH)
      : name(n), attack(a), armor(ar), speed(s), ID(I), current_mana(CM),
        MAX_MANA(MXM), current_health(CH), MAX_HEALTH(MXH){};
  entity() : name("NA"){};
};
extern vector<entity> enemy_list_1;
