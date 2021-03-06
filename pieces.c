#include "pieces.h"


// 7 Kinds, Four Rotations, Five by Five row.

char pieceList[7][4][5][5] = 
{
    //Square
    {
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,2,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,2,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {

            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,2,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,2,1,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        }
    },
    // Straight
    {
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,1,2,1,1},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,0,2,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0}
        },
        {

            {0,0,0,0,0},
            {0,0,0,0,0},
            {1,1,2,1,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,2,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        }
    },
    // L 
    {
        {
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,0,2,0,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,1,2,1,0},
            {0,1,0,0,0},
            {0,0,0,0,0}
        },
        {

            {0,0,0,0,0},
            {0,1,1,0,0},
            {0,0,2,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,1,0},
            {0,1,2,1,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        }
    },
    // L Mirrored
    {
        {
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,0,2,0,0},
            {0,1,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,1,0,0,0},
            {0,1,2,1,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {

            {0,0,0,0,0},
            {0,0,1,1,0},
            {0,0,2,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,1,2,1,0},
            {0,0,0,1,0},
            {0,0,0,0,0}
        }
    },
    // N
    {
        {
            {0,0,0,0,0},
            {0,0,0,1,0},
            {0,0,2,1,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,1,2,0,0},
            {0,0,1,1,0},
            {0,0,0,0,0}
        },
        {

            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,1,2,0,0},
            {0,1,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,1,1,0,0},
            {0,0,2,1,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        }
    },
    // N-Mirrored
    {
        {
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,0,2,1,0},
            {0,0,0,1,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,2,1,0},
            {0,1,1,0,0},
            {0,0,0,0,0}
        },
        {

            {0,0,0,0,0},
            {0,1,0,0,0},
            {0,1,2,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,1,1,0},
            {0,1,2,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        }
    },
    // T
    {
        {
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,0,2,1,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,1,2,1,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {

            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,1,2,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,1,2,1,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        }
    }
};

// Seven Shapes, Four rotations.

int pStartList[7][4][2] = 
{
    // Square
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -3}
    },
    // Straight
    {
        {-2, -2},
        {-2, -3},
        {-2, -2},
        {-2, -3}
    },
    //L
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
    },
    //Mirrored-L
    {
        {-2, -3},
        {-2, -2},
        {-2, -3},
        {-2, -3}
    },
    //N
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
    },
    // Mirrored N
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
    },
    // T
    {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
    }
};

int getBlockType(int newPiece, int pRotation, int px, int py){
    return pieceList[newPiece][pRotation][px][py];
}

void getStartPos(int newPiece, int pRotation, int *newX, int *newY){
    *newX = pStartList[newPiece][pRotation][0];
    *newY = pStartList[newPiece][pRotation][1];
};

