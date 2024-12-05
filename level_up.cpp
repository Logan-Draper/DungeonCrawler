#include "level_up.h"
#include "enemy_stat_blocks.h"

// Levels the Player up based on whatever stat they choose.
void LVLUP::level_up_player(entity &player) {
  char input;
  system("clear");
  cout << "LEVEL UP!" << endl;
  while (input != 'S' && input != 's' && input != 'H' && input != 'h' &&
         input != 'A' && input != 'a' && input != 'M' && input != 'm') {
    cout << "Which Stat would you like to upgrade? " << endl;
    cout << "======================================" << endl;
    cout << "||SPEED  (S)              (+1)      ||" << endl;
    cout << "||                                  ||" << endl;
    cout << "||HEALTH (H)              (+5)      ||" << endl;
    cout << "||                                  ||" << endl;
    cout << "||ATTACK (A)              (+2)      ||" << endl;
    cout << "||                                  ||" << endl;
    cout << "||MANA   (M)              (+3)      ||" << endl;
    cout << "||                                  ||" << endl;
    cout << "======================================" << endl;
    cin >> input;
  }
  switch (input) {

  case ('H'):

  case ('h'):
    player.MAX_HEALTH += 5;
    break;

  case ('S'):

  case ('s'):
    player.speed += 1;
    break;

  case ('a'):

  case ('A'):
    player.attack += 2;
    break;

  case ('m'):

  case ('M'):
    player.MAX_MANA += 2;
    break;
  default:
    cout << "no valid selection made." << endl;
  };
  player.current_mana = player.MAX_MANA;
  player.current_health = player.MAX_HEALTH;
  return;
};
