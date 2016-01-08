#ifndef _CONFIG_H
#define _CONFIG_H

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define BOARD_LINE_WIDTH 1
#define BLOCK_SIZE 1
#define BOARD_POSITION 40
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define PIECE_BLOCKS 5

enum
{
    POS_FREE,
    POS_FILLED
};

typedef struct Board 
{
    int bGrid[BOARD_WIDTH][BOARD_HEIGHT];
    int score;
} Board;

typedef struct Game 
{
    int mXloc, mYloc;
    int mPiece, mRot;

    int nextX, nextY;
    int nextP, nextRot;
} Game;

#endif
