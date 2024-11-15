#include "enemy_stat_blocks.h"
using namespace std;

entity skeleton = {"Skeleton", 2, 0, 2, 100, 0, 0, 10, 10};
entity skeleton_brute = {"Skeleton Brawler", 6, 0, 4, 101, 0, 0, 25, 25};
entity skeleton_horse = {"Hemrich's Horse", 2, 0, 15, 102, 0, 0, 15, 15};
entity goblin = {"Goblin", 3, 1, 4, 200, 0, 0, 15, 15};
entity goblin_nerd = {"Goblin Nerd", 2, 0, 0, 201, 0, 0, 10, 10};
entity goblin_brute = {"Goblin Bruiser", 8, 1, 2, 202, 0, 0, 30, 30};
entity wraith = {"Wraith", 1, 9999, 0, 005, 0, 0, 999, 999};
entity necromancer = {"Nercomancer", 15, 7, 5, 30};
entity necro_skele;
entity lich_boss;
entity cultist_1;

vector<entity> enemy_list_1 = {skeleton, goblin, goblin_nerd, goblin_brute,
                               skeleton_brute};

// int main() { cout << ""; }
