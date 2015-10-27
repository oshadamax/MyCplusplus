#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game {
private:
  char Board[3][3];
  Player player;

  void showBoard() const;
  void menu() const;
  void gameLoop();
  void checkBoard();

public:
  Game();
  void run();



};




#endif
