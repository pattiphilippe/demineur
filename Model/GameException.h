#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include "string"
#include "exception"

using namespace std;

/**
 * @brief Exception of the game
 * Exception throwed when the game rules aren't followed.
*/
class GameException : public exception{
private:
    string message_;
public:
    inline GameException(const string& message);
    inline virtual const char* what() const throw();
};

/**
 * @brief GameException(message)
 * Creates a new Exception with a message describing the error.
 * @param message the error's description
*/
GameException::GameException(const string &message):
    message_{message}
{}

/**
 * @brief Describes the error
 * Return a char* with a description of the error
*/
const char* GameException::what() const throw(){
    return message_.c_str();
}

#endif // GAMEEXCEPTION_H
