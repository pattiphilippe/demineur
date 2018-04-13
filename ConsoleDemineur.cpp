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
#include "Controller.h"
using namespace std;

int main()
{

    Game game{};

    ConsoleView view {game};
    Controller ctrl{game, view};
    ctrl.run();

/*
    Command cmd {HELP};

    view.helpMenu();

    bool canStart = false ;

    while(!canStart){

        view.commandCheck(cmd);
        if(game.getGameState() == init){
            canStart = true ;
        }
    }

    view.help();

    while(cmd != EXIT){

        view.displayBoard();
        if(game.getGameState() == win){
            cout << "Congratualation you won !" << endl;
            break;
        }else if(ctrl.getGame().getGameState() == lose){
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
    }*/
    return 0;
}

#endif
