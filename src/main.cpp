#include "application_main.h"

int main(int argc, char* argv[])
{
    ApplicationMain app;

    app.Init();

    app.mainLoop();

    return 0;
}
