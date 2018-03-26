#ifndef COORDINATES_H
#define COORDINATES_H

/**
 * @brief Direction enum
 * Describe the eight principal direction in a board
 */
enum Direction{
    N, NE, E, SE, S, SO, O, NO, Last
};

class Coordinates {
private:
    int c_line;
    int c_column;

public:
    Coordinates(int line, int column);
    inline int getColumn() const;
    inline int getLine() const;
    Coordinates move(Direction dir);
};

//TODO documenter le tout

/**
 * @brief Coordinates::getLine
 * Return an Integer , line of coordinates
 */
int Coordinates::getLine() const{
    return c_line;
}

/**
 * @brief Coordinates::getColumn
 * Return an Integer, column of coordinates
 */
int Coordinates::getColumn() const{
    return c_column;
}

#endif // COORDINATES_H
