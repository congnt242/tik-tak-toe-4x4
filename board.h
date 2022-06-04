#ifndef BOARD_H
#define BOARD_H
#include <gameplay.h>
#include"Point.h"
#define DEFAULT_SIZE 10
class Board
{
    int m_positionX;
    int m_postitionY;
    int m_size;
    gamePlay playerMove;


public:
    Board(int posX = 2, int posY =2,int size = 10);
    void playGame();



};

#endif // BOARD_H
