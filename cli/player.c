#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Player stubPlayer(){
  Player player = malloc(sizeof(Player));
  strcpy(player->name, "foo");
  player->pos[0] = 10;
  player->pos[1] = 5;
  player->hp = 10;
  player->maxhp = 10;
  player->xp = 10;
  player->lvl = 2;
  player->atk = 2;
  player->def = 4;
  return player;
}

Player edit_name(Player player, char name[10]){
  strcpy(player->name, name);
  return player;
}