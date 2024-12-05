#pragma once
#include "combat_sim.h"
#include "loot_gen.h"
#include "player.h"
#include "string"
using namespace std;
class RB {
public:
  RB();
  struct room {
    string description;
    string inspection_text;
    int room_level;
    room(string d, string i, int rl)
        : description(d), inspection_text(i), room_level(rl){};
    room(string d) : description(d), inspection_text(" "){};
    room() : description("N/A"), inspection_text(" "){};
  };
  char search(Player &P1, room CR);
  char print_room(Player &P1, room CR);
};
extern vector<RB::room> room_level_1;
