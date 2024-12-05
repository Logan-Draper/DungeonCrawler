#include "item_list.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ITEM_LIST::item_generic::item_generic(){};

ITEM_LIST::item_generic::item_generic(string n, string d, int p, int q)
    : name(n), description(d), price(p), quantity(q){};

ITEM_LIST::item_generic::item_generic(string n, string d, int p)
    : name(n), description(d), price(p), quantity(1){};

ITEM_LIST::item_generic::item_generic(string, int p, int q)
    : price(p), quantity(q){};

ITEM_LIST::item_generic leather("Leather", "Cow's Leather.. Gross", 3);
ITEM_LIST::item_generic bones("Bones", "Bones. Don't ask me from what", 4);
ITEM_LIST::item_generic feathers("Feathers", "Did dinosaurs have feathers?", 2);
ITEM_LIST::item_generic iron("Iron Ingot", "It's quite heavy.", 15);
ITEM_LIST::item_generic rat_poison("Rat Poison",
                                   "Would not recommend drinking.", 10);
ITEM_LIST::item_generic gold("Gold", "Some small gold pieces..", 1);
ITEM_LIST::item_generic dragon_scale("Dragon Scale", "Aboloth's Scale..", 200);
ITEM_LIST::item_generic cloth("Cloth", "Tattered Cloth", 2);
ITEM_LIST::item_generic herbs("Herbs & Spices", "Good for cooking.. ", 15);
ITEM_LIST::item_generic salt("Salt", "A necessity down here", 3);
ITEM_LIST::item_generic cotton("Cotton",
                               "Not sure how cotton got into a dungeon?", 5);
ITEM_LIST::item_generic crystal("Crystal", "Rare but rather useless mineral.",
                                4);
ITEM_LIST::item_generic spider_silk("Spider's Silk",
                                    "Spiderman did NOT make this..", 7);

vector<ITEM_LIST::item_generic> generic_list_1 = {
    gold,  leather,      bones, feathers, iron,        rat_poison, salt,
    cloth, dragon_scale, herbs, cotton,   spider_silk, crystal};
