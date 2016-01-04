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
#include "player.h"
int main(){

	//init socket

	int s_cli ;
	struct sockaddr_in serv_addr ;
	char buf [80] ;
	s_cli =socket(PF_INET, SOCK_STREAM, 0) ;
	serv_addr.sin_family = AF_INET ;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1") ;//adresse de alexis : a changer à la compilation
	serv_addr.sin_port = htons(5000) ;
	memset (&serv_addr.sin_zero, 0, sizeof(serv_addr.sin_zero));

	//end init

  int quit=0;
  char input;
  //Player player = stubPlayer();
  Map map = zeroMap(); 
  //Map map = zeroMap();
  char dbgstr[10] = "\0";
  Player player = stubPlayer();

  //demande du nom de joueur
  char namePlayer[10];
  printf("écrivez votre pseudo : ");
  scanf("%s", namePlayer);
  player = edit_name(player, namePlayer);


  //render(map, player, "Bienvenue dans Sapés comme Dungeon");
connect(s_cli, (struct sockaddr *)&serv_addr, sizeof serv_addr) ;
 send(s_cli, player->name, 18,0) ;//move top

  while(quit==0){

  	recv(s_cli, map, 2000, 0) ;//on reçoit l'état de la map
    	recv(s_cli, player, 2000, 0) ;//on reçoit l'état de la map
  	    printf("lavie");

  	  render(map, player, dbgstr); // render the map
  	  printf("%dx", map->cells[3][3]);
    input = getInput(); //get user input
    //dbgstr[0] = input;
            //process(player, map, buf);
  switch(input){

case 'z' :
send(s_cli, "z", 1,0) ;//move top
break;

case 's' :
send(s_cli, "s", 1,0) ;//move down
break;

case 'd' :
send(s_cli, "d", 1,0) ;//move right
break;

case 'q' :
send(s_cli, "q", 1,0) ;//move left
break;
case 'e' :
quit=1;
default ://wrong input
send(s_cli, "0", 1,0) ;
break;
}
  }
  close(s_cli) ;

}
