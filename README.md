# Asteroid Shooter

An arcade-style asteroid shooter made with C++ and Raylib.

## Requirements

- CMake 3.16 or newer
- A C++20 compiler
- Raylib installed and discoverable by CMake

Install Raylib with your platform's package manager. For example, use `libraylib-dev` on Ubuntu/Debian, `raylib` with Homebrew on macOS, or `raylib:x64-windows` with vcpkg on Windows.

## Build

Run these commands from the project directory on Linux, macOS, or Windows:

```sh
cmake -S . -B cmake-build
cmake --build cmake-build --config Release
```

The executable is created in `cmake-build/` (or `cmake-build/Release/` with multi-configuration generators such as Visual Studio).

For vcpkg on Windows, configure with its toolchain file:

```powershell
cmake -S . -B cmake-build -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build cmake-build --config Release
```