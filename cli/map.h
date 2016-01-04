#ifndef MAP_H
#define MAP_H
typedef struct map_struct{
  int id;
  int cells[20][20];
}*Map;
Map zeroMap();
#endif
