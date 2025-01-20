/*
Copyright © 2025 Rudolf Farkas @rudifa rudi.farkas@gmail.com
*/

#include "templates.hpp"
#include "filewriter.hpp"
#include <filesystem>

namespace fs = std::filesystem;


void Templates::createReadme(const std::string &projectName)
{
    createFile(projectName + "/README.md") << R"(# )" << projectName << R"(

A C++ project.

## Simple build

```bash
g++ -std=c++20 main.cpp -o )"
                                           << projectName << R"(
```

## Run

```bash
./)" << projectName << R"(
```

## CMake build

```bash
mkdir build
cd build
cmake ..
make
```
)";
}

void Templates::createMainCpp(const std::string &projectName)
{
    createFile(projectName + "/main.cpp") << R"(#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
})";
}

void Templates::createGitignore(const std::string &projectName)
{
    createFile(projectName + "/.gitignore") << R"(# Prerequisites
# Compiled object files
*.o
*.obj

# Compiled dynamic libraries
*.so
*.dll

# Compiled static libraries
*.a
*.lib

# Executables
*.exe
*.out
*.app

# Build directories
/build/
/bin/
/obj/

# IDE-specific files
*.layout
*.depend

# Precompiled headers
*.gch
*.pch

# macOS
.DS_Store
)"
                                            << projectName << "\n";
}

void Templates::createCMakeLists(const std::string &projectName)
{
    createFile(projectName + "/CMakeLists.txt") << R"(cmake_minimum_required(VERSION 3.15.0)
project()" << projectName << R"()

set(CMAKE_CXX_STANDARD 20)

add_executable()" << projectName << R"( main.cpp)

# Specify the installation directory
install(TARGETS )" << projectName << R"( DESTINATION bin)
)";
}
