#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class room_gen {

#define S (1 << 0)
#define N (1 << 1)
#define E (1 << 3)
#define W (1 << 2)

public:
  struct cords {

    int x;
    int y;
  };

  vector<vector<char>> populate_room_types(int NPC, int ENEM, int REST,
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
            cout << "bumped limiter" << endl;
            j--;
          }
        }
      }
    }
    return map;
  }
  vector<vector<char>> room_generation(int upper_bound, int lower_bound,
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
    for (int k = 0; k < room_nums - 1; k++) {
      // cout << "K :" << k << endl;
      int room_gen_move = (rand() % 100);

      //  If when I move forward, I go out of bounds, loop over again and
      //  generate a new random direction to try.

      if (room_gen_move >= 0 && room_gen_move <= 35) {
        if (current_room_x + 1 >= map_size ||
            map[current_room_x + 1][current_room_y] == 'X') {
          k--;
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
        } else {
          current_room_y -= 1;
          map[current_room_x][current_room_y] = 'X';
        }
      }

      else {
        cout << "We should not be here." << endl;
      }
    }
    for (int i = 0; i < map_size; i++) {
      for (int j = 0; j < map_size; j++) {
        cout << map[i][j] << " ";
      }
      cout << endl;
    }
    return map;
  }

  void room_print(vector<vector<char>> map) {
    for (int i = 0; i < map.size(); i++) {
      for (int j = 0; j < map.size(); j++) {
        cout << map[i][j] << " ";
      }
      cout << endl;
    }
  }

  cords find_cordinates(vector<vector<char>> map) {
    cords current_cord = {0, 0};
    for (int i = 0; i < map.size(); i++) {
      for (int j = 0; j < map.size(); j++) {
        if (map[i][j] == 'C') {
          current_cord.x = i;
          current_cord.y = j;
          cout << "X: " << current_cord.x << endl;
          cout << "Y: " << current_cord.y << endl;
        }
      }
    }
    return current_cord;
  };

  __int8_t directions(vector<vector<char>> map, cords current_cord) {
    int x = current_cord.x;
    int y = current_cord.y;
    __int8_t ret = 0;
    if (map[x + 1][y] != '_') {
      ret |= E;
    }
    if (map[x - 1][y] != '_') {
      ret |= W;
    }
    if (map[x][y + 1] != '_') {
      ret |= N;
    }
    if (map[x][y + 1] != '_') {
      ret |= S;
    }
    return ret;
  }

  void traverse_map(vector<vector<char>> &map) {
    __int8_t rooms_flag = 0b0000;
    char input;
    cords current_cordinates = find_cordinates(map);
    rooms_flag = directions(map, current_cordinates);
    room_print(map);
    bool temp = true;
    cout << "ROOM FLAGS: " << rooms_flag << endl;
    while (temp) {
      cout << "Which Direction would you like to move?" << endl;
      cout << "=======================================" << endl;
      if (rooms_flag & N) {
        cout << "North(N)" << endl;
      }
      if (rooms_flag & S) {
        cout << "South(S)" << endl;
      }
      if (rooms_flag & E) {
        cout << "East(E)" << endl;
      }
      if (rooms_flag & W) {
        cout << "West(W)" << endl;
      }
      cin >> input;
      if (input == 'S' && rooms_flag & S) {
        map[current_cordinates.x][current_cordinates.y] = 'O';
        map[current_cordinates.x][current_cordinates.y - 1] = 'C';
        temp = false;
      }
      if (input == 'N' && rooms_flag & N) {
        map[current_cordinates.x][current_cordinates.y] = 'O';
        map[current_cordinates.x][current_cordinates.y + 1] = 'C';
        temp = false;
      }
      if (input == 'E' && rooms_flag & E) {
        map[current_cordinates.x][current_cordinates.y] = 'O';
        map[current_cordinates.x + 1][current_cordinates.y] = 'C';
        temp = false;
      }
      if (input == 'W' && rooms_flag & W) {
        map[current_cordinates.x][current_cordinates.y] = 'O';
        map[current_cordinates.x - 1][current_cordinates.y] = 'C';
        temp = false;
      }
    }
  }
};
int main() {
  room_gen rg;
  long seed;
  vector<vector<char>> map;
  cout << "Enter a seed: ";
  cin >> seed;
  srand(seed);
  rg.room_generation(25, 15, 2, map);
  rg.populate_room_types(2, 50000, 3, 6, 1, map);
  cout << endl << endl << endl;
  rg.room_print(map);
  rg.traverse_map(map);
  rg.room_print(map);
};
