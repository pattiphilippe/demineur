#include <iostream>

#define CATCH_CONFIG_RUNNER
#include "Libraries/catch.hpp"
#define RUN_TEST 0 //change this value


#if RUN_TEST
int main(int argc, char* const argv [])
{
    Catch::Session().run(argc, argv);
}

#else

#include "View/consoleread.h"
#include "View/ConsoleView.h"
using namespace std;

int main()
{
    ConsoleView view = ConsoleView();

    Command cmd {HELP};
    while(cmd != EXIT){
        cmd = readCommand();
        switch(cmd){
        case START:
            cout << "start a new game" << endl;
            view.displayStart();
        }
    }

    /*
    bool canStart = false ;

    while(!canStart){
        canStart = view.displayStart();
    }


    while(view.getController().getGameState() == inProgress ||view.getController().getGameState() == init  ){
        view.displayBoard();
        view.displayChoices();
    }

    if(view.getController().getGame().getGameState() == win){
        cout << "Congratualation you won !" << endl;
    }else{
        cout << "Boom !!! You exploded :/ " << endl;
    }
    */

    return 0;
}

#endif
