#include "application_main.h"

int main(int argc, char* argv[])
{
    ApplicationMain app;

    if (!app.Init()) {
        return -1;
    }

    app.mainLoop();

    return 0;
}
