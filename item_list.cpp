#include "item_list.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ITEM_LIST::item_generic::item_generic(string n, string d, int p, int q)
    : name(n), description(d), price(p), quantity(q){};

ITEM_LIST::item_generic::item_generic(string n, string d, int p)
    : name(n), description(d), price(p), quantity(1){};

ITEM_LIST::item_generic leather("Leather", "Cow's Leather.. Gross", 3);
ITEM_LIST::item_generic bones("Bones", "Bones. Don't ask me from what", 4);
ITEM_LIST::item_generic feathers("Feathers", "Did dinosaurs have feathers?", 2);
ITEM_LIST::item_generic iron("Iron Ingot", "It's quite heavy.", 15);
ITEM_LIST::item_generic rat_poison("Rat Poison",
                                   "Would not recommend drinking.", 10);

/*
struct healing : public item_generic {
  int health;
  healing() : item_generic(), h

healing apple("Apple", "Red apple", 10, 4);
healing bad_apple("Apple", "Purple apple", -15, 4);
healing steak("Steak", "Still Mooing..", 20, 10);
healing rations("Rations", "It'll hold you over", 15, 12);
healing potion_1("Potion", "Not of great quality, you're bold to drink it", 12,
                 12);
healing potion_2("Potion", "Produced by an Apothicary, of moderate quality", 30,
                 25);
healing potion_3("Potion", "Produced from life fruit, quite rare, quite good..",
                 45, 50);

vector<healing> healing_list_1 = {apple, bad_apple, steak, rations};
vector<healing> healing_list_2 = {potion_1, potion_2, potion_3};
*/

vector<ITEM_LIST::item_generic> generic_list_1 = {leather, bones, feathers,
                                                  iron, rat_poison};
