#ifndef N1041_ROBOT_BOUNDED_IN_CIRCLE_H
#define N1041_ROBOT_BOUNDED_IN_CIRCLE_H

#include "bits/stdc++.h"
using namespace std;


namespace n1041
{

typedef enum
{
    NORTH,
    EAST,
    SOUTH,
    WEST,
    DIR_NUM,
} Direction;

class Position
{
public:
    Position(int x = 0, int y = 0):
        x(x), y(y), direction(NORTH)
    {
    }

    bool isAtOrigin()
    {
        return x == 0 && y == 0;
    }

    void initPosition()
    {
        x = 0;
        y = 0;
        direction = NORTH;
    }

protected:
    int x;
    int y;
    Direction direction;
};

class Solution: public Position
{
public:
    bool isRobotBounded(string instructions)
    {
        initPosition();
        procInstructions(instructions);
        if (direction == SOUTH)
        {
            procInstructions(instructions);
        }
        else if (direction == WEST || direction == EAST)
        {
            procInstructions(instructions);
            procInstructions(instructions);
            procInstructions(instructions);
        }
        return isAtOrigin();
    }

private:
    void procInstructions(const string &instructions)
    {
        for (char command : instructions)
        {
            if (command == 'G')
            {
                goStraight();
            }
            else if (command == 'L')
            {
                turnLeft();
            }
            else if (command == 'R')
            {
                turnRight();
            }
        }

    }

    void turnLeft()
    {
        direction = static_cast<Direction>((direction + DIR_NUM - 1) % DIR_NUM);
    }

    void turnRight()
    {
        direction = static_cast<Direction>((direction + 1) % DIR_NUM);
    }

    void goStraight()
    {
        switch (direction)
        {
            case NORTH:
            {
                y++;
                break;
            }
            case EAST:
            {
                x++;
                break;
            }
            case SOUTH:
            {
                y--;
                break;
            }
            case WEST:
            {
                x--;
                break;
            }
            default:
            {
            }
        }
    }
};



}

#endif // N1041_ROBOT_BOUNDED_IN_CIRCLE_H
