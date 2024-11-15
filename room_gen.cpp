#include "room_gen.h"

#define S (1 << 0)
#define N (1 << 1)
#define E (1 << 3)
#define W (1 << 2)

room_gen::cords::cords() : x(0), y(0){};
room_gen::cords::cords(int X, int Y) : x(X), y(Y){};
room_gen::room_gen() { cords(); };

vector<vector<char>> room_gen::populate_room_types(int NPC, int ENEM, int REST,
                                                   int RANDOM, int BLESSED,
                                                   vector<vector<char>> &map) {
  system("clear");
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map.size(); j++) {
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
          //          cout << "bumped limiter" << endl;
          j--;
        }
      }
    }
  }
  return map;
}
void room_gen::room_print(vector<vector<char>> map) {
  system("clear");
  cout << "=================================" << endl;
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map.size(); j++) {
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
}

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

  // int room_start_x = 0;
  // int room_start_y = 0;

  // Generates starting point for the rooms.
  map[room_start_x][room_start_y] = 'C';

  int current_room_x = room_start_x;
  int current_room_y = room_start_y;
  int internal_error_counter = 0;
  for (int k = 0; k < room_nums - 1; k++) {
    if (internal_error_counter == 50) {
      break;
    }
    cout << "K :" << k << endl;
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
      cout << "We should not be here." << endl;
    }
    internal_error_counter++;
  }
  room_print(map);
  return map;
}
room_gen::cords room_gen ::find_cordinates(vector<vector<char>> map) {
  cords current_cord = {0, 0};
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map.size(); j++) {
      if (map[i][j] == 'C') {
        current_cord.x = i;
        current_cord.y = j;
        //  cout << "X: " << current_cord.x << endl;
        // cout << "Y: " << current_cord.y << endl;
      }
    }
  }
  return current_cord;
};

__int8_t room_gen::directions(vector<vector<char>> map, cords current_cord) {
  int x = current_cord.x;
  int y = current_cord.y;
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
    // cout << "got soth condition";
    if (map[x + 1][y] != '_') {
      ret |= S;
    }
  }
  return ret;
}

int room_gen::map_direction(vector<vector<char>> map) {

  struct termios oldsettings;
  Movement mg;
  room_gen rg;
  __int8_t rooms_flag = 0b0000;
  char input;
  bool temp = true;
  mg.setRawMode(oldsettings);
  rg.room_print(map);
  room_gen::cords current_cordinates = rg.find_cordinates(map);
  rooms_flag = rg.directions(map, current_cordinates);
  cout << "MAP!" << endl;

  input = mg.getKeyPress();
  char input3;
  if (input == 27) {
    char input2 = mg.getKeyPress();
    if (input2 == '[') {
      input3 = mg.getKeyPress();
      // cout << "INPUT3: " << input3 << endl;
      if (input3 == 'B' && rooms_flag & S) {
        // cout << "got to south exit logic" << endl;
        return 2;
      }
      if (input3 == 'A' && rooms_flag & N) {
        // cout << "got to north exit logic" << endl;
        return 3;
      }
      if (input3 == 'C' && rooms_flag & E &&
          current_cordinates.y + 1 < map.size()) {
        // cout << "got to east exit logic" << endl;
        return 0;
      }
      if (input3 == 'D' && rooms_flag & W && current_cordinates.y - 1 >= 0) {
        //  cout << "got to west exit logic" << endl;
        return 1;
      }
    }
  } else {
    cout << "\n\nexiting..";
    exit(0);
  }
  mg.resetMode(oldsettings);
  return -1;
};

void room_gen ::traverse_map(vector<vector<char>> &map, int input) {
  cords current_cordinates = find_cordinates(map);
  if (input == 2) {
    // cout << "got to south exit logic" << endl;
    map[current_cordinates.x][current_cordinates.y] = 'O';
    map[current_cordinates.x + 1][current_cordinates.y] = 'C';
    return;
  }
  if (input == 3) {
    // cout << "got to north exit logic" << endl;
    map[current_cordinates.x][current_cordinates.y] = 'O';
    map[current_cordinates.x - 1][current_cordinates.y] = 'C';
    return;
  }
  if (input == 0) {
    // cout << "got to east exit logic" << endl;
    map[current_cordinates.x][current_cordinates.y] = 'O';
    map[current_cordinates.x][current_cordinates.y + 1] = 'C';
    return;
  }
  if (input == 1) {
    //  cout << "got to west exit logic" << endl;
    map[current_cordinates.x][current_cordinates.y] = 'O';
    map[current_cordinates.x][current_cordinates.y - 1] = 'C';
    return;
  } else {
    return;
  }
};
/*
int main() {
  room_gen rg;
  long seed;
  vector<vector<char>> map;
  cout << "Enter a seed: ";
  cin >> seed;
  char input;
  srand(seed);
  rg.room_generation(25, 15, 2, map);
  rg.populate_room_types(2, 50, 3, 6, 1, map);
  cout << endl << endl << endl;
  while (true) {
    rg.traverse_map(map);
  }
  return 0;
};
*/
