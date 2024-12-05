#include "player.h"

// Player Constructor.
Player::Player(string n, int a, int ar, int s, int16_t I, int CM, int MXM,
               int CH, int MXH)
    : entity(n, a, ar, s, I, CM, MXM, CH, MXH){};

Player::Player() { cout << "made default character with no stats.." << endl; };
