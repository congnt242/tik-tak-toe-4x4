#include "replay.h"

int replay::getPositionX() const
{
    return positionX;
}

void replay::setPositionX(int value)
{
    positionX = value;
}

int replay::getPositionY() const
{
    return positionY;
}

void replay::setPositionY(int value)
{
    positionY = value;
}

char replay::getPoint() const
{
    return point;
}

void replay::setPoint(char value)
{
    point = value;
}

replay::replay(int posX, int posY, char ppoint):positionX(posX),positionY(posY),point(ppoint)
{

}
