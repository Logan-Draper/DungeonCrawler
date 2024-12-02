#pragma once
#include "enemy_stat_blocks.h"
#include "string"
using namespace std;
class RB {
public:
  struct room {
    string description;
    string inspection_text;
    int room_level;
    room(string d, string i, int rl)
        : description(d), inspection_text(i), room_level(rl){};
    room(string d) : description(d), inspection_text(" "){};
    room() : description("N/A"), inspection_text(" "){};
  };
  void search(entity &P1, int room_level);
};
