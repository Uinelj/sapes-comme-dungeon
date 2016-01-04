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
#include "../cli/screen.h"
#include "../cli/input.h"
#include "../cli/actions.h"


int main () { 

  Player players[5];
  int s_ecoute, s_dial, cli_len ; 
  struct sockaddr_in serv_addr, cli_addr ; 
  char buf [80] ; 
  serv_addr.sin_family = AF_INET ;
  serv_addr.sin_addr.s_addr = INADDR_ANY ; 
  serv_addr.sin_port = htons (5000) ; 
  Map map = zeroMap(); 
  s_ecoute =socket(PF_INET, SOCK_STREAM, 0) ;
  memset (&serv_addr.sin_zero, 0, sizeof(serv_addr.sin_zero)); 
  bind(s_ecoute, (struct sockaddr *)&serv_addr, sizeof serv_addr) ; 
  listen(s_ecoute, 5) ; cli_len = sizeof cli_addr ; 
  s_dial =accept(s_ecoute, (struct sockaddr *)&cli_addr, &cli_len) ; 

  //reception du pseudo
  char name[10];
      recv(s_dial, name, 18, 0) ; 
      players[0] = stubPlayer();
      players[0] = edit_name(players[0], name);

     map->cells[10][10] = 3;
  map->cells[11][10] = 3;
  map->cells[12][10] = 3;
  map->cells[4][7] = 2;
  map->cells[3][3] = 4;
  map->cells[1][19] = 4;
  map->cells[5][10] = 5;
  players[0]->hp = 10;

  while (1) { 
 		/*Ici un processus dialogue avec le client */ 
 		send(s_dial, map,2000,0);//envoie de la map aux client 
    

 		recv(s_dial, buf, 1, 0) ;
            process(players[0], map, buf[0]);

 		printf ("%s \n", buf) ;//on reçoit une instruction 
 	}
		close(s_ecoute) ; 
		close(s_dial) ; 

	return 0 ; 
}