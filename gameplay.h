#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include<windows.h>
#include<conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define SPACE 32
#define F 102
#include<iostream>
#include<queue>
#include"Point.h"
#include"replay.h"

class gamePlay{
    std::queue<replay> history;
    replay rep;
    Point m_playerMove;
public:
    gamePlay(Point move = Null);
    void GotoXY( int x, int y);
    void addMoveToHistory(const int& x,const int& y, const char& c);
    void watchReplay();
    void printStatus(int const &x, int const &y,const Point &point);
    void playerPlayXO(int &x, int &y, Point &point, std::vector<std::vector<char>> &board);
    bool winCheck(const int &x, const int &y,const std::vector<std::vector<char>> &board);
    bool drawCheck(const std::vector<std::vector<char>> &board);
    bool winCheckRow(const int &x, const int &y,const std::vector<std::vector<char>> &board);
    bool winCheckColumn(const int &x, const int &y,const std::vector<std::vector<char>> &board);
    bool winCheckTopLeftToRightBot(const int &x, const int &y,const std::vector<std::vector<char>> &board);
    bool winCheckTopRightToLeftBot(const int &x, const int &y,const std::vector<std::vector<char>> &board);
};


#endif // GAMEPLAY_H
