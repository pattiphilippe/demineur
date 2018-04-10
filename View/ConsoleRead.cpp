#include "View/ConsoleRead.h"
#include "Libraries/keyboardAndStringConvert/keyboard.hpp"
#include <algorithm>
#include "Libraries/keyboardAndStringConvert/stringConvert.hpp"

using namespace std;

int readInt(string const & msg, string const & errorMsg){
    cout << msg << endl;
    int nb;
    bool error {true};
    do{
        try
        {
            nb = nvs::lineFromKbd<int>();
            error = false;
        }
        catch (const exception & e)
        {
            cout << "Error : " << e.what() << endl;
            cout << errorMsg << endl;
        }
    } while (error);
    return nb;
}

int readIntBetween(int nb1, int nb2, string const & msg, string const & errorMsg) {
    int nb, min = nb1 < nb2 ? nb1 : nb2, max = min == nb1 ? nb2 : nb1;
    do{
        nb = readInt(msg, errorMsg);
    } while(nb < min || max < nb);
    return nb;
}

Command readCommand(){
    do{
        string s = nvs::lineFromKbd<string>();
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        if(s == "start" || s == "s"){
            return START;
        } else if(s == "custom" || s == "c"){
            return CUSTOM;
        } else if(s == "scores" || s == "sc"){
            return SCORES;
        } else if(s == "mark" || s == "m"){
            return MARK;
        } else if(s == "reveal" || s == "r"){
            return REVEAL;
        } else if(s == "help" || s == "h"){
            return HELP;
        } else if(s == "exit" || s == "x"){
            return EXIT;
        } else {
            cout << "Wrong command! Enter one of the following : "<< endl;
            cout << "start (s), custom (c), scores (sc), mark (m), reveal (r), help (h), exit (x)." << endl;
        }
    } while (true); //No value returned
}

