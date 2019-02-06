cmake_minimum_required(VERSION 3.1)
project(shared_lib)

# Sets the build type to a release build (production)
set(CMAKE_BUILD_TYPE Release)

include_directories(include)

file(GLOB SOURCES "src/*.cc")

# As opposed to the 'add_executable' function, we use 'add_library' which
# generates the shared library .so files from source files, as opposed to a
# binary executable.
# 'student' will be the named of the shared library directory.
add_library(student STATIC ${SOURCES})

# Set location for lib installation. In this example, we use /usr/lib. "student"
# is the target executable, which will be added to destination /usr/lib.
install(TARGETS student DESTINATION /usr/lib)
