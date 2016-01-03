#include <stdio.h>
#include "screen.h"

/*Draw map and stats.*/

//printStats();
void render(Map map, Player player, char *text){
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
  int x, y;
	for(x=0; x<20; x++){
    for(y=0; y<20; y++){
      printf("%d ", map->cells[x][y]);
    }
    printf("\n");
  }
}

void printText(char *text){
  if(text != NULL){
    printf("\033[7m%s\033[0m\n", text);
  }
}
