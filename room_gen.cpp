#include "room_gen.h"

// Defining shifts to make avaliable room logic easier
// See "directions" function for usage.
#define S (1 << 0)
#define N (1 << 1)
#define E (1 << 3)
#define W (1 << 2)

// Bunch of Constructors.
room_gen::cords::cords() : x(0), y(0){};
room_gen::cords::cords(int X, int Y) : x(X), y(Y){};
room_gen::room_gen() { cords(); };

// Populates the map with a variety of room types.
vector<vector<char>> room_gen::populate_room_types(int NPC, int ENEM, int REST,
                                                   int RANDOM, int BLESSED,
                                                   vector<vector<char>> &map) {
  system("clear");
  for (size_t i = 0; i < map.size(); i++) {
    for (size_t j = 0; j < map.size(); j++) {
      if (map[i][j] == 'X') {
        int random = rand() % 5;
        if (NPC > 0 && random == 0) {
          map[i][j] = 'N';
          NPC--;
          continue;
        }
        if (ENEM > 0 && random == 1) {
          map[i][j] = 'E';
          ENEM--;
          continue;
        }
        if (REST > 0 && random == 2) {
          map[i][j] = 'R';
          REST--;
          continue;
        }
        if (RANDOM > 0 && random == 3) {
          map[i][j] = 'M';
          RANDOM--;
          continue;
        }
        if (NPC > 0 && random == 4) {
          map[i][j] = 'B';
          BLESSED--;
        } else {
          j--;
        }
      }
    }
  }
  return map;
}
// Prints the map
void room_gen::room_print(vector<vector<char>> map) {
  system("clear");
  cout << "=================================" << endl;
  for (size_t i = 0; i < map.size(); i++) {
    for (size_t j = 0; j < map.size(); j++) {
      if (j == 0) {
        cout << "||";
      }
      cout << map[i][j] << " ";

      if (j == map.size() - 1) {
        cout << "||";
      }
    }
    cout << endl;
  }
  cout << "=================================" << endl;
  cout << "Press I for Inventory" << endl;
  cout << "Press E to Exit" << endl;
}
// Generates a map of X's that are always connected to each other.
vector<vector<char>> room_gen::room_generation(int upper_bound, int lower_bound,
                                               int map_level,
                                               vector<vector<char>> &map) {

  int room_nums = rand() % (upper_bound - lower_bound + 1) + lower_bound;

  cout << room_nums << endl;

  int map_size = (map_level * 10);
  map_size = 15;
  cout << map_size << endl;
  map.resize(map_size, vector<char>(map_size));
  // Clearing the Map:
  for (int i = 0; i < map_size; i++) {
    for (int j = 0; j < map_size; j++) {
      map[i][j] = '_';
    }
  }

  int room_start_x = map_size / 2;
  int room_start_y = map_size / 2;

  // Generates starting point for the rooms.

  int current_room_x = room_start_x;
  int current_room_y = room_start_y;
  int internal_error_counter = 0;
  for (int k = 0; k < room_nums - 1; k++) {
    if (internal_error_counter == 200) {
      break;
    }
    int room_gen_move = (rand() % 100);

    //  If when I move forward, I go out of bounds, loop over again and
    //  generate a new random direction to try.

    if (room_gen_move >= 0 && room_gen_move <= 35) {
      if (current_room_x + 1 >= map_size ||
          map[current_room_x + 1][current_room_y] == 'X') {
        k--;
        internal_error_counter++;
        continue;
      } else {
        current_room_x += 1;
        map[current_room_x][current_room_y] = 'X';
      }
    }

    else if (room_gen_move > 35 && room_gen_move <= 55) {

      if (current_room_x - 1 <= 0 ||
          map[current_room_x - 1][current_room_y] == 'X') {
        k--;
        internal_error_counter++;
        continue;
      } else {
        current_room_x -= 1;
        map[current_room_x][current_room_y] = 'X';
      }

    }

    else if (room_gen_move > 55 && room_gen_move <= 85) {

      if (current_room_y + 1 >= map_size ||
          map[current_room_x][current_room_y + 1] == 'X') {
        k--;
        continue;
        internal_error_counter++;
      } else {
        current_room_y += 1;
        map[current_room_x][current_room_y] = 'X';
      }
    }

    else if (room_gen_move > 85 && room_gen_move <= 100) {

      if (current_room_y - 1 <= 0 ||
          map[current_room_x][current_room_y - 1] == 'X') {
        k--;
        continue;
        internal_error_counter++;
      } else {
        current_room_y -= 1;
        map[current_room_x][current_room_y] = 'X';
      }
    } else {
    }
    internal_error_counter++;
  }
  map[room_start_x][room_start_y] = 'C';
  room_print(map);
  return map;
}
room_gen::cords room_gen ::find_cordinates(vector<vector<char>> map) {
  cords current_cord = {0, 0};
  for (size_t i = 0; i < map.size(); i++) {
    for (size_t j = 0; j < map.size(); j++) {
      if (map[i][j] == 'C') {
        current_cord.x = i;
        current_cord.y = j;
      }
    }
  }
  return current_cord;
};
// Returns an int_size_8 that lets us tell avaliable directions based on bit
// math.
__int8_t room_gen::directions(vector<vector<char>> map, cords current_cord) {
  size_t x = current_cord.x;
  size_t y = current_cord.y;
  __int8_t ret = 0;
  if (y + 1 < map.size() && map[x][y + 1] != '_') {
    ret |= E;
  }
  if (y - 1 >= 0) {
    if (map[x][y - 1] != '_') {
      ret |= W;
    }
  }
  if (x - 1 >= 0) {
    if (map[x - 1][y] != '_') {
      ret |= N;
    }
  }
  if (x + 1 < map.size()) {
    if (map[x + 1][y] != '_') {
      ret |= S;
    }
  }
  return ret;
}

// Gets movement input by putting terminal into RAW mode to make movement more
// clean.
int room_gen::map_direction(vector<vector<char>> map, Player P1) {
  struct termios oldsettings;
  LG loot;
  Movement mg;
  room_gen rg;
  __int8_t rooms_flag = 0b0000;
  char input;
  mg.setRawMode(oldsettings);
  rg.room_print(map);
  room_gen::cords current_cordinates = rg.find_cordinates(map);
  rooms_flag = rg.directions(map, current_cordinates);
  input = mg.getKeyPress();
  char input3;
  if (input == 'i' || input == 'I') {
    do {
      if (input == 'C') {
        cout << "emergency exit." << endl;
        exit(0);
      }

      loot.print_inventory(P1);
      cout << "(B) to go Back" << endl;
      cin >> input;
      if (input == 'b' || input == 'B') {
        break;
      }
    } while (false);
    rg.room_print(map);
  }
  if (input == 27) {
    char input2 = mg.getKeyPress();
    if (input2 == '[') {
      input3 = mg.getKeyPress();
      if (input3 == 'B' && rooms_flag & S) {
        return 2;
      }
      if (input3 == 'A' && rooms_flag & N) {
        return 3;
      }
      if (input3 == 'C' && rooms_flag & E &&
          (size_t)current_cordinates.y + 1 < map.size()) {
        return 0;
      }
      if (input3 == 'D' && rooms_flag & W && current_cordinates.y - 1 >= 0) {
        return 1;
      }
    }
  } else if (input == 'E' || input == 'e') {
    cout << "\n\nexiting..";
    exit(0);
  }
  mg.resetMode(oldsettings);
  return -1;
};
// Checks if every room on the map has been visited, exit condition for the
// game.
bool room_gen::map_clear(vector<vector<char>> map) {
  bool clear = false;
  for (size_t i = 0; i < map.size(); i++) {
    for (size_t j = 0; j < map.size(); j++) {
      if (map[i][j] != 'C' && map[i][j] != 'O' && map[i][j] != '_') {
        clear = true;
      }
    }
  }

  return clear;
}
// Makes the actual movement on the map.
void room_gen ::traverse_map(vector<vector<char>> &map, int input) {
  LG loot;
  cords current_cordinates = find_cordinates(map);
  if (input == 2) {
    map[current_cordinates.x][current_cordinates.y] = 'O';
    map[current_cordinates.x + 1][current_cordinates.y] = 'C';
    return;
  }
  if (input == 3) {
    map[current_cordinates.x][current_cordinates.y] = 'O';
    map[current_cordinates.x - 1][current_cordinates.y] = 'C';
    return;
  }
  if (input == 0) {
    map[current_cordinates.x][current_cordinates.y] = 'O';
    map[current_cordinates.x][current_cordinates.y + 1] = 'C';
    return;
  }
  if (input == 1) {
    map[current_cordinates.x][current_cordinates.y] = 'O';
    map[current_cordinates.x][current_cordinates.y - 1] = 'C';
    return;
  } else {
    return;
  }
};
