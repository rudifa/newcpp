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

## Building

```bash
g++ -std=c++11 main.cpp -o )"
                                           << projectName << R"(
```

## Running

```bash
./)" << projectName
                                           << R"(
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
