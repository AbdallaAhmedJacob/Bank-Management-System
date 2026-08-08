#include "clsLoginScreen.h"
#include "Global.h"

#include <string>
#include <vector>

int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }

    return 0;
}

