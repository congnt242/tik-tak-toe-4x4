#include "board.h"

/*
*constructor Board in ra ban co
*/
Board::Board(int posX, int posY, int size)
    :m_positionX(posX),m_postitionY(posY),m_size(size)
{
    std::cout<<"Player 1 <X> - Player 2 <Y>"<< " Using SPACE and F from keyboard to play.\n";

    std::vector<std::vector<char>>board(m_size,std::vector<char>(m_size));
    for (int i = 0; i<m_size; i++){
        std::cout<<"\n";
        for(int j = 0; j<m_size; j++){
            board[i][j] = ' ';
            std::cout<<"| "<<board[i][j]<<" ";

        }std::cout<<"|\n";
        for(int m= 0; m <m_size;m++)
            std::cout<<"----";
    }std::cout<<"\n";

}
/*
* ham playGame co tac dung di chuyen cursor, danh X,O
*/
void Board::playGame(){
    Point turn = Null;

    std::vector<std::vector<char>>board(m_size,std::vector<char>(m_size));
    for (int i = 0; i<m_size; i++){
        std::cout<<"\n";
        for(int j = 0; j<m_size; j++){
            board[i][j] = ' ';}}

    while(playerMove.winCheck(m_positionX,m_postitionY,board)&&playerMove.drawCheck(board)){
        playerMove.GotoXY(m_positionX,m_postitionY);

        playerMove.playerPlayXO(m_positionX,m_postitionY, turn,board);
    }
    std::cout<<"\nThe game is replaying now!";
    Sleep(3000);
    playerMove.watchReplay();
}

