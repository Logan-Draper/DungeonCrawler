#include "combat_sim.h"
using namespace std;

// General Constructor
COM_SIM::COM_SIM(){};

// Prints out name based on ID of enemy
string COM_SIM::ID_to_name(entity NA) { return NA.name; }

// Prints the list of enemys avaliable to hit
int COM_SIM::printELN(vector<entity> &list) {
  system("clear");
  cout << "Enemies: " << endl;
  cout << "|-----------------------------------|\n";
  int enemy_count = 1;
  for (size_t i = 0; i < list.size(); i++) {
    // 000 is the player, we don't want to print their name.
    if (list[i].ID != 000) {
      cout << "[" << enemy_count << "] " << list[i].name << endl;
      enemy_count++;
    }
  }
  cout << "|-----------------------------------|\n";
  return enemy_count - 1;
}

void COM_SIM::dead_check(vector<entity> &list, Player P1) {

  for (size_t i = 0; i < list.size(); i++) {
    if (list[i].current_health <= 0) {
      loot.produce_loot(list[i].ID, P1);
      list.erase(list.begin() + i);
    }
  }
}
// Prints a spell list and handles the players selection of spells.
void COM_SIM::spell_attack(vector<SPELL *> spell_list, Player &player,
                           vector<entity> &enemy_list) {
  system("clear");
  string c_input = "99999";
  cout << "==============================="
       << "\n\n";
  for (size_t i = 0; i < spell_list.size(); i++) {
    cout << i + 1 << ": " << spell_list[i]->name
         << "    COST: " << spell_list[i]->mana_cost << endl;
  }
  cout << "==============================="
       << "\n\n";
  cout << "Which spell would you like?: " << endl;
  cout << "(B) to go back" << endl;
  while (stoi(c_input) < 1 || (size_t)stoi(c_input) > spell_list.size()) {
    c_input = mg.getKeyPress();
    if (c_input == "B" || c_input == "b") {
      return;
    }
  }
  int input = stoi(c_input);
  cout << "input: " << input << endl;
  input -= 1;
  cout << "You chose: " << spell_list[input]->name << endl;
  // Error Handling if the player doesn't have sufficient mana
  if (spell_list[input]->mana_cost > player.current_mana) {
    cout << "You don't have the mana to cast that! " << endl;
    spell_attack(spell_list, player, enemy_list);
    return;
  }
  char enemy_selection;
  printELN(enemy_list);
  // Enemy Selection
  cout << "Which enemy would you like to attack?" << endl;
  cin >> enemy_selection;
  if (enemy_selection == 27) {
    exit(0);
  } else if (enemy_selection - '0' > 0 &&
             (size_t)enemy_selection - '0' < enemy_list.size()) {
    spell_list[input]->attack(enemy_list, enemy_selection - '0' - 1);
    cout << "YOU CAST: " << spell_list[input]->name << endl;
    player.current_mana -= spell_list[input]->mana_cost;
  }
  dead_check(enemy_list, player);
}

// Based on targets armor and attackers attack stat, return difference.
int COM_SIM::attack(entity *target, entity attacker) {
  int damage = 0;
  if (attacker.attack >= target->armor) {
    damage = attacker.attack - target->armor;
  }
  target->current_health -= damage;
  return damage;
};
// Handles the players variety of choices.
int COM_SIM::Player_choice(Player &P1, vector<entity> &list) {
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
      cout << "(esc) to exit game" << endl;
      input = mg.getKeyPress();
    }
    // Exit handling
    if (input == 27) {
      exit(0);
    }
    // Rest logic
    cout << endl;
    if ((input == 'R' || input == 'r') && P1.current_health < P1.MAX_HEALTH) {
      cout << "You chose to Rest!" << endl;
      double hp_recovered = (rand() % 200);
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
    }
    // Spell Attack logic
    else if ((input == 's' || input == 'S')) {
      spell_attack(spells, P1, list);
      return 0;
    }
    // Attack Logic
    if (input == 'A' || input == 'a') {
      char enemy_selection = 0;
      printELN(list);
      cout << "Which enemy would you like to attack?" << endl;
      cout << "Hit: (B) to go back" << endl;
      enemy_selection = mg.getKeyPress();
      if (enemy_selection == 27) {
        exit(0);

      } else if (enemy_selection == 'B' || enemy_selection == 'b') {
        continue;
      }
      enemy_selection = enemy_selection - '0';
      cout << "You hit the " << list[enemy_selection].name << " for "
           << attack(&list[enemy_selection], P1) << " damage!" << endl;
      return input;
    } // Inventory Logic
    else if (input == 'I' || input == 'i') {
      system("clear");
      loot.print_inventory(P1);
      input = mg.getKeyPress();
      system("clear");
      // Pass / End Turn logic
    } else if (input == 'E' || input == 'e') {
      return 0;
    }
  }
  return 0;
};
// Sums the health of every enemy excluding the player.
int COM_SIM::sum_health(vector<entity> &List) {
  int sum = 0;
  for (size_t i = 0; i < List.size(); i++) {
    // Player is 000, exclude this in HP calculation.
    if (List[i].ID != 000) {
      sum += List[i].current_health;
    }
  }
  return sum;
};
// Handles the order of turns between the player and the enemy
int COM_SIM::turn_table(entity NA, vector<entity> &list, Player P1) {
  if (NA.ID == 000) {
    int temp = Player_choice(P1, list);
    mg.resetMode(oldSettings);
    return temp;
  } else {
    cout << "The " << NA.name << " attacked you !" << endl;
    this_thread::sleep_for(chrono::milliseconds(750));
    return NA.attack;
  }
};
