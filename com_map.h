#pragma once
#include "combat_sim.h"
#include "room_gen.h"
using namespace std;

class COM_MAP {
public:
  COM_MAP();

  char room_type(vector<vector<char>> map, int direction, room_gen::cords cc);
  void combat_simulation(Player &P1);
  void room_action(char room_type, Player &P1);
  void driver();
};
