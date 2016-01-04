#include <stdio.h>
#include "screen.h"

/*Draw map and stats.*/

//printStats();
void render(Map map, Player player, char *text){
  printf("\e[1;1H\e[2J");
  printStats(player);
  //printMap(map);
  printf("----------------------------------------\n");
  printMap(map);
  printf("----------------------------------------\n");
  printText(text);
  printf("----------------------------------------\n");
}

void printStats(Player player){
  printf("\033[7m%s|", player->name);
  printf("HP: %d/", player->hp);
  printf("%d|", player->maxhp);
  printf("ATK:%d|", player->atk);
  printf("DEF:%d|", player->def);
  printf("LVL:%d|", player->lvl);
  printf("XP:%d\033[0m\n", player->xp);
}

void printMap(Map map){
  /*
    0 : rocher B
    1 : player B
    2 : monstre N
    3 : XP N
    4 : sword N
    5 : shield N
    6 : air N
  */
  int x, y;
	for(x=0; x<20; x++){
    for(y=0; y<20; y++){
      switch(map->cells[x][y]){
        case 0:
          printf("□ ");
          break;
        case 1:
          printf("⛄ ");
          break;
        case 2:
          printf("⛇ ");
          break;
        case 3:
          printf("● ");
          break;
        case 4:
          printf("⚔ ");
          break;
        case 5:
          printf("⛨ ");
          break;
        case 6:
          printf("_ ");
          break;
        default:
          printf("E ");
          break;
      }
    }
    printf("\n");
  }
}

void printText(char *text){
  if(text != NULL){
    printf("\033[7m%s\033[0m\n", text);
  }
}
