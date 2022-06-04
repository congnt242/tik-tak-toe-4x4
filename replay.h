#ifndef REPLAY_H
#define REPLAY_H


class replay
{
    int positionX;
    int positionY;
    char point;
public:
    replay(int posX = 2, int posY = 2, char ppoint = ' ');

    int getPositionX() const;
    void setPositionX(int value);
    int getPositionY() const;
    void setPositionY(int value);
    char getPoint() const;
    void setPoint(char value);
};

#endif // REPLAY_H
