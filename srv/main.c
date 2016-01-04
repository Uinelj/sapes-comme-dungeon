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
#include <pthread.h> 


typedef struct Sc_struct { 
  Player players[5]; 
  int *s_dial;
  char buf [80] ; 
  Map map; 
}*Sc;

void * fn_thread ( void *sc)
{
    Sc sic = (Sc*) sc;

      char name[10];
      recv(sic->s_dial, name, 18, 0) ; 
      sic->players[0] = edit_name(sic->players[0], name);
    while(1){

  send(sic->s_dial, sic->map,2000,0);//envoie de la map aux client 
    send(sic->s_dial, sic->players[0],2000,0);//envoie de la map aux client 


    recv(sic->s_dial, sic->buf, 1, 0) ;
            process(sic->players[0], sic->map, sic->buf[0]);


    printf ("%s \n", sic->buf) ;//on reçoit une instruction 
  }
}

int main () { 
  Sc sc = malloc(sizeof(struct Sc_struct));
  int cli_len, c , s_ecoute; 
  struct sockaddr_in serv_addr, cli_addr ; 
  serv_addr.sin_family = AF_INET ;
  serv_addr.sin_addr.s_addr = INADDR_ANY ; 
  serv_addr.sin_port = htons (5000) ; 
  s_ecoute =socket(PF_INET, SOCK_STREAM, 0) ;

  memset (&serv_addr.sin_zero, 0, sizeof(serv_addr.sin_zero)); 
  printf("%d",bind(s_ecoute, (struct sockaddr *)&serv_addr, sizeof serv_addr) ); 
  listen(s_ecoute, 5) ; cli_len = sizeof cli_addr ; 
   c = sizeof(struct sockaddr_in);
pthread_t thread_id;
  
    
  Map map = zeroMap();
  while (1) { 
    sc = malloc(sizeof(struct Sc_struct));
      sc->map= map; 
      sc->players[0] = stubPlayer();
sc->map->cells[10][10] = 3;
  sc->map->cells[11][10] = 3;
  sc->map->cells[12][10] = 3;
  sc->map->cells[4][7] = 2;
  sc->map->cells[3][3] = 4;
  sc->map->cells[1][19] = 4;
  sc->map->cells[5][10] = 5;

 		/*Ici un processus dialogue avec le client */ 
    sc->s_dial = accept(s_ecoute, (struct sockaddr *)&cli_addr, &cli_len);
    pthread_create( &thread_id , NULL , fn_thread , sc);

 		
 	}
    close(sc->s_dial);
		close(s_ecoute) ; 

	return 0 ; 
}