#include "item_list.h"
#include <string>
#include <vector>
using namespace std;

class HEALING_ITEM {
public:
  struct healing : public ITEM_LIST::item_generic {
    int health;

    healing(int h);
    healing(int h, string n, string desc, int p, int q);
    healing(string n, string desc, int p, int q);
    healing();
  };

  healing generate_random_healing(vector<healing> list);

  ITEM_LIST::item_generic
  generate_random_item(vector<ITEM_LIST::item_generic> list);
};

extern HEALING_ITEM::healing apple;
extern HEALING_ITEM::healing bad_apple;
extern HEALING_ITEM::healing steak;
extern HEALING_ITEM::healing rations;
extern vector<HEALING_ITEM::healing> healing_list_1;
extern vector<HEALING_ITEM::healing> healing_list_2;
extern HEALING_ITEM::healing potion_1;
extern HEALING_ITEM::healing potion_2;
extern HEALING_ITEM::healing potion_3;
