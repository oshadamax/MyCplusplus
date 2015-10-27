#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
  std::string _name;
  bool win;
public:
  Player(std::string ="NULL");
  bool isWinner() const;
  std::string getName() const;
  void winner();

};


#endif
