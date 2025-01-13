/*
Copyright © 2025 Rudolf Farkas @rudifa rudi.farkas@gmail.com
*/

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include "filewriter.hpp"

class Templates
{
public:
    static void createReadme(const std::string &projectName);
    static void createMainCpp(const std::string &projectName);
    static void createGitignore(const std::string &projectName);

private:
    static FileWriter createFile(const std::string &filename);
};

#endif // TEMPLATES_HPP
