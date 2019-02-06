### CMake
* Cross-platform makefile generator (automatically generates makefiles for a
    project). Makefiles compile your project through **make**

#### Project Structuring
* Partition project to have **build/, includue/, and src/** directories
    * **build/** is empty, which stores the final binary executable + temporary
        files required for the build.
* To place CMake output within the **build/** directory, **cd** into **build/**
    and run **cmake ..** to reference the CMakeLists.txt file.

#### Shared Object Libraries (.so)
* Either:
    * Dynamically linked at run time: libraries must be available during compile / link phase. Not included into executable, but tied to execution
    * Dynamically loaded / unloaded and linked during execution using dynamic
        linking loader system functions

* To install a shared library system-wide, include an install() function within
    CMakeLists.txt specifying the system-wide location (i.e. **/usr/lib/**) and
    run **sudo make install** within the **build/** directory

#### Static Library Files (.a)
* Created at compile time to contain all the code relating to the library.
    Essentially, it makes copies of any dependency code, including those in
    other libraries / projects.
* Consist of object code wich is linked with / becomes part of project
* Typically larger in file size compared to shared libraries, meaning slower compile time, but at
    the benefit of faster run time loading costs / less platform dependent.
* **Unless certain you require a static lib**, use a shared library.
Use **nm -C <shared_lib>.so** command to determine symbols / types in object files and binaries. 
**T** is code, **U** is undefined, **R** is read-only data:
```zsh
λ ~/git/cmake_tutorial/static_library/build/ master* nm -C libstudent.a

student.cc.o:
                 U __cxa_atexit
                 U __dso_handle
0000000000000000 t _GLOBAL__sub_I__Z5test1v
0000000000000000 T test1()
0000000000000080 T test2()
                 U std::ctype<char>::_M_widen_init() const
0000000000000000 W std::ctype<char>::do_widen(char) const
                 U std::ostream::put(char)
                 U std::ostream::flush()
                 U std::ios_base::Init::Init()
                 U std::ios_base::Init::~Init()
                 U std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
                 U std::__throw_bad_cast()
                 U std::cout
0000000000000000 b std::__ioinit
```

Use **ar -t <static_lib>.a** to view all members of a static library:
```zsh
λ ~/git/cmake_tutorial/static_library/build/ master* ar -t libstudent.a 
student.cc.o
```

#### Using Static and Shared Libraries in Other Projects
* When creating the CMakeLists.txt, must choose **either** the shared or static
    library, should both exist.
* Ensure the include_directories() includes the header file of the linked
    library

### Tips
* Don't forget to **exclude** the **build/** directory from version control by adding a
    **.gitignore** file at the same level as the top-level directories of the
    project
* Make sure to **rerun cmake** when updating project source / header files
