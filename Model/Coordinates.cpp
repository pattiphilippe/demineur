#include "Coordinates.h"

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

/**
 * @brief Coordinates::getLine
 * Return an Integer , line of coordinates
 */
Coordinates::getLine()
{
    return m_line ;
}

/**
 * @brief Coordinates::getColumn
 * Return an Integer, column of coordinates
 */
Coordinates::getColumn()
{
    return m_column ;
}

/**
 * @brief Coordinates::setLine
 * Set the line of coordinate
 * @param line, int line of coordinates
 */
Coordinates::setLine(int line)
{
    m_line = line ;
}

/**
 * @brief Coordinates::setColumn
 * Set column of coordinate
 * @param column int of coordinates
 */
Coordinates::setColumn(int column)
{
    m_column = column ;
}

/**
 * @brief Coordinates::move
 * Moves the coordinate in a given direction
 * @param dir Enum of direction
 */
Coordinates::move(Direction dir)
{
    switch (dir) {
    case N:
        m_line -=1 ;
        break;

    case NE:
        m_line -=1 ;
        m_column +=1 ;
        break;

    case E:
        m_column +=1 ;
        break;

    case SE:
        m_line +=1 ;
        m_column +=1 ;
        break;

    case S:
        m_line +=1 ;
        break;

    case SO:
        m_line +=1 ;
        m_column -=1 ;
        break;

    case O:
        m_column -=1 ;
        break;

    case NO:
        m_line -=1 ;
        m_column -=1 ;
        break;

    default:
        break;
    }
}
