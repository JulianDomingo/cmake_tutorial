# 3 = major version, 5 = minor version, 1 = patch version
cmake_minimum_required(VERSION 3.5.1)

# Sets project name
project(hello_world)

# Requests an executable of nmae 'hello_world' is built using the source file
# 'hello_world.cc'
add_executable(hello_world hello_world.cc)
