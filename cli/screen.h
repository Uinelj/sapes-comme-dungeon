#ifndef SCREEN_H
#define SCREEN_H
#include "map.h"
#include "player.h"
void render(Map map, Player player, char *text);
void printStats(Player player);
void printMap(Map map);
void printText(char *text);
#endif
