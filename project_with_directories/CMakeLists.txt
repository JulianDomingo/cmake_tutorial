# 3.0 for modern, target-based CMake. 3.1 for use of CXX_STANDARD in targets.
cmake_minimum_required(VERSION 3.1)

project(multiple_dirs)

# Bring in headers (student.h) into project
include_directories(include)

# Can manually add sources using set() command
# set(SOURCES src/main.cc src/student.cc)

# However, the file(GLOB...) allows for wildcard file addition
file(GLOB SOURCES "src/*.cc")

# Using the SOURCES variable rather than explicit reference to each source file.
add_executable(student ${SOURCES})
