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
    int m_line;
    int m_column;

public:
    Coordinates(int line, int column);
    Coordinates();
    ~Coordinates();
    int getColumn();
    int getLine();
    void setLine();
    void setColumn();
    void move(Direction dir);

}

#endif // COORDINATES_H
