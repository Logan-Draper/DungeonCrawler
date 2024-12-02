// NOTE: THINGS TO WORK ON: Flesh out random, NPC, blessing and rest rooms. Also
// figure out why sometimes given a seed the map generator does nothing.

using namespace std;
#include "combat_sim.h"
#include "room_gen.h"

char room_type(vector<vector<char>> map, int direction, room_gen::cords cc) {

  switch (direction) {
  // North Logic?
  case (0):
    return map[cc.x][cc.y + 1];

  // South?
  case (1):
    return map[cc.x][cc.y - 1];

  // East?
  case (2):
    return map[cc.x + 1][cc.y];

  // West?
  case (3):
    return map[cc.x - 1][cc.y];

  default:
    return '-';
  };
}

void combat_simulation(entity &P1) {
  COM_WEIGHT CW(0.15);
  LVLUP LV;
  COM_SIM CS;
  vector<entity> room_enemies;
  int turn_count = 1;
  CW.generate_enemies(room_enemies, P1, enemy_list_1);
  room_enemies.push_back(P1);
  //  cout << "got past sum_stats call." << endl;
  sort(room_enemies.begin(), room_enemies.end(),
       [](const entity &a, const entity &b) { return a.speed > b.speed; });
  // cout << "got past sort." << endl;
  while (CS.sum_health(room_enemies) > 0) {
    cout << "Round: " << turn_count << endl;
    turn_count++;
    for (int i = 0; i < room_enemies.size(); i++) {
      if (room_enemies[i].ID != 0) {
        P1.current_health -= CS.turn_table(room_enemies[i], room_enemies);
        //  this_thread::sleep_for(chrono::milliseconds(500));
        if (P1.current_health <= 0) {
          cout << "oops! You died! Thanks for playing! " << endl;
          exit(0);
        }
      } else {
        CS.Player_choice(P1, room_enemies);
        CS.dead_check(room_enemies);
      }
    }
  }
  cout << "Nice! You defeated all the enemies! " << endl;
  // NOTE: add random exclamation phrase.
  LV.level_up_player(P1);
};

void room_action(char room_type, entity &P1) {
  MERCH Logan("Logan", "Welcome to my Shop!", 2, 2);
  switch (room_type) {
  case ('E'):
    combat_simulation(P1);
    break;
  case ('R'):
    cout << "REST PLACEHOLDER" << endl;
    break;
  case ('N'):
    cout << "NPC" << endl;
    Logan.buy(player_inventory);
    this_thread::sleep_for(chrono::milliseconds(750));
    break;
  case ('M'):
    cout << "RANDOM PLACE HOLDER" << endl;
    this_thread::sleep_for(chrono::milliseconds(750));
    break;
  case ('B'):
    cout << "BLESSING PLACE HOLDER" << endl;
    this_thread::sleep_for(chrono::milliseconds(750));
    break;
  case ('O'):
    cout << "O TYPE" << endl;
    break;
  default:
    cout << "DEFAULT " << endl;
  };
}
void driver() {
  room_gen::cords cc;
  room_gen RG;
  entity P1 = {"Player", 200, 10, 10, 000, 50, 50, 100, 100};
  long seed;
  vector<vector<char>> map;
  cout << "Enter seed: " << endl;
  cin >> seed;
  srand(seed);
  LG loot;
  RG.room_generation(25, 15, 2, map);
  RG.populate_room_types(2, 10, 3, 6, 1, map);
  cout << "\n\n";
  while (true) {
    int direction = RG.map_direction(map);
    cc = RG.find_cordinates(map);
    char type = room_type(map, direction, cc);
    room_action(type, P1);
    RG.traverse_map(map, direction);
  }
};

int main() { driver(); }
