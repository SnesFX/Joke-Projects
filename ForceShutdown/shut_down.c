#include <stdio.h>
#include <windows.h>

int main()
{
    printf("Shutting down the computer in 5 seconds...\n");
    Sleep(5000);
    ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0);
    return 0;
}
