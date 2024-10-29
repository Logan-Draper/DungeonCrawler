#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> populate_room_types(int NPC, int ENEM, int REST,
                                         int RANDOM, int BLESSED,
                                         vector<vector<char>> &map) {
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
                                     int map_level, vector<vector<char>> &map) {

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
  map[room_start_x][room_start_y] = 'O';

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

int main() {

  long seed;
  vector<vector<char>> map;
  cout << "Enter a seed: ";
  cin >> seed;
  srand(seed);
  room_generation(25, 15, 2, map);
  populate_room_types(2, 50000, 3, 6, 1, map);
  cout << endl << endl << endl;
  room_print(map);
};
