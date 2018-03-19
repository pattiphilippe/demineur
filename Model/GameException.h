#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include "string"
#include "exception"

using namespace std;

class GameException : public exception{
private:
    string message_;
public:
    inline GameException(const string& message);
    inline virtual const char* what() const throw();
};

GameException::GameException(const string &message):
    message_{message}
{}

const char* GameException::what() const throw(){
    return message_.c_str();
}

#endif // GAMEEXCEPTION_H
