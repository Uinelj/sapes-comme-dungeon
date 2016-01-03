#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

Map getMap(){
  Map map = malloc(sizeof(Map));
  /*Stub : TODO : Get map from server. Waiting for LE CODE DE ALEXIS*/
  return map;
}

Map zeroMap(Map map){
  int i,j;
  int width = 20;
  int length = 20;

  map->id=1;
  for(i=0; i<width; i++){
    for(j=0; j<length; j++){
      map->cells[i][j] = 0;
    }
  }
  return map;
}
