#include <iostream>
#include <IO.h>
#include <time.h>

using namespace std;

#define _PIECES_
#define _BOARD_
#define BOARD_LINE_WIDTH 6
#define BLOCK_SIZE 16
#define BOARD_POSITION 320
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define MIN_VERTICAL_MARGIN 20
#define MIN_HORIZONTAL_MARGIN 20
#define PIECE_BLOCKS 5
#define _GAME_
#define WAIT_TIME 700

// The basic shapes. 7 shapes, 4 rotations, in a 5x5 matrix
char pieces[7][4][5][5] =
        {
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 2, 1, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 2, 1, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 2, 1, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 2, 1, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        }},
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 2, 1, 1},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 2, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {1, 1, 2, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 2, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        }
                },
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 2, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 2, 1, 0},
                                {0, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 2, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 1, 0},
                                {0, 1, 2, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        }
                },
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 2, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0},
                                {0, 1, 2, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 2, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 2, 1, 0},
                                {0, 0, 0, 1, 0},
                                {0, 0, 0, 0, 0}
                        }
                },
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 1, 0},
                                {0, 0, 2, 1, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 2, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 1, 2, 0, 0},
                                {0, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        },


                        {
                                {0, 0, 0, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 2, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        }
                },
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 2, 1, 0},
                                {0, 0, 0, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 2, 1, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0},
                                {0, 1, 2, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 1, 2, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        }
                },
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 2, 1, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 2, 1, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 1, 2, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 1, 2, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        }
                }
        };

// keep initial positions so that pieces start at very top, otherwise they will start a bit lower. first row is zeroes in the shapes matrix
int initialPositions  [7][4][2] =
        {
                {
                        {-2, -3},
                        {-2, -3},
                        {-2, -3},
                        {-2, -3}
                },
                {
                        {-2, -2},
                        {-2, -3},
                        {-2, -2},
                        {-2, -3}
                },
                {
                        {-2, -3},
                        {-2, -3},
                        {-2, -3},
                        {-2, -2}
                },
                {
                        {-2, -3},
                        {-2, -2},
                        {-2, -3},
                        {-2, -3}
                },
                {
                        {-2, -3},
                        {-2, -3},
                        {-2, -3},
                        {-2, -2}
                },
                {
                        {-2, -3},
                        {-2, -3},
                        {-2, -3},
                        {-2, -2}
                },
                {
                        {-2, -3},
                        {-2, -3},
                        {-2, -3},
                        {-2, -2}
                },
        };


class Pieces{
public:
    int getType (int piece, int r, int pX, int pY);
    int getInitialX (int piece, int r);
    int getInitialY (int piece, int r);
};

int Pieces::getType(int piece, int r, int pX, int pY) {
    return pieces[piece][r][pX][pY];
}

int Pieces::getInitialX(int piece, int r) {
    return initialPositions[piece][r][0];
}

int Pieces::getInitialY(int piece, int r) {
    return initialPositions[piece][r][1];
}



class Board{
public:
    Board(Pieces *pPieaces, int screenHeight);
    int getXinPxls(int pos);
    int getYinPxls(int pos);
    bool isFree(int pX, int pY);
    bool isPossible(int pX, int pY, int pPiece, int pR);
    void storePiece(int pX, int pY, int pPiece, int pR);
    void deletePossibleLines();
    bool isGameOver();

private:
    enum {POS_FREE, POS_FILLED};
    int mBoard [BOARD_WIDTH][BOARD_HEIGHT];
    Pieces *mPieces;
    int screenHeight;

    void initBoard();
    void deleteLine(int pY);
};

void Board::initBoard() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            mBoard[i][j] = POS_FREE;
        }
    }
}

void Board::storePiece(int pX, int pY, int pPiece, int pR) {
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
            if (mPieces->getType(pPiece,pR,j2,i2) != 0){
                mBoard[i1][j1] == POS_FILLED;
            }
        }
    }
}

bool Board::isGameOver() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        if (mBoard[i][0] == POS_FILLED){
            return true;
        }
    }
    return false;
}

void Board::deleteLine(int pY) {
    for (int j = pY; j > 0; j++) {
        for (int i = 0; i < BOARD_WIDTH; i++) {
            mBoard[i][j] = mBoard[i][j-1];
        }
    }
}

void Board::deletePossibleLines() {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
        int i = 0;
        while (i<BOARD_WIDTH){
            if (mBoard[i][j] != POS_FILLED){
                break;
            }
        }
        if (i == BOARD_WIDTH){
            deleteLine(j);
        }
    }
}

bool Board::isFree(int pX, int pY) {
    if (mBoard[pX][pY] == POS_FREE){
        return true;
    }
    return false;
}

int Board::getXinPxls(int pos) {
    return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pos * BLOCK_SIZE));
}

int Board::getYinPxls(int pos) {
    return ((screenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pos * BLOCK_SIZE));
}

bool Board::isPossible(int pX, int pY, int pPiece, int pR) {
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
            if (i1 < 0 || i1 > BOARD_WIDTH  - 1 || j1 > BOARD_HEIGHT - 1)
            {
                if (mPieces->getType(pPiece, pR, j2, i2) != 0) {
                    return false;
                    //return 0;
                }
            }
            if (j1 >= 0)
            {
                if ((mPieces->getType (pPiece, pR, j2, i2) != 0) && (!isFree (i1, j1)) ) {
                    return false;
                }
            }
        }
    }
    return true;
}

//Need further implementation of class Game and functions
//Coloring the shapes not implemented
// main loop not implemented yet
class Game{
    Game(Board *pBoard, Pieces *pPieces, IO *pIO, int screenHeight);
};





int main() {




    cout << "Hello, World!" << endl;
    return 0;
}
