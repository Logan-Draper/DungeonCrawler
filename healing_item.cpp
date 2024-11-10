#include "healing_item.h"
using namespace std;

HEALING_ITEM::healing generate_random_item(vector<HEALING_ITEM::healing> list) {
  return list[rand() % list.size()];
}
ITEM_LIST::item_generic
generate_random_item(vector<ITEM_LIST::item_generic> list) {
  return list[rand() % list.size()];
}
HEALING_ITEM::healing::healing(int h, string n, string d, int p, int q)
    : item_generic(n, d, p, q), health(h){};
HEALING_ITEM::healing::healing(string n, string d, int p, int q)
    : item_generic(n, d, p, q), health(0){};
HEALING_ITEM::healing apple("Apple", "Red apple", 10, 4);
HEALING_ITEM::healing bad_apple("Apple", "Purple apple", -15, 4);
HEALING_ITEM::healing steak("Steak", "Still Mooing..", 20, 10);
HEALING_ITEM::healing rations("Rations", "It'll hold you over", 15, 12);
HEALING_ITEM::healing
    potion_1("Potion", "Not of great quality, you're bold to drink it", 12, 12);
HEALING_ITEM::healing potion_2("Potion",
                               "Produced by an Apothicary, of moderate quality",
                               30, 25);
HEALING_ITEM::healing
    potion_3("Potion", "Produced from life fruit, quite rare, quite good..", 45,
             50);

vector<HEALING_ITEM::healing> healing_list_1 = {apple, bad_apple, steak,
                                                rations};
vector<HEALING_ITEM::healing> healing_list_2 = {potion_1, potion_2, potion_3};
