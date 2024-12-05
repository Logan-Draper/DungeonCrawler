#include "movement.h"
#include <fcntl.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>

// Function to set the terminal to raw mode
// Lot of help from stack overflow here.
void Movement ::setRawMode(struct termios &oldSettings) {
  struct termios newSettings;
  tcgetattr(STDIN_FILENO, &oldSettings); // Get current terminal settings
  newSettings = oldSettings;

  newSettings.c_lflag &= ~(ICANON | ECHO | ISIG);
  newSettings.c_cc[VMIN] = 1;
  newSettings.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSADRAIN, &newSettings); // Set terminal to raw mode
}

// Function to reset terminal to original settings
void Movement::resetMode(const struct termios &oldSettings) {
  tcsetattr(STDIN_FILENO, TCSADRAIN, &oldSettings); // Restore original settings
}

// Function to read a single character from stdin
char Movement::getKeyPress() {
  char ch;
  read(STDIN_FILENO, &ch, 1); // Read one character
  return ch;
}
