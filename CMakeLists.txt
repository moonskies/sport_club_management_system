cmake_minimum_required(VERSION 3.10)

# Set project name and C++ standard
project(SportsManagement)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(domain repo controller)

# Collect all source files
set(SOURCES
        main.cpp
        domain/User.cpp
        domain/Equipment.cpp
        domain/Field.cpp
        repository/UserRepository.cpp
        repository/FieldRepository.cpp
        repository/EquipmentRepository.cpp
        controller/UserController.cpp

)

# Create the executable
add_executable(SportsManagement ${SOURCES})
