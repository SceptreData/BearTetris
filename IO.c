#include "IO.h"

uint64_t getTime(void)
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec*1000 + t.tv_usec/1000;
}

void drawRectangle(int x0, int y0, int x1, int y1, char *color_s)
{
    terminal_color(color_from_name(color_s));
    for (int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            terminal_put( i, j, 0x2588);
        }
    }
}

void clearScreen(void)
{
    terminal_clear( BOARD_POSITION - (BOARD_WIDTH / 2), 
                    SCREEN_HEIGHT - BOARD_HEIGHT, 
                    BOARD_WIDTH, BOARD_HEIGHT);
}

void handleInput(int code, Board *theBoard, Game *theGame)
{
    if (code == TK_RIGHT){
        if ( movePossible( theBoard, theGame->mXloc + 1, theGame->mYloc, theGame->mPiece, theGame->mRot)){
            theGame->mXloc++;
        }
    }
    if (code == TK_LEFT){
        if ( movePossible( theBoard, theGame->mXloc - 1, theGame->mYloc, theGame->mPiece, theGame->mRot)){
            theGame->mXloc--;
        }
    }
    if (code == TK_DOWN){
        if ( movePossible( theBoard, theGame->mXloc, theGame->mYloc + 1, theGame->mPiece, theGame->mRot)){
            theGame->mYloc++;
        }
    }

    if(code == TK_X){
        while(movePossible(theBoard, theGame->mXloc, theGame->mYloc, theGame->mPiece, theGame->mRot)){
            theGame->mYloc++;
        }
        storePiece( theBoard, theGame->mXloc, theGame->mYloc - 1, theGame->mPiece, theGame->mRot);
        deletePossibleLines(theBoard);
        if(isGameOver(theBoard)){
            printf("Game Over!");
            exit(0);
        }
        newPiece(theGame);
    }
    
    if (code == TK_Z){
        if(movePossible(theBoard,theGame->mXloc, theGame->mYloc, theGame->mPiece, 
          (theGame->mRot + 1) % 4)){
            theGame->mRot = (theGame->mRot + 1) % 4;
        }
    }
}

