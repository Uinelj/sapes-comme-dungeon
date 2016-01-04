#ifndef PLAYER_H
#define PLAYER_H
typedef struct plstruct{
  char name[10];
  int pos[2];
  int hp;
  int maxhp;
  int xp;
  int lvl;
  int atk;
  int def;
}*Player;

Player stubPlayer();
Player edit_name(Player player, char name[10]);

#endif
