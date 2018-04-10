#ifndef CONSOLEREAD_H
#define CONSOLEREAD_H
#include <string>

using namespace std;

enum Command{
    START,
    CUSTOM,
    SCORES,
    MARK,
    REVEAL,
    HELP,
    EXIT
};

Command readCommand();
int readInt(string const & msg, string const & errorMsg);
int readIntBetween(int, int, string const & msg, string const & errorMsg) ;

#endif // CONSOLEREAD_H
