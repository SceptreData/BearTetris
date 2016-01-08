#include "tetris.h"

bool isFreeBlock(Board *theBoard, int x, int y)
{
    if ( theBoard->bGrid[x][y] == POS_FREE)
        return true;
    return false;
}

void getPiecePosition( int pX, int pY ,int *xLoc, int *yLoc )
{
    *xLoc = (( BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)))+ (pX * BLOCK_SIZE));
    *yLoc = (( SCREEN_HEIGHT - (BLOCK_SIZE * BOARD_HEIGHT)) + (pY * BLOCK_SIZE) );
}

bool movePossible(Board *theBoard, int x, int y, int thePiece, int pRotation)
{
    for (int i1 = x, i0 = 0; i1 < x + PIECE_BLOCKS; i1++, i0++){
        for(int j1 = y, j0 = 0; j1 < y + PIECE_BLOCKS; j1++, j0++){
            // Bounds check.
            if ( i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 >= BOARD_HEIGHT - 1){
                if( getBlockType(thePiece, pRotation, j0, i0) != 0){
                    return 0;
                }
            }
            // COLLISION CHECK.
            if (j1 >= 0){
                    if( getBlockType(thePiece, pRotation, j0, i0) != 0 &&
                        (!isFreeBlock(theBoard, i1, j1 + 1))){
                        return false;
                    }
            }
        }
    }
    return true;
}

void storePiece(Board *theBoard, int x, int y, int thePiece, int pRotation)
{
    int i0, i1;
    int j0, j1;
    int total = 0;
    for(i0 = 0, i1 = x; i1 < x + PIECE_BLOCKS; i0++, i1++){
        for(j0 = 0, j1 = y; j1 < y + PIECE_BLOCKS; j0++, j1++){
            //Store only parts of block that aren't holes.
            if( getBlockType(thePiece, pRotation, j0, i0) != 0){
                theBoard->bGrid[i1][j1+1] = POS_FILLED;
                total++;
            }
        }
    }
    if(total != 4){
        printf("STORING TOO MUCH! Total = %d", total);
        exit(1);
    }
}

void deletePossibleLines(Board *theBoard)
{
    int i,j;
    for ( j = 0; j < BOARD_HEIGHT; j++){
        i = 0;
        while (i < BOARD_WIDTH){
            if( theBoard->bGrid[i][j] != POS_FILLED) break;
            i++;
        }
        if (i == BOARD_WIDTH){
             deleteLine( theBoard, j );
             theBoard->score++;
        }
    }
}

bool isGameOver(Board *theBoard)
{
    for (int i = 0; i < BOARD_WIDTH; i++){
        if (theBoard->bGrid[i][0] == POS_FILLED) return true;
    }
    return false;
}

void initBoard(Board *theBoard)
{
    for(int i = 0; i < BOARD_WIDTH; i++){
        for(int j = 0; j < BOARD_HEIGHT; j++){
            theBoard->bGrid[i][j] = 0;
        }
    }
    theBoard->score = 0;
}

void deleteLine(Board *theBoard, int yLoc )
{
    for (int j = yLoc; j > 0; j--){
        for (int i = 0; i < BOARD_WIDTH; i++){
            theBoard->bGrid[i][j] = theBoard->bGrid[i][j-1];
        }
    }
}

