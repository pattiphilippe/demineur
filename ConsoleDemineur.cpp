#include <iostream>
#include <View/ConsoleView.h>

using namespace std;

int main()
{
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
