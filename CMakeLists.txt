cmake_minimum_required(VERSION 3.15.0)
project(newcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(newcpp src/main.cpp src/templates.cpp src/filewriter.cpp)

# Specify the installation directory
# This will install to /usr/local/bin by default
# You can change this path as needed by running:
# cmake -DCMAKE_INSTALL_PREFIX=/your/custom/path ..
install(TARGETS newcpp DESTINATION bin)
