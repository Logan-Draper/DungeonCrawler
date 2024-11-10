#include "movement.h"
#include <fcntl.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>

// Function to set the terminal to raw mode
void Movement ::setRawMode(struct termios &oldSettings) {
  struct termios newSettings;
  tcgetattr(STDIN_FILENO, &oldSettings); // Get current terminal settings
  newSettings = oldSettings;

  // Disable canonical mode and echo
  newSettings.c_lflag &= ~(ICANON | ECHO | ISIG);
  newSettings.c_cc[VMIN] = 1;  // Minimum number of characters to read
  newSettings.c_cc[VTIME] = 0; // No timeout

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
/*
int main() {
  Movement mg;
  struct termios oldSettings;

  // Set terminal to raw mode
  mg.setRawMode(oldSettings);

  std::cout << "Press arrow keys (up, down, left, right) or ESC to quit.\n";

  while (true) {
    char key = mg.getKeyPress();
    // ESC key to exit the loop

    // Detect arrow keys (ESC + [ + Arrow Key)
    if (key == 27) { // The ESC character
      char secondChar = mg.getKeyPress();
      if (secondChar == '[') { // Read the next characte
        char thirdChar =
            mg.getKeyPress(); // Read the final character for arrow key
        switch (thirdChar) {
        case 'A':
          std::cout << "Up Arrow pressed\n";
          break;
        case 'B':
          std::cout << "Down Arrow pressed\n";
          break;
        case 'C':
          std::cout << "Right Arrow pressed\n";
          break;
        case 'D':
          std::cout << "Left Arrow pressed\n";
          break;
        default:
          break;
        }
        continue;
      }
    }
    if (key == 27) {
      std::cout << "\nExiting...\n";
      break;
    }
    if (key == '\n') {
      std::cout << "ENTER KEY !" << std::endl;
      continue;
    } else {
      std::cout << "Key pressed: " << key << std::endl;
    }
  }
  // Reset the terminal settings before exiting
  mg.resetMode(oldSettings);

  return 0;
}
*/
