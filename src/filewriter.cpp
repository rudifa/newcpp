/*
Copyright © 2025 Rudolf Farkas @rudifa rudi.farkas@gmail.com
*/

#include "filewriter.hpp"
#include "templates.hpp"
#include <filesystem>

namespace fs = std::filesystem;
FileWriter::FileWriter(const std::string &filename) : file(filename) {}

FileWriter::~FileWriter()
{
    if (file.is_open())
    {
        file.close();
    }
}

FileWriter Templates::createFile(const std::string &filename)
{
    return FileWriter(filename);
}
