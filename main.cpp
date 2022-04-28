#include "incl.hpp"
#include "logic.hpp"
int main() {
  game game;
  while (1){ 
    system("python keypress.py");
    game.returnkey();
    game.player_moves();
    }
  return 0;
}