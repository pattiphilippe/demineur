#include <iostream>

#define CATCH_CONFIG_RUNNER
#include "Libraries/catch.hpp"
#define RUN_TEST 0 //change this value
#define CONSOLE 0


#if RUN_TEST
int main(int argc, char* const argv [])
{
    Catch::Session().run(argc, argv);
}

#elif CONSOLE

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

    return 0;
}
#else
#include "GUI/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#endif
