#include "blessing.h"

BLESS::BLESS(){};

// Swaps two of the players stats randomly.
void BLESS::stat_swap(Player &P1) {
  int random1 = rand() % 4;
  int temp;
  switch (random1) {

  case (0):
    temp = P1.attack;
    P1.attack = P1.armor;
    P1.armor = temp;

  case (1):
    temp = P1.MAX_HEALTH;
    P1.MAX_HEALTH = P1.MAX_MANA;
    P1.MAX_MANA = temp;
    P1.current_health = P1.MAX_HEALTH;
    P1.current_mana = P1.MAX_MANA;
    break;

  case (2):
    temp = P1.attack;
    P1.attack = P1.speed;
    P1.speed = P1.attack;

  case (3):
    cout << "You got lucky.. No swaps.." << endl;
    break;

  default:
    return;
  };
  return;
}

// Switch on a random number and it buffs or debuffs the player.
void BLESS::blessup(Player &P1) {
  int random = rand() % 10;
  cout << "============================" << endl;
  cout << "                            " << endl;
  cout << "YOU SPUN THE BLESSING WHEEL " << endl;
  cout << "AND YOU GOTTTTTT:           " << endl;
  switch (random) {

  case (0):
  case (1):
    cout << "MAX HEALTH UP BY 10%!     " << endl;
    P1.MAX_HEALTH += (P1.MAX_HEALTH * 0.10);
    P1.current_health = P1.MAX_HEALTH;
    break;

  case (2):
  case (3):
    cout << "MAX MANA UP BY 20%!       " << endl;
    P1.MAX_MANA += (P1.MAX_MANA * 0.20);
    P1.current_mana = P1.MAX_MANA;
    break;
  case (4):
  case (5):
    cout << "FULL RESTORE!!            " << endl;
    P1.current_mana = P1.MAX_MANA;
    P1.current_health = P1.MAX_HEALTH;
    break;
  case (6):
    cout << "SPEED UP! +5              " << endl;
    P1.speed += 5;
    break;
  case (7):
    cout << "Crippled Leg. Speed - 10  " << endl;
    cout << "They can't all be good..  " << endl;
    P1.speed -= 10;
    if (P1.speed < 0) {
      P1.speed = 0;
    }
    break;
  case (8):
    cout << "RAY OF WEAKNESS Attack - 5" << endl;
    P1.attack -= 5;
    break;
  case (9):
    cout << "STAT SWAP!" << endl;
    stat_swap(P1);
    break;
  default:
    cout << "(BLESSING) we shouldn't be here.." << endl;
    exit(0);
  };
  cout << "                            " << endl;
  cout << "============================" << endl;
  this_thread::sleep_for(chrono::milliseconds(5000));
  return;
};
