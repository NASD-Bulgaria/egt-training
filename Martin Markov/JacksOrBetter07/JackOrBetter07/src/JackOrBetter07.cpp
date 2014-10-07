//============================================================================
// Name        : JackOrBetter07.cpp
// Author      : Martin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Application.h"


int main(int argc, char* args[] )

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
