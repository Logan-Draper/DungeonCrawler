#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct enemy {

  int health;
  string name;
  enemy(int h, string n) : health(h), name(n){};
};

enemy bat(10, "BAT");
vector<enemy> list = {bat, bat, bat};

class Spell {
public:
  virtual ~Spell() {}
  virtual void attack(vector<enemy> &, int) const = 0;
};

class Fireball : public Spell {
private:
  int damage;
  int mana_cost;

public:
  Fireball(int d, int m) : damage(d), mana_cost(m) {}

  void attack(vector<enemy> &list, int index) const override {
    if (index <= list.size() - 1 && list[index + 1].name != "") {
      list[index + 1].health -= damage;
    }
    if (index != 0 && list[index - 1].name != "") {
      list[index - 1].health -= damage;
    }
    list[index].health -= damage;
  }
};
/*
int main() {
  int damage;
  int mana;
  Fireball FB(10, 10);
  FB.attack(list, 0);

  for (int i = 0; i < list.size(); i++) {
    cout << list[i].name << ": " << list[i].health << endl;
  }
  return 0;
}
*/
