#include "SingleThreadedApplication.h"
#include "MultiThreadApplication.h"

int main()
{
    //SingleThreadedApplication app;
    MultiThreadApplication app;

    while (true)
    {
        app.Tick();
    }

    return 0;
}