// NOTE:FUTURE PROGRESS: take the bats off the board when their health drops
// below zero and end the round system once all bats health drops to zero.
#include "loot_gen.cpp"
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>
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
};

string ID_to_name(Entity NA) {

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
int attack(Entity *target, Entity attacker) {
  int damage = 0;
  if (attacker.attack >= target->armor) {
    damage = attacker.attack - target->armor;
  }
  cout << endl << "target health before: " << target->current_health << endl;
  target->current_health -= damage;
  cout << "target health after: " << target->current_health << endl;
  return damage;
};

int printELN(vector<Entity> &list) {
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

int Player_choice(Entity P1, vector<Entity> &list) {
  this_thread::sleep_for(chrono::milliseconds(1500));
  char input;
  while (true) {
    input = 'X';
    while (input != 'R' && input != 'A' && input != 'I' && input != 'S' &&
           input != 'E') {
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
      cin >> input;
    }
    cout << endl;
    if (input == 'R' && P1.current_health < P1.MAX_HEALTH) {
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
      } else {
        cout << "You Recovered " << actual_recovered << endl;
      }
    } else if (input == 'R' && P1.current_health >= P1.MAX_HEALTH) {
      cout << "You are already at Maximum Hitpoints." << endl;
    }

    if (input == 'A') {
      int enemy_selection = 0;
      cout << "Which enemy would you like to attack?" << endl;
      int num_enemy = printELN(list);
      cout << "num_enemy = " << num_enemy << endl;
      cin >> enemy_selection;
      /*
      while (list[enemy_selection].ID != 1) {
        enemy_selection++;
      }
      */
      cout << "You hit the " << ID_to_name(list[enemy_selection - 1]) << " for "
           << attack(&list[enemy_selection - 1], P1) << " damage!" << endl;
      return input;
    } else if (input == 'I') {
      system("clear");
      print_inventory();
      cout << "Input test:  ";
      cin >> input;
    }
  }
  return input;
};

void dead_check(vector<Entity> &list) {

  for (int i = 0; i < list.size(); i++) {
    if (list[i].current_health <= 0) {
      // Remove element at index i
      list.erase(list.begin() + i);
      produce_loot(list[i].ID);
    }
  }
}

int sum_health(vector<Entity> &List) {
  int sum = 0;
  for (int i = 0; i < List.size(); i++) {
    if (List[i].ID != 1) {
      sum += List[i].current_health;
    }
  }
  cout << "SUM HEALTH: " << sum << endl;
  return sum;
};

int turn_table(Entity NA, vector<Entity> &list) {
  int random = rand() % 10;
  switch (NA.ID) {

  case (1):
    // PLAYER:
    return Player_choice(NA, list);
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

  Entity bat{"BAT", 2, 0, 5, 2, 0, 0, 20, 20};
  Entity P1{"PLAYER", 99, 2, 3, 1, 50, 50, 100, 100};
  bool gamestate;
  vector<Entity> turn_order;
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
       [](const Entity &a, const Entity &b) { return a.speed > b.speed; });

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
      } else {
        turn_table(turn_order[i], turn_order);
      }
    }
    dead_check(turn_order);
  }
}
