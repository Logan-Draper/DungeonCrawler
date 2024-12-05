#include <string>
#include <vector>
#pragma once
using namespace std;
class ITEM_LIST {
public:
  struct item_generic {
    int price;
    string name;
    string description;
    int quantity;
    item_generic(string n, string d, int p, int q);
    item_generic(string n, string d, int p);
    item_generic();
    item_generic(string n, int p, int q);
  };
};

extern ITEM_LIST::item_generic leather;
extern ITEM_LIST::item_generic bones;
extern ITEM_LIST::item_generic feathers;
extern ITEM_LIST::item_generic iron;
extern ITEM_LIST::item_generic gold;
extern ITEM_LIST::item_generic rat_poison;
extern vector<ITEM_LIST::item_generic> generic_list_1;
