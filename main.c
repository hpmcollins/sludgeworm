#include <windows.h>
#include <stdio.h>

// world's dumbest app

// windows shit
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    // changed this to 256. apparently this is better! yay!!!!!
    char cmd[256] = "alacritty --command nvim ";
    strcat_s(cmd, sizeof(cmd), lpCmdLine);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    si.cb = sizeof(si);

    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;

    // Create the process
    if (!CreateProcessA(
            NULL,
            cmd,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi))
    {
        MessageBoxA(NULL, "Failed to launch Alacritty!", "Error", MB_ICONERROR);
        return 1;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
