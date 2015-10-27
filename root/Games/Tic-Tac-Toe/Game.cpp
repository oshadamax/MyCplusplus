#include "Game.h"
#include "Player.h"

#include <iostream>
#include <string>


Game::Game() {

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

  std::string name;

  std::cout << " Enter your name : ";
  std::cin >> name;

  player = Player(name);

  int x, i, j;

  while (!player.isWinner()) {

    showBoard();

    std::cout << std::endl << " Make your move : ";
    std::cin >> x;

    i = (x / 10) % 10;
    j = x % 10;

    Board[i][j] = 'X';

    checkBoard();





  }

  if (player.isWinner())
    std::cout << player.getName() << " WINS " << std::endl;

  std::cout << " Enter a key to continue...";
  std::cin >> x;


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

  if (Board[0][0] == Board[0][1] && Board[0][1] == Board[0][2] && Board[0][0]!='_'){
    player.winner();
    return;
  }

  if (Board[1][0] == Board[1][1] && Board[1][1] == Board[1][2] && Board[1][0]!='_'){
    player.winner();
    return;
  }

  if (Board[2][0] == Board[2][1] && Board[2][1] == Board[2][2] && Board[2][0]!='_'){
    player.winner();
    return;
  }

  if (Board[0][0] == Board[1][0] && Board[1][0] == Board[2][0] && Board[0][0]!='_'){
    player.winner();
    return;
  }

  if (Board[0][1] == Board[1][1] && Board[1][1] == Board[2][1] && Board[0][1]!='_'){
    player.winner();
    return;
  }

  if (Board[0][2] == Board[1][2] && Board[1][2] == Board[2][2] && Board[0][2]!='_'){
    player.winner();
    return;
  }

  if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[0][0]!='_'){
    player.winner();
    return;
  }

  if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[0][2]!='_'){
    player.winner();
    return;
  }
}
