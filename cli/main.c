#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "input.h"
#include "actions.h"

int main(){
  int quit=0;
  char input;
  //Player player = stubPlayer();
  Map map = malloc(sizeof(Map));
  char dbgstr[10] = "\0";
  Player player = stubPlayer();

  //socket init

  /*int s_cli ;
  struct sockaddr_in serv_addr ;
  char buf [80] ;
  s_cli =socket(PF_INET, SOCK_STREAM, 0) ;
  serv_addr.sin_family = AF_INET ;
  serv_addr.sin_addr.s_addr = inet_addr("192.168.0.12") ;//adresse de alexis : a changer à la compilation
  serv_addr.sin_port = htons(5000) ;
  memset (&serv_addr.sin_zero, 0, sizeof(serv_addr.sin_zero));

  read(s_cli, map->cells, 80) ;

  //init end

  //connect(s_cli, (struct sockaddr *)&serv_addr, sizeof serv_addr) ;
  */


  map->cells[10][10] = 4;
  player->hp = 14;

  render(map, player, "Bienvenue dans Sapés comme Dungeon");

  while(quit==0){
    input = getInput(); //get user input
    process(player, map, input);
    dbgstr[0] = input;
  render(map, player, dbgstr); // render the map
  }
}
