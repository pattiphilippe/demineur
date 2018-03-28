#include "Coordinates.h"
#include "GameException.h"

using namespace std;

/**
 * @brief Coordinates::Coordinates
 * Coordinates with set value
 * @param line int line of the coordinates
 * @param column int column of the coordinates
 */
Coordinates::Coordinates(int line, int column)
{
    c_line = line ;
    c_column = column ;
}


/**
 * @brief Coordinates::move
 * Moves the coordinate in a given direction
 * @param dir Enum of direction
 */
Coordinates Coordinates::move(Direction dir) const
{
    int line{c_line}, column{c_column};
    switch (dir) {
    case N:
        line++;
        break;
    case NE:
        line ++;
        column++;
        break;
    case E:
        column++;
        break;
    case SE:
        line--;
        column++;
        break;
    case S:
        line--;
        break;
    case SO:
        line --;
        column--;
        break;
    case O:
        column--;
        break;
    case NO:
        line++;
        column--;
        break;
    default:
        throw GameException("Unknown direction!");
    }
    return Coordinates(line, column);
}
