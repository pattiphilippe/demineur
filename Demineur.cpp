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

    return 0;
}

#endif
