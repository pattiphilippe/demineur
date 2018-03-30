
#include "Tests/maintests.h"
#include <iostream>

#if !RUN_TESTS
#include "View/ConsoleView.h"
using namespace std;

int main()
{
    Controller ctrl {};
    ctrl.saveScore("philippe");

    //TODO ==> Main bidon, à bien refaire lorsque les scores fonctionneront et que le projet compilera

    ConsoleView view = ConsoleView();
    bool canStart = false ;

    while(!canStart){
        canStart = view.displayStart();
    }


    while(view.getController().getGameState() == inProgress){
        view.displayBoard();
        view.displayChoices();
    }

    if(view.getController().getGame().getGameState() == win){
        cout << "Congratualation you won !" << endl;
    }else{
        cout << "Boom !!! You exploded :/ " << endl;
    }

    return 0;
}

#endif
