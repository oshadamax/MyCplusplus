#include "Player.h"
#include <string>

Player::Player(std::string name) : _name(name), win(false) {}



bool Player::isWinner() const{
  return win;
}

std::string Player::getName() const{
  return _name;
}

void Player::winner() {
  win = true;
}
