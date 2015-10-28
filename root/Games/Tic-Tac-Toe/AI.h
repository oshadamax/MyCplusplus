#ifndef AI_H
#define AI_H


class AI {
private:
  bool win;
public:
  AI();
  bool isWinner() const;
  void winner();
  int move(char [][3]);

};


#endif
