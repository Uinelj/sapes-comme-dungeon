#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

int main(){
  int quit=0;
  char input;

  //Player player = stubPlayer();
  Map map = malloc(sizeof(Map));
  Player player = stubPlayer();
  // int i, j;
  // for(i=0; i<20; i++){
  //   for(j=0; j<20; j++){
  //     map->cells[i][j] = 0;
  //   }
  // }
  map->cells[10][10] = 4;
  player->hp = 14;
  while(quit==0){
    scanf("%c", &input); //Get user input
    //TODO : Process user input and send it to the server, waiting for his response.
    render(map, player, "sample text");
  }
}
