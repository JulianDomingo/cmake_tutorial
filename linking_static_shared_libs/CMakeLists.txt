cmake_minimum_required(VERSION 3.1)
project(linking_so_a_libs)

file(GLOB SOURCE "src/*.cc")

# Add shared library to PROJECT_LINK_LIBS
set(PROJECT_LINK_LIBS libstudent.so)
# Reference the build directory of where the libstudent.so file lies
link_directories(../shared_library/build)

# Add static library to PROJECT_LINK_LIBS
#set(PROJECT_LINK_LIBS libstudent.a)
# Reference the build directory of where the libstudent.a file lies
#link_directories(../static_library/build)

# MUST link the relative file path to the header file of the linked library
include_directories(../shared_library/include)
add_executable(linked_so_a_libs ${SOURCE})

# Finally, link the shared + static library to the newly created executable
target_link_libraries(linked_so_a_libs ${PROJECT_LINK_LIBS})
