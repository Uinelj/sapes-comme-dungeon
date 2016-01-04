#include "actions.h"

void process(Player player, Map map, char input){
  switch(input){
    case 'z':
      move(player, map, -1, 0);
      break;
    case 'q':
      move(player, map, 0, -1);
      break;
    case 's':
      move(player, map, 1, 0);
      break;
    case 'd':
      move(player, map, 0, 1);
      break;
    case 'e':
      break;
    case 'a':
      break;
    default:
      break;
    }
}

void move(Player player, Map map, int dx, int dy){
  if(!collision(player, map->cells[player->pos[0]+dx][player->pos[1]+dy])){
    map->cells[player->pos[0]][player->pos[1]] = 6;
    player->pos[0] += dx;
    player->pos[1] += dy;
    map->cells[player->pos[0]][player->pos[1]] = 1;
  }
}

int collision(Player player, int celltype){
  /*
    0 : rocher B
    1 : player B
    2 : monstre N
    3 : XP N
    4 : sword N
    5 : shield N
    6 : air N
  */
  switch(celltype){
    case 2:
      player->hp -= ((5*player->lvl)-player->def);
      break;
    case 3:
      player->xp += 5;
      if(player->xp > 20){
        player->lvl++;
        player->atk += player->lvl;
        player->def += 0.5*player->lvl;
        player->xp %= 20;
      }
      break;
    case 4:
      player->atk += 5;
      break;
    case 5:
      player->def += 5;
      break;
    default:
      break;
  }
  return celltype<=1;
}
