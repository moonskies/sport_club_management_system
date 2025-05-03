cmake_minimum_required(VERSION 3.30)
project(oop_sport)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop_sport main.cpp
        controller/UserController.cpp
        repository/EquipmentRepository.cpp
        repository/FieldRepository.cpp
        repository/UserRepository.cpp
        domain/Equipment.cpp
        domain/Field.cpp
        domain/User.cpp)
