#pragma once
using namespace std;
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

class Movement {
public:
  void setRawMode(struct termios &oldSettings);
  void resetMode(const struct termios &oldSettings);
  char getKeyPress();
};
