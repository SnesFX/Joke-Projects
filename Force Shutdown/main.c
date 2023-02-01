#include <windows.h>
#include <stdio.h>

int main()
{
    // Initiate system shutdown
    if (!ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, SHTDN_REASON_MAJOR_OPERATINGSYSTEM | SHTDN_REASON_MINOR_UPGRADE | SHTDN_REASON_FLAG_PLANNED)) {
        printf("Shutdown failed");
    }

    return 0;
}
