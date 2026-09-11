#include <windows.h>

typedef int  (__stdcall* GetCurrentDesktopNumber_t)();
typedef void (__stdcall* GoToDesktopNumber_t)(int);

GetCurrentDesktopNumber_t GetCurrentDesktopNumber;
GoToDesktopNumber_t GoToDesktopNumber;

void ToggleDesktop()
{
    int current = GetCurrentDesktopNumber();

    if (current == 0)
        GoToDesktopNumber(1);
    else
        GoToDesktopNumber(0);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // Load DLL
    HMODULE dll = LoadLibraryW(L"VirtualDesktopAccessor.dll");
    if (!dll)
    {
        MessageBoxA(nullptr, "VirtualDesktopAccessor.dll not found!", "Error", MB_OK);
        return 1;
    }

    // Load functions
    GetCurrentDesktopNumber =
        (GetCurrentDesktopNumber_t)GetProcAddress(
            dll,
            "GetCurrentDesktopNumber");

    GoToDesktopNumber =
        (GoToDesktopNumber_t)GetProcAddress(
            dll,
            "GoToDesktopNumber");

    if (!GetCurrentDesktopNumber || !GoToDesktopNumber)
    {
        MessageBoxA(nullptr, "Failed to load DLL functions!", "Error", MB_OK);
        return 1;
    }

    // Register ( Wind + ` )
  RegisterHotKey( nullptr, 1, MOD_NOREPEAT | MOD_WIN | MOD_SHIFT, VK_OEM_3 );

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (msg.message == WM_HOTKEY)
        {
            ToggleDesktop();
        }
    }

    UnregisterHotKey(nullptr, 1);
    FreeLibrary(dll);

    return 0;
}