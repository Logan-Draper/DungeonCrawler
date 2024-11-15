#include "enemy_stat_blocks.h"
#include "loot_gen.h"
#include <iostream>
#include <vector>
using namespace std;

class COM_WEIGHT {
public:
  int sum_stats(entity E);

  int sum_stats(vector<entity> E_list);

  COM_WEIGHT();
  COM_WEIGHT(float EPSILON);

  const float EPSILON;

  int calculate_epsilon(entity Player);

  void generate_enemies(vector<entity> &E, entity Player,
                        vector<entity> ref_list);
};
