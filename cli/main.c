#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "input.h"

int main(){
  int quit=0;
  char input;
  //Player player = stubPlayer();
  Map map = malloc(sizeof(Map));

  Player player = stubPlayer();

  //socket init

  int s_cli ;
  struct sockaddr_in serv_addr ;
  char buf [80] ;
  s_cli =socket(PF_INET, SOCK_STREAM, 0) ;
  serv_addr.sin_family = AF_INET ;
  serv_addr.sin_addr.s_addr = inet_addr("192.168.0.12") ;//adresse de alexis : a changer à la compilation
  serv_addr.sin_port = htons(5000) ;
  memset (&serv_addr.sin_zero, 0, sizeof(serv_addr.sin_zero));

  read(s_cli, map->cells, 80) ; 

  /*init end*/

  connect(s_cli, (struct sockaddr *)&serv_addr, sizeof serv_addr) ;


  // int i, j;
  // for(i=0; i<20; i++){
  // for(j=0; j<20; j++){
  // map->cells[i][j] = 0;
  // }
  // }

  map->cells[10][10] = 4;
  player->hp = 14;
  render(map, player, "Bienvenue dans Sapés comme Dungeon");

  while(quit==0){
    input = getInput(); //get user input

    switch(input){

    case 'z' :
      write(s_cli, "0;-1", 18) ;//move top
      break;

    case 's' :
      write(s_cli, "0;1", 18) ;//move down
      break;

    case 'd' :
      write(s_cli, "1;0", 18) ;//move right
      break;

    case 'q' :
      write(s_cli, "-1;0", 18) ;//move left
      break;

    default ://wrong input
      write(s_cli, "0;0", 18) ;
      break;
    }

  bzero (buf, 80) ;
  close(s_cli) ;

  //TODO : Process user input and send it to the server, waiting for his response.
  render(map, player, "Super jeu de fifou sa mere"); // render the map
  }
}