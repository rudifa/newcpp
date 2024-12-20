/*
Copyright © 2024 Rudolf Farkas @rudifa rudi.farkas@gmail.com
*/

#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>
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

void createReadme(const std::string& projectName) {
    std::ofstream readme(projectName + "/README.md");
    readme << "# " << projectName << "\n\n"
           << "A C++ project.\n\n"
           << "## Building\n\n"
           << "```bash\n"
           << "g++ main.cpp -o " << projectName << "\n"
           << "```\n\n"
           << "## Running\n\n"
           << "```bash\n"
           << "./" << projectName << "\n"
           << "```\n";
}

void createMainCpp(const std::string& projectName) {
    std::ofstream main(projectName + "/main.cpp");
    main << "#include <iostream>\n\n"
         << "int main() {\n"
         << "    std::cout << \"Hello, World!\" << std::endl;\n"
         << "    return 0;\n"
         << "}\n";
}

void createGitignore(const std::string& projectName) {
    std::ofstream gitignore(projectName + "/.gitignore");
    gitignore << "# Prerequisites\n"
              << "*.d\n\n"
              << "# Compiled Object files\n"
              << "*.o\n"
              << "*.obj\n\n"
              << "# Executables\n"
              << "*.exe\n"
              << "*.out\n"
              << projectName << "\n";
}

void initGitRepo(const std::string& projectName) {
    std::string cmd = "cd " + projectName + " && git init && git add . && git commit -m \"Initial commit\"";
    system(cmd.c_str());
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <project-name>\n";
        return 1;
    }

    std::string projectName = argv[1];

    if (!createDirectory(projectName)) {
        return 1;
    }

    try {
        createReadme(projectName);
        createMainCpp(projectName);
        createGitignore(projectName);
        initGitRepo(projectName);

        std::cout << "Created new C++ project '" << projectName << "'\n";
        std::cout << "cd into '" << projectName << "' to get started\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
