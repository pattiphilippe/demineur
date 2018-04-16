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

enum TypeOfCustom{
    LINESANDCOLUMNS,
    NBBOMBS,
    DENSITYBOMBS,
};

Command readCommand();
TypeOfCustom readCustom();
int readInt(string const & msg);
double readDouble(string const & msg);
bool readBoolean(string const & msg);
int readIntBetween(int, int, string const & msg) ;
string readString(string const & msg);

#endif // CONSOLEREAD_H
