#ifndef ACTIONS_H
#define ACTIONS_H
#include "player.h"
#include "map.h"
#include <stdio.h>
void process(Player, Map, char);
void move(Player, Map, int, int);
int collision(Player, int);
#endif
