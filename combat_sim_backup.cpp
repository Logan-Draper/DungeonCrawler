// NOTE: Balance enemy damage, and resting health restore, currently ALWAYS
// restores you to max hp. Integrate Map and combat simulation.
#include "AllnAll.h"
#include "fireball.h"
#include "loot_gen.h"
#include "movement.h"
#include "thousand_arrow.h"
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

LG loot;
HEALING_ITEM h;
ITEM_LIST it;
Movement mg;

struct termios oldSettings;
string ID_to_name(entity NA) {

  switch (NA.ID) {

  case (1):
    // Player Name:
    return "Player";

  case (2):
    return "BAT";

  default:
    return "";
  };
}

int printELN(vector<entity> &list) {
  system("clear");
  cout << "Enemies: " << endl;
  cout << "|-----------------------------------|\n";
  int enemy_count = 1;
  for (int i = 0; i < list.size(); i++) {
    if (list[i].ID != 1) {
      cout << enemy_count << ": " << ID_to_name(list[i]) << endl;
      enemy_count++;
    }
  }
  cout << "|-----------------------------------|\n";
  return enemy_count - 1;
}

void dead_check(vector<entity> &list) {

  for (int i = 0; i < list.size(); i++) {
    if (list[i].current_health <= 0) {
      // Remove element at index i
      list.erase(list.begin() + i);
      loot.produce_loot(list[i].ID);
    }
  }
}

SPELL *FB = new Fireball(20, 20, "Fireball");
SPELL *AA = new AllnAll(10, "All for All");
SPELL *TA = new TARROWS(10, 30, "Thousand Arrows");

vector<SPELL *> spells = {FB, AA, TA};
void spell_attack(vector<SPELL *> spell_list, entity &player,
                  vector<entity> &enemy_list) {
  system("clear");
  int input;
  cout << "==============================="
       << "\n\n";
  for (int i = 0; i < spell_list.size(); i++) {
    cout << i + 1 << ": " << spell_list[i]->name
         << "    COST: " << spell_list[i]->mana_cost << endl;
  }
  cout << "==============================="
       << "\n\n";
  cout << "Which spell would you like?";
  while (input < 1 || input > spell_list.size()) {
    cin >> input;
  }
  input -= 1;
  cout << "You chose: " << spell_list[input]->name << endl;
  if (spell_list[input]->mana_cost > player.current_mana) {
    cout << "You don't have the mana to cast that! ";
    spell_attack(spell_list, player, enemy_list);
  }
  char enemy_selection;
  int num_enemy = printELN(enemy_list);
  cout << "Which enemy would you like to attack?" << endl;
  cin >> enemy_selection;
  if (enemy_selection == 27) {
    exit(0);
  } else if (enemy_selection == 'B' || enemy_selection == 'b') {
    return;
  } else if (enemy_selection - '0' > 0 &&
             enemy_selection - '0' < enemy_list.size()) {
    spell_list[input]->attack(enemy_list, enemy_selection - '0' - 1);
    cout << "YOU CAST: " << spell_list[input]->name << endl;
    player.current_mana -= spell_list[input]->mana_cost;
  }
  dead_check(enemy_list);
}

int attack(entity *target, entity attacker) {
  int damage = 0;
  if (attacker.attack >= target->armor) {
    damage = attacker.attack - target->armor;
  }
  cout << endl << "target health before: " << target->current_health << endl;
  target->current_health -= damage;
  cout << "target health after: " << target->current_health << endl;
  return damage;
};

int Player_choice(entity &P1, vector<entity> &list) {
  this_thread::sleep_for(chrono::milliseconds(1500));
  mg.setRawMode(oldSettings);
  char input;
  while (true) {
    input = 'X';
    while (input != 'R' && input != 'A' && input != 'I' && input != 'S' &&
           input != 'E' && input != 'r' && input != 'a' && input != 'i' &&
           input != 's' && input != 'e' && input != 27) {
      system("clear");
      cout << "|-----------------------------------|\n";
      cout << "YOUR TURN! WHAT WOULD YOU LIKE TO DO?\n";
      cout << "                                     \n";
      cout << "R:                              Rest \n";
      cout << "A:                            Attack \n";
      cout << "I:                         Inventory \n";
      cout << "S:                        Spell List \n";
      cout << "E:                   End Turn (pass) \n";
      cout << "                                     \n";
      cout << "                                     \n";
      cout << "Mana( " << P1.current_mana << " / " << P1.MAX_MANA << " )\n";
      cout << "Health( " << P1.current_health << " / " << P1.MAX_HEALTH
           << " )\n";
      cout << "|-----------------------------------|\n";
      input = mg.getKeyPress();
    }
    if (input == 27) {
      exit(0);
    }
    cout << endl;
    if ((input == 'R' || input == 'r') && P1.current_health < P1.MAX_HEALTH) {
      cout << "You chose to Rest!" << endl;
      this_thread::sleep_for(chrono::milliseconds(250));
      cout << ". ";
      this_thread::sleep_for(chrono::milliseconds(250));
      cout << ". ";
      this_thread::sleep_for(chrono::milliseconds(250));
      cout << ".";
      double hp_recovered = (rand() % 30);
      int actual_recovered = (P1.MAX_HEALTH * (1 + (hp_recovered / 100)));
      P1.current_health += (P1.MAX_HEALTH * (1 + (hp_recovered / 100)));
      if (P1.current_health > P1.MAX_HEALTH) {
        cout << "You Recovered up to Maximum Health!" << endl;
        P1.current_health = P1.MAX_HEALTH;
        return 0;
      } else {
        cout << "You Recovered " << actual_recovered << endl;
        return 0;
      }
    } else if ((input == 'R' || input == 'r') &&
               P1.current_health >= P1.MAX_HEALTH) {
      cout << "You are already at Maximum Hitpoints." << endl;
      this_thread::sleep_for(chrono::milliseconds(2500));
    } else if ((input == 's' || input == 'S')) {
      spell_attack(spells, P1, list);
      return 0;
    }
    if (input == 'A' || input == 'a') {
      char enemy_selection = 0;
      int num_enemy = printELN(list);
      cout << "Which enemy would you like to attack?" << endl;
      cout << "Hit: (B) to go back" << endl;
      enemy_selection = mg.getKeyPress();
      if (enemy_selection == 27) {
        exit(0);
      } else if (enemy_selection == 'B' || enemy_selection == 'b') {
        continue;
      }
      enemy_selection = enemy_selection - '0';
      cout << "You hit the " << ID_to_name(list[enemy_selection - 1]) << " for "
           << attack(&list[enemy_selection - 1], P1) << " damage!" << endl;
      return input;
    } else if (input == 'I' || input == 'i') {
      system("clear");
      loot.print_inventory();
      input = mg.getKeyPress();
      system("clear");
    } else if (input == 'E' || input == 'e') {
      return 0;
    }
  }
  return 0;
};

int sum_health(vector<entity> &List) {
  int sum = 0;
  for (int i = 0; i < List.size(); i++) {
    if (List[i].ID != 1) {
      sum += List[i].current_health;
    }
  }
  cout << "SUM HEALTH: " << sum << endl;
  return sum;
};

int turn_table(entity NA, vector<entity> &list) {
  int random = rand() % 10;
  switch (NA.ID) {

  case (1):
    // PLAYER:
    return Player_choice(NA, list);
    mg.resetMode(oldSettings);
    break;
  case (2):
    // BAT:
    if (random % 2 == 0) {
      this_thread::sleep_for(chrono::milliseconds(500));
      cout << "The bat swoops down and bites you!" << endl;
    } else {
      this_thread::sleep_for(chrono::milliseconds(500));
      cout << "OUCH it bit you!" << endl;
    }
    return NA.attack;
  default:
    cout << "Unrecognized ID" << endl;
    return 0;
  };
};

/*
void order(int counter, vector<Entity> *spd_order, Entity E1, ...) {
  va_list args;
  va_start(args, E1);

  for (int i = 0; i < counter; i++) {
    spd_order->push_back(va_arg(args, Entity));
  }
  sort(spd_order->begin(), spd_order->end(),
       [](const Entity &a, const Entity &b) { return a.speed > b.speed; });
  va_end(args);
}
*/

int main() {

  entity bat{"BAT", 2, 0, 5, 2, 0, 0, 20, 20};
  entity P1{"PLAYER", 99, 2, 3, 1, 50, 50, 100, 100};
  bool gamestate;
  vector<entity> turn_order;
  int num;
  cout << "Num bats: " << endl;
  cin >> num;
  for (int i = 0; i < num; i++) {
    turn_order.push_back(bat);
  }

  cout << "Num Players: " << endl;
  cin >> num;
  for (int i = 0; i < num; i++) {
    turn_order.push_back(P1);
  }
  sort(turn_order.begin(), turn_order.end(),
       [](const entity &a, const entity &b) { return a.speed > b.speed; });

  int turn_count = 1;
  for (int i = 0; i < turn_order.size(); i++) {
    cout << turn_order[i].speed << " ";
  }
  cout << endl;

  while (sum_health(turn_order) != 0) {
    cout << "Round: " << turn_count << endl;
    turn_count++;
    cout << "turn order size: " << turn_order.size() << endl;
    for (int i = 0; i < turn_order.size(); i++) {
      if (turn_order[i].ID != 1) {
        P1.current_health -= turn_table(turn_order[i], turn_order);
        cout << "PLAYER HEALTH: " << P1.current_health << endl;
      } else {
        Player_choice(P1, turn_order);
        dead_check(turn_order);
      }
    }
  }
}
