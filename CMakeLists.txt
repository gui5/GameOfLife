cmake_minimum_required(VERSION 3.16)

project(GOF VERSION 0.0.0.1
                        DESCRIPTION "Another Game of Life Implementation"
                        LANGUAGES CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED) 

find_package(SFML COMPONENTS REQUIRED system window graphics network audio)

add_executable(gof src/main.cpp include/fps.hpp)
target_include_directories(gof PRIVATE "include")

set_target_properties(gof PROPERTIES
                          CXX_STANDARD 17
                          CXX_STANDARD_REQUIRED YES
                          CXX_EXTENSIONS NO)


target_link_libraries(gof PUBLIC Threads::Threads  X11 FLAC UDev OpenAL
sfml-system sfml-window sfml-network sfml-graphics freetype)

