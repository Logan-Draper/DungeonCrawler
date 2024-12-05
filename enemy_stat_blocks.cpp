#include "enemy_stat_blocks.h"
using namespace std;

// Enemy struct definitions.

entity skeleton = {"Skeleton", 2, 0, 2, 100, 0, 0, 10, 10};
entity skeleton_brute = {"Skeleton Brawler", 6, 0, 4, 101, 0, 0, 25, 25};
entity skeleton_horse = {"Hemrich's Horse", 2, 0, 15, 102, 0, 0, 15, 15};
entity goblin = {"Goblin", 3, 1, 4, 200, 0, 0, 15, 15};
entity goblin_nerd = {"Goblin Nerd", 2, 0, 0, 201, 0, 0, 10, 10};
entity goblin_brute = {"Goblin Bruiser", 8, 1, 2, 202, 0, 0, 30, 30};
entity wraith = {"Wraith", 1, 99, 0, 005, 0, 0, 999, 999};
entity necromancer = {"Nercomancer", 7, 4, 10, 103, 0, 0, 15, 15};
entity cultist_1 = {"Cultist of the Sun", 5, 1, 2, 301, 0, 0, 5, 5};
entity werebear = {"Werebear", 5, 1, 5, 302, 0, 0, 15, 15};
entity radiant = {"Radiant One", 1, 20, 1, 303, 0, 0, 50, 50};
entity ghost_in_armor = {"Ghostly Armor", 7, 20, 1, 304, 0, 0, 1, 1};
entity vampire = {"Vampire", 10, 4, 1, 401, 0, 0, 20, 20};
entity vampire_lord = {"Vampire Lord", 15, 7, 1, 402, 0, 0, 100, 100};
entity murker = {"Swamp Thing", 3, 3, 1, 501, 0, 0, 30, 30};
entity ogre = {"Ogre", 5, 5, 1, 502, 0, 0, 40, 40};

vector<entity> enemy_list_1 = {
    skeleton,     skeleton_horse, goblin,      goblin_nerd,
    goblin_brute, skeleton_brute, necromancer, wraith,
    cultist_1,    werebear,       radiant,     ghost_in_armor,
    vampire,      vampire_lord,   murker,      ogre};
