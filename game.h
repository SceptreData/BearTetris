#ifndef _GAME_H
#define _GAME_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <BearLibTerminal.h>

#include "config.h"
#include "tetris.h"
#include "pieces.h"
#include "IO.h"

#define WAIT_TIME 700


int getRand(int a, int b);
void initGame( Game *theGame );
void newPiece( Game *theGame );
void drawPiece(int x, int y, int thePiece, int pRot);
void drawScene(Board *theBoard, Game *theGame);    

#endif
