/*
Copyright © 2025 Rudolf Farkas @rudifa rudi.farkas@gmail.com
*/

#ifndef FILEWRITER_HPP
#define FILEWRITER_HPP

#include <fstream>
#include <string>

class FileWriter {
public:
    FileWriter(const std::string &filename);
    ~FileWriter();
    template <typename T>
    FileWriter &operator<<(const T &data);

private:
    std::ofstream file;
};

template <typename T>
FileWriter &FileWriter::operator<<(const T &data) {
    file << data;
    return *this;
}

#endif // FILEWRITER_HPP
