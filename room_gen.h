using namespace std;
#include "movement.h"
#include <cstdlib>
#include <iostream>
#include <vector>

class room_gen {
public:
#ifndef DEFINE
#define S (1 << 0)
#define N (1 << 1)
#define E (1 << 3)
#define W (1 << 2)

#endif
  struct cords {
    int x;
    int y;
    cords();
    cords(int x, int y);
  };
  room_gen();
  vector<vector<char>> populate_room_types(int n, int e, int R, int RA, int B,
                                           vector<vector<char>> &map);

  void room_print(vector<vector<char>> map);

  vector<vector<char>> room_generation(int ub, int lb, int mplvl,
                                       vector<vector<char>> &map);
  int map_direction(vector<vector<char>> map);

  cords find_cordinates(vector<vector<char>> map);

  __int8_t directions(vector<vector<char>> map, cords cc);

  void traverse_map(vector<vector<char>> &map, int inputs);
};
