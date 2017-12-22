cmake_minimum_required(VERSION 3.6)
project(projekt_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Programista.cpp Programista.h Pracownik.cpp Pracownik.h Student.cpp Student.h Konto.cpp Konto.h Kasa.cpp Czlowiek.cpp Czlowiek.h)
add_executable(projekt_cpp ${SOURCE_FILES})