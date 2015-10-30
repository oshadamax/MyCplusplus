#include "Game.h"
#include "Player.h"
#include "AI.h"

#include <iostream>
#include <string>





Game::Game() : ACTOR(0) {

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      Board[i][j] = '_';

}


void Game::showBoard() const{

  std::cout << "    0   1   2  " << std::endl;

  for (int i = 0; i < 3; i++){

    std::cout << i;

    for (int j = 0; j < 3; j++)
      std::cout << " | "  << Board[i][j];

    std::cout << " |" << std::endl;
  }

}

void Game::menu() const{

  std::cout << " WELCOME TO TIC-TAC-TOE " << std::endl << std::endl;

  std::cout << " 1 - New Game" << std::endl;
  std::cout << " 2 - Quit" << std::endl << std::endl;

  std::cout << " Make your choice : ";


}


void Game::gameLoop() {


  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      Board[i][j] = '_';

  std::string name;

  std::cout << " Enter your name : ";
  std::cin >> name;

  player = Player(name);

  int x, i, j, a_func;
  char c;
  bool full = false;

  while (!player.isWinner() && !ai.isWinner() && !full) {


    ACTOR = 0;

    showBoard();

    std::cout << std::endl << " Make your move : ";
    std::cin >> x;

    i = (x / 10) % 10;
    j = x % 10;

    Board[i][j] = 'X';

    checkBoard();

    if (!player.isWinner()) {

      ACTOR = 1;

      a_func = ai.move(Board);

      if (a_func == -1)
        full = true;
      else {

        bool b = false;

        for (int i=0;i<3 && !b;i++)
          for (int j=0;j<3 && !b;j++){

            if (a_func == 0){
              Board[i][j] = 'O';
              b = true;
            }

            a_func--;

          }


        checkBoard();

    }

  }

}

  if (player.isWinner())
    std::cout << player.getName() << " WINS " << std::endl;
  else if (ai.isWinner())
    std::cout <<" COMPUTER WINS " << std::endl;
  else if (full)
    std::cout <<" NO WINNER " << std::endl;

  showBoard();

  std::cout << " Press ENTER to continue...";
  std::cin >> c;

  if (c == '\n')
    return;

}



void Game::run() {

  bool b = true;
  int i;

  while (b) {

    system("clear");

    menu();

    std::cin >> i;

    switch (i) {
      case 1:
        gameLoop();
        break;
      case 2:
        b = false;
        break;
    }
  }
}


void Game::checkBoard() {

  char c;

  switch (ACTOR) {
    case 0:
      c = 'X';
      break;
    case 1:
      c = 'O';
      break;
    default:
      break;

  }

  if (Board[0][0] == Board[0][1] && Board[0][1] == Board[0][2] && Board[0][0]==c){
    winMove();
    return;
  }

  if (Board[1][0] == Board[1][1] && Board[1][1] == Board[1][2] && Board[1][0]==c){
    winMove();
    return;
  }

  if (Board[2][0] == Board[2][1] && Board[2][1] == Board[2][2] && Board[2][0]==c){
    winMove();
    return;
  }

  if (Board[0][0] == Board[1][0] && Board[1][0] == Board[2][0] && Board[0][0]==c){
    winMove();
    return;
  }

  if (Board[0][1] == Board[1][1] && Board[1][1] == Board[2][1] && Board[0][1]==c){
    winMove();
    return;
  }

  if (Board[0][2] == Board[1][2] && Board[1][2] == Board[2][2] && Board[0][2]==c){
    winMove();
    return;
  }

  if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[0][0]==c){
    winMove();
    return;
  }

  if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[0][2]==c){
    winMove();
    return;
  }
}

void Game::winMove() {
  if (ACTOR == 0)
    player.winner();
  else
   ai.winner();
}
