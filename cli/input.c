#include "input.h"
char getInput(){
  int ch;
  changemode(1);
  while(!kbhit()){}
  ch = getchar();
  changemode(0);
  return ch;
}
