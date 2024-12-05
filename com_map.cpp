
using namespace std;
#include "com_map.h"

COM_MAP::COM_MAP(){};

// Based on the coordinate specified, and direction we want to travel, we return
// what type of room it is.
char COM_MAP::room_type(vector<vector<char>> map, int direction,
                        room_gen::cords cc) {

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
// Simluates combat by generating enemies, is called whenever an E room is hit.
void COM_MAP::combat_simulation(Player &P1) {
  COM_WEIGHT CW(0.15); // 0.15 is the epsilon of stat generation. 15% higher or
                       // lower than the players stats.
  LVLUP LV;
  COM_SIM CS;
  vector<entity> room_enemies;
  int turn_count = 1;
  // Based on the players stats, generate a challenging amount of enemies based
  // on an epsilon value.
  CW.generate_enemies(room_enemies, P1, enemy_list_1);
  room_enemies.push_back(P1);
  // Lambda Function that sorts enemies based on their speed stat so faster
  // things go first.
  sort(room_enemies.begin(), room_enemies.end(),
       [](const entity &a, const entity &b) { return a.speed > b.speed; });
  while (CS.sum_health(room_enemies) > 0) {
    cout << "Round: " << turn_count << endl;
    turn_count++;
    for (size_t i = 0; i < room_enemies.size(); i++) {
      if (room_enemies[i].ID != 0) {
        P1.current_health -= CS.turn_table(room_enemies[i], room_enemies, P1);
        if (P1.current_health <= 0) {
          cout << "oops! You died! Thanks for playing! " << endl;
          exit(0);
        }
      } else {
        // Lets the player have their move
        CS.Player_choice(P1, room_enemies);
        // Checks if any enemies health are below zero, if it is, remove from
        // list.
        CS.dead_check(room_enemies, P1);
      }
    }
  }
  cout << "Nice! You defeated all the enemies! " << endl;
  LV.level_up_player(P1);
};
// Based on the room, call aa specific function to do something.
void COM_MAP::room_action(char room_type, Player &P1) {
  MERCH Logan("Logan", "Welcome to my Shop!", 2, 2);
  BLESS Bless;
  RB roob;
  REST RT;
  int random_room = rand() % room_level_1.size();
  switch (room_type) {
  case ('E'):
    combat_simulation(P1);
    break;
  case ('R'):
    RT.resting_room(P1);
    break;
  case ('N'):
    Logan.buy(P1.player_inventory_generic);
    break;
  case ('M'):
    roob.print_room(P1, room_level_1[random_room]);
    break;
  case ('B'):
    Bless.blessup(P1);
    break;
  case ('O'):
    break;
  default:
    cout << "DEFAULT " << endl;
  };
}
// Sets up and plays the game.
void COM_MAP::driver() {
  system("clear");
  room_gen::cords cc;
  room_gen RG;
  LG LOOT;
  Player P1 = {"Player", 200, 10, 999, 000, 50, 50, 100, 100};
  LOOT.add_item(P1.player_inventory_generic, gold, 50);
  LOOT.add_item_healing(P1.player_inventory_healing, steak, 3);
  long seed;
  cout << WELCOME << endl;
  cout << TITLE << endl << endl;
  vector<vector<char>> map;
  cout << "                        ENTER A SEED:";
  cin >> seed;
  srand(seed);
  RG.room_generation(2000, 2000, 2, map);
  RG.populate_room_types(3, 20, 4, 8, 3, map);
  cout << "\n\n";
  // Keep traversing the map until the player either dies or defeats all
  // enemies and explores all rooms.
  bool cleared = true;
  while (cleared) {
    int direction = RG.map_direction(map, P1);
    cc = RG.find_cordinates(map);
    char type = room_type(map, direction, cc);
    room_action(type, P1);
    RG.traverse_map(map, direction);
    cleared = RG.map_clear(map);
  }
};
int main() {
  COM_MAP CM;
  CM.driver();
}
