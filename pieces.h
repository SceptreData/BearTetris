#ifndef _PIECES_H
#define _PIECES_H

enum
{
    SQUARE,
    STRAIGHT,
    L,
    LM,
    N,
    NM,
    T
};

int getBlockType(int newPiece, int pRotation, int px, int py);
void getStartPos(int newPiece, int pRotation, int *newX, int *newY);

#endif
