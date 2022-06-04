#include "gameplay.h"

gamePlay::gamePlay(Point move):
    m_playerMove(move)
{


}
//ham di chuyen con tro
void gamePlay::GotoXY( int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}

void gamePlay::playerPlayXO(int &x, int &y, Point &point,  std::vector<std::vector<char>> &board){
    //    printStatus(point);
    int i = 0;//index chieu doc
    int j = 0;//index chieu ngang
    j = (x - 2)/4;
    i =( y- 2)/2;
    //dieu huong len xuong trai phai danh x,o
    char keyPress = getch();
    if(keyPress==KEY_UP){
        y-=2;
        GotoXY(x,y);

    }
    else if(keyPress==KEY_DOWN){
        y+=2;
        GotoXY(x,y);

    }else if(keyPress==KEY_LEFT){
        x-=4;
        GotoXY(x,y);

    }else if(keyPress==KEY_RIGHT){
        x+=4;
        GotoXY(x,y);


    }
    //danh x,o. Chi danh vao o chua co ai dien vao
    if((point == Null)&&(keyPress==SPACE)&&(board[i][j]!='X')&&(board[i][j]!='O')){
        std::cout<<"X";
        addMoveToHistory(x,y,X);
        point = O;
        printStatus(x,y,point);
        board[i][j]='X';

        winCheck(x,y,board);
    }
    if((point == X)&&(keyPress==SPACE)&&((board[i][j]!='X')&&(board[i][j]!='O'))){
        std::cout<<"X";
        addMoveToHistory(x,y,point);
        point = O;
        printStatus(x,y,point);
        board[i][j]='X';

        winCheck(x,y,board);
    }if((point==O)&&(keyPress==F)&&((board[i][j]!='X')&&(board[i][j]!='O'))){
        std::cout<<"O";
        addMoveToHistory(x,y,point);
        point = X;
        printStatus(x,y,point);
        board[i][j] = 'O';

        winCheck(x,y,board);

    }
}
void gamePlay::addMoveToHistory(const int& x,const int& y, const char& c){
    rep.setPositionX(x);
    rep.setPositionY(y);
    rep.setPoint(c);
    history.push(rep);
}
void gamePlay::watchReplay(){
    std::queue<replay> tempHistory(history);
    GotoXY(0,0);
    std::cout<<"Player 1 <X> - Player 2 <Y>"<< " Using SPACE and F from keyboard to play.\n";
    for (int i = 0; i<10; i++){
        std::cout<<"\n";
        for(int j = 0; j<10; j++){
            std::cout<<"| "<<"  ";
        }std::cout<<"|\n";
        for(int m= 0; m <10;m++)
            std::cout<<"----";
    }std::cout<<"\n";

    while(!tempHistory.empty()){
        replay temp = tempHistory.front();
        GotoXY(temp.getPositionX(),temp.getPositionY());
        if(temp.getPoint()==X)
            std::cout<<"X";
        else
            std::cout<<"O";
        tempHistory.pop();
        Sleep(2000);
    };
    GotoXY(1,30);
}
// in ra luot choi cua nguoi choi
void gamePlay::printStatus(int const &x, int const &y,const Point &point){
    GotoXY(3,30);
    //    std::cout<<"Use key SPACE and F to play.";
    if((point == X)||(point == Null)){
        std::cout<<"Player X turn, press SPACE to play!";
    }
    if(point == O){
        std::cout<<"Player O turn, press F to play!";
    }
    GotoXY(x,y);
}
//kiem tra game da co nguoi thang chua
bool gamePlay::winCheck(const int &x, const int &y, const std::vector<std::vector<char> > &board){
    return winCheckRow(x,y,board)&&winCheckColumn(x,y,board)&&winCheckTopLeftToRightBot(x,y,board)&&winCheckTopRightToLeftBot(x,y,board);
}

bool gamePlay::drawCheck(const std::vector<std::vector<char> > &board){
    int count = 0;
    int size = board.size();
    for(int i = 0; i<size; i++)
        for(int j = 0; j< size; j++)
            if((board[i][j] == 'X')||(board[i][j]=='O'))
                count++;

    if(count == 100){

        GotoXY(2,30);
        std::cout<<"Game draw!!!";
        return false;}
    else
        return true;

}


//co che kiem tra win:
// xet diem vua danh, kiem tra 3 diem xung quanh co thoa man khong theo 4 huong doc, ngang, trai, phai.
//kiem tra hang doc
bool gamePlay::winCheckColumn(const int &x, const int &y, const std::vector<std::vector<char> >  &board){
    int i = 0;//index chieu doc
    int j = 0;//index chieu ngang
    j = (x - 2)/4;
    i = (y- 2)/2;
    if(board[i][j]=='X'){
        //check win theo hang doc
        if( (i<=7) && (board[i+1][j]=='X') ){
            if (board[i+2][j]=='X' ){
                if(board[i+3][j]=='X'){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;

                }
                else if((i>=1)&&(board[i-1][j]=='X'))
                { GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }
                else
                    return true;
            }
            else if((i>=2) && (board[i-1][j]=='X')){
                if(board[i-2][j]=='X'){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }
                else{return true;}
            }
            else
                return true;
        }else if( (i>=3) && (board[i-1][j]=='X') ){
            if(board[i-2][j]=='X' ){
                if(board[i-3][j]=='X' ){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else
            return true;
    }
    else if(board[i][j]=='O'){

        if((i<=7) && (board[i+1][j]=='O')){
            if(board[i+2][j]=='O'){
                if(board[i+3][j]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;

                }else if((i>=1) && (board[i-1][j]=='O')){ GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;}
                else
                    return true;
            }else if((i>=2) && (board[i-1][j]=='O')){
                if(board[i-2][j]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else if((i>=3) && (board[i-1][j]=='O')){
            if(board[i-2][j]=='O'){
                if(board[i-3][j]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else
            return true;
    }



    return true;
}
//kiem tra hang ngang
bool gamePlay::winCheckRow(const int &x, const int &y, const std::vector<std::vector<char> > &board){
    int i = 0;//index chieu doc
    int j = 0;//index chieu ngang
    j = (x - 2)/4;
    i = (y- 2)/2;
    if(board[i][j]=='X'){
        //check win theo hang doc
        if( (j<=7) && (board[i][j+1]=='X') ){
            if (board[i][j+2]=='X' ){
                if(board[i][j+3]=='X'){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;

                }
                else if((j>=1)&&(board[i][j-1]=='X'))
                { GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }
                else
                    return true;
            }
            else if((j>=2) && (board[i][j-1]=='X')){
                if(board[i][j-2]=='X'){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }
                else{return true;}
            }
            else
                return true;
        }else if( (j>=3) && (board[i][j-1]=='X') ){
            if(board[i][j-2]=='X' ){
                if(board[i][j-3]=='X' ){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else
            return true;
    }
    else if(board[i][j]=='O'){

        if((j<=7) && (board[i][j+1]=='O')){
            if(board[i][j+2]=='O'){
                if(board[i][j+3]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;

                }else if((j>=1) && (board[i][j-1]=='O')){ GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;}
                else
                    return true;
            }else if((j>=2) && (board[i][j-1]=='O')){
                if(board[i][j-2]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else if((j>=3) && (board[i][j-1]=='O')){
            if(board[i][j-2]=='O'){
                if(board[i][j-3]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else
            return true;
    }
    return true;
}
//kiem tra duong cheo tu goc trai qua phai
bool gamePlay::winCheckTopLeftToRightBot(const int &x, const int &y, const std::vector<std::vector<char> > &board){
    int i = 0;//index chieu doc
    int j = 0;//index chieu ngang
    j = (x - 2)/4;
    i = (y- 2)/2;
    if(board[i][j]=='X'){
        //check win theo hang doc
        if( (i<=7) && (j<=7) && (board[i+1][j+1]=='X') ){
            if (board[i+2][j+2]=='X' ){
                if(board[i+3][j+3]=='X'){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;

                }
                else if((i>=1)&&(j>=1)&&(board[i-1][j-1]=='X'))
                { GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }
                else
                    return true;
            }
            else if((i>=2)&&(j>=2) && (board[i-1][j-1]=='X')){
                if(board[i-2][j-2]=='X'){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }
                else{return true;}
            }
            else
                return true;
        }else if( (i>=3)&&(j>=3) && (board[i-1][j-1]=='X') ){
            if(board[i-2][j-2]=='X' ){
                if(board[i-3][j-3]=='X' ){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else
            return true;
    }
    else if(board[i][j]=='O'){

        if((i<=7)&&(j<=7) && (board[i+1][j+1]=='O')){
            if(board[i+2][j+2]=='O'){
                if(board[i+3][j+2]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;

                }else if((i>=1)&&(j>=1) && (board[i-1][j-1]=='O')){ GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;}
                else
                    return true;
            }else if((i>=2)&&(j>=2) && (board[i-1][j-1]=='O')){
                if(board[i-2][j-2]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else if((i>=3)&&(j>=3) && (board[i-1][j-1]=='O')){
            if(board[i-2][j-2]=='O'){
                if(board[i-3][j-3]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else
            return true;
    }



    return true;
}
//kiem tra duong cheo tu goc phai qua trai
bool gamePlay::winCheckTopRightToLeftBot(const int &x, const int &y, const std::vector<std::vector<char> > &board){
    int i = 0;//index chieu doc
    int j = 0;//index chieu ngang
    j = (x - 2)/4;
    i = (y- 2)/2;
    if(board[i][j]=='X'){
        //check win theo hang doc
        if( (i<=7) &&(j>=3) && (board[i+1][j-1]=='X') ){
            if (board[i+2][j-2]=='X' ){
                if(board[i+3][j-3]=='X'){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;

                }
                else if((i>=1) &&(j<=9)&&(board[i-1][j+1]=='X'))
                { GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }
                else
                    return true;
            }
            else if((i>=2) &&(j<=8) && (board[i-1][j+1]=='X')){
                if(board[i-1][j+1]=='X'){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }
                else{return true;}
            }
            else
                return true;
        }else if( (i>=3) &&(j<=7) && (board[i-1][j+1]=='X') ){
            if(board[i-2][j+2]=='X' ){
                if(board[i-3][j+3]=='X' ){
                    GotoXY(3,40);
                    std::cout<<"Player X win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else
            return true;
    }
    else if(board[i][j]=='O'){

        if((i<=7) && (j>=3) && (board[i+1][j+1]=='O')){
            if(board[i+2][j+2]=='O'){
                if(board[i+3][j+3]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;

                }else if((i>=1) &&(j<=9) && (board[i-1][j+1]=='O')){ GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;}
                else
                    return true;
            }else if((i>=2) &&(j<=8) && (board[i-1][j+1]=='O')){
                if(board[i-2][j+2]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else if((i>=3) &&(j<=7) && (board[i-1][j+1]=='O')){
            if(board[i-2][j+2]=='O'){
                if(board[i-3][j+3]=='O'){
                    GotoXY(3,40);
                    std::cout<<"Player O win!";
                    return false;
                }else{return true;}
            }
            else
                return true;
        }else
            return true;
    }
    return true;
}
