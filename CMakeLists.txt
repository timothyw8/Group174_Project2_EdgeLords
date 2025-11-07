cmake_minimum_required(VERSION 3.30)
project(Group174_Project2_EdgeLords)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)

FetchContent_MakeAvailable(SFML)

add_executable(Group174_Project2_EdgeLords
        main.cpp
        Graph.h
        Graph.cpp
        Dijkstra.cpp
        BellmanFord.cpp
        gui.cpp
        gui.h
        gui.h)

target_compile_features(Group174_Project2_EdgeLords PRIVATE cxx_std_17)
target_link_libraries(Group174_Project2_EdgeLords PRIVATE sfml-graphics sfml-system sfml-window)
