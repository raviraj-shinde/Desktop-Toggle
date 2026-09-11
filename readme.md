# Desktop Toggle App

- Aim: Toggle between Desktop 1 and Desktop 2 using the same button

<br/>

---

### `Write a small C++ application that:`

```text

1. Start application.
2. Register a global hotkey (e.g., F13 or F24).
3. Wait for the hotkey to be pressed.
4. Get the current virtual desktop.
5. If Desktop 1 → Switch to Desktop 2.
6. Else → Switch to Desktop 1.
7. Repeat until the application exits.
```

<br/>

---

# To create .exe open terminal and 
```text
g++ main.cpp -o DesktopToggle.exe -mwindows
```


<br/>

---
---
---

### Other

| Command / Step                                | Purpose                                                                                                                                                                              |
| --------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Install MSYS2**                             | Installs a Unix-like development environment and package manager for Windows. It provides tools such as `pacman` and allows you to install compilers and other development packages. |
| `pacman -Syu`                                 | Updates the MSYS2 package database and upgrades all installed packages to the latest versions.                                                                                       |
| `pacman -Su`                                  | Completes the upgrade after restarting MSYS2 (required if the first update updates the package manager itself).                                                                      |
| `pacman -S mingw-w64-ucrt-x86_64-gcc`         | Installs the **GCC C/C++ compiler** (g++), linker, and related tools for 64-bit Windows using the UCRT runtime.                                                                      |
| `g++ --version`                               | Verifies that the compiler is installed and accessible. Displays the compiler version.                                                                                               |
| **Add `C:\msys64\ucrt64\bin` to PATH**        | Makes Windows able to find `g++.exe` from any terminal (PowerShell, CMD, VS Code), instead of only from the MSYS2 terminal.                                                          |
| `g++ main.cpp -o DesktopToggle.exe -mwindows` | Compiles `main.cpp` into an executable named `DesktopToggle.exe`. The `-mwindows` option builds it as a **GUI Windows application**, so no console window appears when it runs.      |
