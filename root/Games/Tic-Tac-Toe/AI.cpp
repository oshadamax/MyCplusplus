#include "AI.h"

#include <iostream>

AI::AI() : win(false) {}

bool AI::isWinner() const {
  return win;
}

void AI::winner() {
  win = true;
}

int AI::move(char B[][3]) {

   // std::cout << "AI MOVES" << std::endl;

   int total_void = 0;
   int pos[9];

   for (int i=0; i < 3; i++)
    for (int j=0; j < 3; j++){

      if (B[i][j] == '_'){
        pos[total_void] = i + j;
        total_void++;

      }
    }

   if (total_void == 0)
    return -1; // Grid full

   return pos[0];

}
