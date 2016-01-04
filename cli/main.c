#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <termios.h>
#include <unistd.h>
#include <sys/time.h>

#include "screen.h"
#include "input.h"
#include "actions.h"

int main(){
  int quit=0;
  char input;
  //Player player = stubPlayer();
  Map map = zeroMap();
  //Map map = zeroMap();
  char dbgstr[10] = "\0";
  Player player = stubPlayer();
  map->cells[10][10] = 3;
  map->cells[11][10] = 3;
  map->cells[12][10] = 3;
  map->cells[4][7] = 2;
  map->cells[3][3] = 4;
  map->cells[1][19] = 4;
  map->cells[5][10] = 5;
  player->hp = 10;

  render(map, player, "Bienvenue dans Sapés comme Dungeon");

  while(quit==0){
    input = getInput(); //get user input
    process(player, map, input);
    dbgstr[0] = input;
  render(map, player, dbgstr); // render the map
  }
}
// int i, j;
// for(i=0; i<20; i++){
// for(j=0; j<20; j++){
// map->cells[i][j] = 0;
// }
// }
