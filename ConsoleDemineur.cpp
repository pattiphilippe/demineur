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

    view.helpMenu();

    bool canStart = false ;

    while(!canStart){

        view.commandCheck(cmd);
        if(view.getController().getGameState() == init){
            canStart = true ;
        }
    }

    view.help();

    while(cmd != EXIT){

        view.displayBoard();
        if(view.getController().getGame().getGameState() == win){
            cout << "Congratualation you won !" << endl;
            break;
        }else if(view.getController().getGame().getGameState() == lose){
            cout << "Boom !!! You exploded :/ " << endl;
            break;
        }

        cmd = readCommand();

        switch(cmd){
            case MARK:
                view.action("mark");
                break;
            case REVEAL:
                view.action("reveal");
                break;
            case EXIT:
                view.displayExit();
                break;
            case HELP:
                view.help();
                break;
            default:
                view.displayError();
                view.help();
                break;
        }
    }
    return 0;
}

#endif
