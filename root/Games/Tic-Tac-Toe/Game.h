#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "AI.h"

class Game {
private:
  char Board[3][3];
  Player player;
  AI ai;
  int ACTOR; // defines player or cpu

  void showBoard() const;
  void menu() const;
  void gameLoop();
  void checkBoard();
  void winMove();

public:
  Game();
  void run();

};






#endif
