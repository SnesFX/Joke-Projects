#include <stdio.h>
#include <windows.h>

int main() {
    // Get the current user token handle
    HANDLE hToken;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
        printf("OpenProcessToken() failed, error code: %d\n", GetLastError());
        return 1;
    }

    // Enable the SE_SHUTDOWN_NAME privilege
    TOKEN_PRIVILEGES tp;
    tp.PrivilegeCount = 1;
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    if (!LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tp.Privileges[0].Luid)) {
        printf("LookupPrivilegeValue() failed, error code: %d\n", GetLastError());
        return 1;
    }

    if (!AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL)) {
        printf("AdjustTokenPrivileges() failed, error code: %d\n", GetLastError());
        return 1;
    }

    // Shut down the system and force all applications to close
    if (!ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0)) {
        printf("ExitWindowsEx() failed, error code: %d\n", GetLastError());
        return 1;
    }

    return 0;
}
