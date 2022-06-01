cmake_minimum_required(VERSION 3.22)
project(disease_simulation)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(disease_simulation main.cpp backend/Board.cpp backend/Board.h backend/Person.cpp backend/Person.h backend/State.h
        backend/Disease.cpp backend/Disease.h backend/Simulation.h backend/Simulation.cpp
        frontend/Window.cpp frontend/Window.h)

target_link_libraries(disease_simulation
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

