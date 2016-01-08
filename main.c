#include "game.h"

int main(void)
{
    Board theBoard;
    Game theGame;
    
    initGame(&theGame);
    initBoard(&theBoard);
    
    terminal_open();
    terminal_set("window.title'David's Tetris Clone!'");

    uint64_t time1 = getTime();
    int running = 1;
    int code;
    while(running){
        clearScreen();
        drawScene( &theBoard, &theGame );
        terminal_print(1, 1, "BearTetris");
        terminal_printf(1, 2,"Score: %d ", theBoard.score);

        terminal_refresh();
        while(running && terminal_has_input()){
            code = terminal_read();
            if (code == TK_CLOSE || code == TK_ESCAPE) running = 0;
            else{
                handleInput(code, &theBoard, &theGame);
            }
        }

        uint64_t time2 = getTime();

        if((time2 - time1) > WAIT_TIME){
            if(movePossible(&theBoard, theGame.mXloc, theGame.mYloc + 1, theGame.mPiece, theGame.mRot)){
                theGame.mYloc++;
            } else {
                storePiece( &theBoard, theGame.mXloc, theGame.mYloc, theGame.mPiece, theGame.mRot);
                
                deletePossibleLines(&theBoard);
                if( isGameOver(&theBoard)){
                    printf("GAME OVER! Score: %d\n", theBoard.score);
                    exit(0);
                }
                newPiece( &theGame );
            }
            time1 = getTime();
        }
    }
    terminal_close();
    return 0;
}
