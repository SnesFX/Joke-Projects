#include <Windows.h>
#include <Ntstatus.h>

int BlueScreen()
{
    BOOLEAN bl;
    LONG Response;

    // Adjust privilege to allow shutting down the system
    if (RtlAdjustPrivilege(19, TRUE, FALSE, &bl) == 0)
    {
        // Raise hard error to trigger a blue screen
        NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response);
    }

    return 0;
}

int main()
{
    BlueScreen();
    return 0;
}
