#include "Application.h"

int main()
{
    Application app;

    if(app.Init())
    {
        app.MainLoop();
    }
    else
    {
        // Error
    }

    return 0;
}
