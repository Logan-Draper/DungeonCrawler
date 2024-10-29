#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct item_generic {
  int price;
  string name;
  string description;
  item_generic(string n, string desc, int p) {
    name = n, description = desc, price = p;
  }
  item_generic();
};

item_generic leather("Leather", "Cow's Leather.. Gross", 3);
item_generic bones("Bones", "Bones. Don't ask me from what", 4);
item_generic feathers("Feathers", "Did dinosaurs have feathers?", 2);
item_generic iron("Iron Ingot", "It's quite heavy.", 15);
item_generic rat_poison("Rat Poison", "Would not recommend drinking.", 10);

struct healing : item_generic {
  int health;

  healing(string n, string desc, int h, int p) {

    name = n, desc = description, h = health, p = price;
  };
};

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
vector<item_generic> generics_list_1 = {leather, bones, feathers, iron,
                                        rat_poison};

healing generate_random_item(vector<healing> list) {
  return list[rand() % list.size()];
}

item_generic generate_random_item(vector<item_generic> list) {
  return list[rand() % list.size()];
}
