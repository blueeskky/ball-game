# Ball Game

A simple cross-platform C++ application that demonstrates keyboard input handling.

## Features

- Cross-platform support (Windows, macOS, Linux)
- Non-blocking keyboard input detection
- Press Escape to exit

## Building

### Prerequisites

- C++ compiler (g++, clang, or MSVC)
- CMake (optional)

### On Windows

```bash
g++ -o main.exe main.cpp
./main.exe
```

### On macOS/Linux

```bash
g++ -o main main.cpp
./main
```

## Usage

1. Run the executable
2. The program displays "Hello, World!"
3. Press the **Escape key** to exit

## How it Works

The program uses platform-specific methods to detect keyboard input without blocking:

- **Windows**: Uses `_kbhit()` and `_getch()` from `conio.h`
- **Unix/Linux/macOS**: Uses `termios` with non-blocking file I/O

## License

MIT
