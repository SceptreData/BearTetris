#include "game.h"

int getRand(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

void initGame( Game *theGame )
{
    srand(time(NULL));

    theGame->mPiece = getRand(0,6);
    theGame->mRot  = getRand(0, 3);
    int pX, pY;
    getStartPos(theGame->mPiece, theGame->mRot, &pX, &pY);
    theGame->mXloc = (BOARD_WIDTH / 2) + pX;
    theGame->mYloc = pY;

    theGame->nextP = getRand(0, 6);
    theGame->nextRot = getRand(0,3);
    theGame->nextX =  BOARD_WIDTH + 5;
    theGame->nextY = 5;
}

void newPiece(Game *theGame)
{
    theGame->mPiece = theGame->nextP;
    theGame->mRot  = theGame->nextRot;
    int pX, pY;
    getStartPos(theGame->mPiece, theGame->mRot, &pX, &pY);
    theGame->mXloc = (BOARD_WIDTH / 2) + pX;
    theGame->mYloc = pY;
    theGame->nextP = getRand(0, 6);
    theGame->nextRot = getRand(0,3);
}

void drawPiece(int x, int y, int thePiece, int pRot)
{
    color_t pColor;
    int newX, newY;
    getPiecePosition( x, y,  &newX, &newY );

    for (int i = 0; i < PIECE_BLOCKS; i++){
        for (int j = 0; j < PIECE_BLOCKS; j++){
            int cTest = getBlockType(thePiece, pRot, j, i);
            if (cTest == 1) pColor = color_from_name("orange");
            else if (cTest == 2) pColor = color_from_name("blue");

            if (cTest != 0){
                terminal_color(pColor);
                terminal_put(newX + i, newY + j, 0x2588);
            }
        }
    }
}

void drawBoard(Board *theBoard, Game *theGame )
{
    int mx1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2));
    int mx2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
    int my = SCREEN_HEIGHT - (BLOCK_SIZE * BOARD_HEIGHT);
    
    drawRectangle(mx1 - BOARD_LINE_WIDTH, my, mx1, SCREEN_HEIGHT - 1, "blue");
    drawRectangle(mx2, my, mx2 + BOARD_LINE_WIDTH, SCREEN_HEIGHT - 1, "blue");
    for(int i = BOARD_POSITION - (BOARD_WIDTH / 2) - 1; i < BOARD_POSITION + (BOARD_WIDTH / 2)+1; i++){
        terminal_color(color_from_name("blue"));
        terminal_put(i, 24, 0x2588);
    }
    //mx1 += 1;

    for (int i = 0; i < BOARD_WIDTH; i++){
        for(int j = 0; j < BOARD_HEIGHT; j++){
            if (!isFreeBlock(theBoard, i, j)){
                terminal_color(color_from_name("red"));
                terminal_put(mx1 + i, my+ j-1, 0x2588);
            }
        }
    }
}

void drawScene(Board *theBoard, Game *theGame){
    drawBoard(theBoard, theGame);
    drawPiece(theGame->mXloc, theGame->mYloc, theGame->mPiece, theGame->mRot);
    drawPiece(theGame->nextX, theGame->nextY, theGame->nextP, theGame->nextRot);
}
