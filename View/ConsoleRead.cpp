#include "View/ConsoleRead.h"
#include "Libraries/keyboardAndStringConvert/keyboard.hpp"
#include "Libraries/keyboardAndStringConvert/stringConvert.hpp"

#include <algorithm>

using namespace std;

int readInt(string const & msg){
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
            cout << "Enter a integer number!" << endl;
        }
    } while (error);
    return nb;
}

double readDouble(string const & msg){
    cout << msg << endl;
    int nb;
    bool error {true};
    do{
        try
        {
            nb = nvs::lineFromKbd<double>();
            error = false;
        }
        catch (const exception & e)
        {
            cout << "Error : " << e.what() << endl;
            cout << "Enter a double number!" << endl;
        }
    } while (error);
    return nb;
}

int readIntBetween(int nb1, int nb2, string const & msg) {
    int nb, min = nb1 < nb2 ? nb1 : nb2, max = min == nb1 ? nb2 : nb1;
    do{
        nb = readInt(msg);
        if(nb < min || max < nb){
            cout << "Enter a number between " << min << " and " << max << "!" << endl;
        }
    } while(nb < min || max < nb);
    return nb;
}

Command readCommand(){
    do{
        cout << "# Enter command : ";
        string s;
        try{
            s= nvs::lineFromKbd<string>();
            std::transform(s.begin(), s.end(), s.begin(),
                           [](unsigned char c){ return std::tolower(c); });
        } catch(nvs::bad_string_convert e){
            s = "error";
        }
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

TypeOfCustom readCustom(){
    do{
        cout << "# Enter Type of custom between (linesAndColumns, nbBombs or densityBombs) : ";
        string s;
        try{
            s= nvs::lineFromKbd<string>();
            std::transform(s.begin(), s.end(), s.begin(),
                           [](unsigned char c){ return std::tolower(c); });
        } catch(nvs::bad_string_convert e){
            s = "error";
        }

        if(s == "linesandcolumns"){
            return LINESANDCOLUMNS;
        } else if(s == "nbbombs"){
            return NBBOMBS;
        } else if(s == "densitybombs"){
            return DENSITYBOMBS;
        } else {
            cout << "Wrong command! Enter one of the following : "<< endl;
            cout << "linesAndColumns, nbBombs or densityBombs." << endl;
        }
    } while (true); //No value returned
}

string readString(string const & msg){
    cout << msg << endl;
    return nvs::lineFromKbd<string>();
}

