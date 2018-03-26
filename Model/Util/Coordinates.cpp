#include "Coordinates.h"
#include "GameException.h"

using namespace std;

int m_line ;
int m_column ;

/**
 * @brief Coordinates::Coordinates
 * Constructor of coordinates, set line and column to 0
 */
Coordinates::Coordinates()
{
    m_line = 0 ;
    m_column = 0;
}

/**
 * @brief Coordinates::Coordinates
 * Coordinates with set value
 * @param line int line of the coordinates
 * @param column int column of the coordinates
 */
Coordinates::Coordinates(int line, int column)
{
    m_line = line ;
    m_column = column ;
}

Coordinates::getLine()
{
    return m_line ;
}

Coordinates::getColumn()
{
    return m_column ;
}

/**
 * @brief Coordinates::move
 * Moves the coordinate in a given direction
 * @param dir Enum of direction
 */
Coordinates Coordinates::move(Direction dir)
{
    //TODO à tester
    int line{c_line}, column{c_column};
    switch (dir) {
    case N: case NE: case NO:
        line--;
        break;
    case S: case SE: case SO:
        line++;
        break;
    case E: case NE: case SE:
        column++;
        break;
    case O: case NO: case SO:
        column--;
        break;
    default:
        throw GameException("Unknown direction!");
    }
        /*
    case NE:
        newLine -=1 ;
        newColumn +=1 ;
        break;

    case E:
        newColumn +=1 ;
        break;

    case SE:
        newLine +=1 ;
        newColumn +=1 ;
        break;

    case S:
        newLine +=1 ;
        break;

    case SO:
        newLine +=1 ;
        newColumn -=1 ;
        break;

    case O:
        newColumn -=1 ;
        break;

    case NO:
        newLine -=1 ;
        newColumn -=1 ;
        break;
        */
    return Coordinates(line, column);
}
