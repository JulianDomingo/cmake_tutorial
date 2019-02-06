#### CMake
* Cross-platform makefile generator (automatically generates makefiles for a
    project). Makefiles compile your project through **make**

#### Project Structuring
* Partition project to have **build/, includue/, and src/** directories
    * **build/** is empty, which stores the final binary executable + temporary
        files required for the build.
* To place CMake output within the **build/** directory, **cd** into **build/**
    and run **cmake ..** to reference the CMakeLists.txt file.

#### Shared Library Files (.so)
* To install a shared library system-wide, include an install() function within
    CMakeLists.txt specifying the system-wide location (i.e. **/usr/lib/**) and
    run **sudo make install** within the **build/** directory


#### Tips
* Don't forget to **exclude** the **build/** directory from version control by adding a
    **.gitignore** file at the same level as the top-level directories of the
    project
* Make sure to **rerun cmake** when updating project source / header files

