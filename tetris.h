#ifndef _TETRIS_H
#define _TETRIS_H

#include "game.h"



bool isFreeBlock( Board *theBoard, int x, int y);
void getPiecePosition(int pX, int pY, int *newX, int *newY);
bool movePossible(Board *theBoard, int x, int y, int thePiece, int pRotation);
void storePiece(Board *theBoard, int x, int y, int thePiece, int pRotation);
void deletePossibleLines(Board *theBoard);
bool isGameOver(Board *theBoard);

void initBoard( Board *theBoard );
void deleteLine(Board *theBoard, int yLoc);
#endif
