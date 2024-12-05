#include "rest.h"

// General Constructor.
REST::REST(){};

// Lets the player rest and restores 25% of the players current mana & hp
void REST::resting_room(Player &P1) {
  system("clear");
  cout << TENT << endl << endl;

  cout << "You decide to setup your tent to get some rest.. " << endl;
  this_thread::sleep_for(chrono::milliseconds(4000));

  int health_gained = P1.MAX_HEALTH * 0.25;
  int mana_gained = P1.MAX_MANA * 0.25;
  P1.current_mana += mana_gained;
  P1.current_health += health_gained;

  if (P1.current_health > P1.MAX_HEALTH) {
    P1.current_health = P1.MAX_HEALTH;
  }
  if (P1.current_mana > P1.MAX_MANA) {
    P1.current_mana = P1.MAX_MANA;
  }
  cout << "After you rest, you gain some HP and Mana.." << endl;
  this_thread::sleep_for(chrono::milliseconds(4000));
  return;
}
