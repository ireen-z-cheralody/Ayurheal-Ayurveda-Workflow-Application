# Cmake is a build system generator
# Reads instructions about project
# Figures out how to compile & link executable
# Generates instructions for a compiler & linker to build the project

# Require CMake version 3.21 or higher
cmake_minimum_required(VERSION 3.21)

# Declare the project name and specify that it uses C++
# Ayurheal is the project name 
# Languages CXX enables C++ support
project(Ayurheal LANGUAGES CXX)

# Set the C++ language standard to C++17 and make it required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Qt 6 installation and its Widgets component 
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Apply Qt's standard config and define an executable target 
# main.cpp is the source file for the executable
qt_standard_project_setup()
qt_add_executable(Ayurheal
    main.cpp
)

# Link the Qt Widgets library to our executable 
target_link_libraries(Ayurheal PRIVATE Qt6::Widgets)
