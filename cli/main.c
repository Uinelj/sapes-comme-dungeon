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
serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1") ;//adresse de alexis : a changer à la compilation
serv_addr.sin_port = htons(5000) ;
memset (&serv_addr.sin_zero, 0, sizeof(serv_addr.sin_zero));


/*init end*/

//read(s_cli, map->cells, 80) ;


// int i, j;
// for(i=0; i<20; i++){
// for(j=0; j<20; j++){
// map->cells[i][j] = 0;
// }
// }

map->cells[10][10] = 4;
player->hp = 14;
render(map, player, "Bienvenue dans Sapés comme Dungeon");
connect(s_cli, (struct sockaddr *)&serv_addr, sizeof serv_addr) ;

while(quit==0){
recv(s_cli, map, 80, 0) ;//on reçoit l'état de la map
input = getInput(); //get user input

switch(input){

case 'z' :
send(s_cli, "0;-1", 18,0) ;//move top
break;

case 's' :
send(s_cli, "0;1", 18,0) ;//move down
break;

case 'd' :
send(s_cli, "1;0", 18,0) ;//move right
break;

case 'q' :
send(s_cli, "-1;0", 18,0) ;//move left
break;
case 'e' :
quit=1;
default ://wrong input
send(s_cli, "0;0", 18,0) ;
break;
}

bzero (buf, 80) ;

//TODO : Process user input and send it to the server, waiting for his response.
render(map, player, "Super jeu de fifou sa mere"); // render the map
}
close(s_cli) ;

}