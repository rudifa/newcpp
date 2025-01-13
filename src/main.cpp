/*
Copyright © 2025 Rudolf Farkas @rudifa rudi.farkas@gmail.com
*/

#include "templates.hpp"

#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

bool createDirectory(const std::string& projectName) {
    try {
        if (fs::exists(projectName)) {
            std::cout << "Directory '" << projectName << "' already exists. Removing contents...\n";
            for (const auto& entry : fs::directory_iterator(projectName)) {
                fs::remove_all(entry.path());
            }
        } else {
            fs::create_directory(projectName);
        }
        return true;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error managing directory: " << e.what() << '\n';
        return false;
    }
}

void initGitRepo(const std::string& projectName) {
    std::string cmd = "cd " + projectName + " && git init && git add . && git commit -m \"Initial commit\"";
    system(cmd.c_str());
}

int main(int argc, char* const argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <project-name>\n";
        return 1;
    }

    std::string projectName = argv[1];

    if (!createDirectory(projectName)) {
        return 1;
    }

    try {
        Templates::createReadme(projectName);
        Templates::createMainCpp(projectName);
        Templates::createGitignore(projectName);

        initGitRepo(projectName);

        std::cout << "Created new C++ project '" << projectName << "' and initialized git repository '" << projectName << "/.git'\n";
        std::cout << "cd into '" << projectName << "' to get started\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
