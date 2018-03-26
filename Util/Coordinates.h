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
    unsigned c_line;
    unsigned c_column;

public:
    Coordinates(unsigned line, unsigned column);
    inline unsigned getColumn() const;
    inline unsigned getLine() const;
    Coordinates move(Direction dir) const;
};


/**
 * @brief Coordinates::getLine
 * Return an Integer , line of coordinates
 */
unsigned Coordinates::getLine() const{
    return c_line;
}

/**
 * @brief Coordinates::getColumn
 * Return an Integer, column of coordinates
 */
unsigned Coordinates::getColumn() const{
    return c_column;
}

#endif // COORDINATES_H
