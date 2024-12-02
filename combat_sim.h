#include "AllnAll.h"
#include "combat_weight.h"
#include "enemy_stat_blocks.h"
#include "fireball.h"
#include "level_up.h"
#include "loot_gen.h"
#include "movement.h"
#include "npc.h"
#include "player.h"
#include "thousand_arrow.h"
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

class COM_SIM {
public:
  COM_SIM();
  LG loot;
  HEALING_ITEM HI;
  ITEM_LIST IT;
  Movement mg;
  SPELL *FB = new Fireball(20, 20, "Fireball");
  SPELL *AA = new AllnAll(100, "All for All");
  SPELL *TA = new TARROWS(10, 30, "Thousand Arrows");
  vector<SPELL *> spells = {FB, AA, TA};
  struct termios oldSettings;

  string ID_to_name(entity NA);

  int printELN(vector<entity> &list);

  void dead_check(vector<entity> &list);

  void spell_attack(vector<SPELL *> spell_list, entity &player,
                    vector<entity> &enemy_list);

  int attack(entity *target, entity attacker);

  int Player_choice(entity &P1, vector<entity> &list);

  int sum_health(vector<entity> &list);

  int turn_table(entity NA, vector<entity> &list);
};
