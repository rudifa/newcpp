cmake_minimum_required(VERSION 3.10)
project(newcpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(newcpp main.cpp)

# Specify the installation directory
# This will install to /usr/local/bin by default
# You can change this path as needed by running:
# cmake -DCMAKE_INSTALL_PREFIX=/your/custom/path ..
install(TARGETS newcpp DESTINATION bin)
