#ifndef _IO_H
#define _IO_H

#include "game.h"

// Have to implement own solution for these!
uint64_t getTime(void);
void drawRectangle(int x0, int y0, int x1, int y1, char *color_s);
void clearScreen(void);
void handleInput(int code, Board  *theBoard, Game *theGame);

#endif
