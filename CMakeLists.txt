cmake_minimum_required(VERSION 3.13)
project(tp2)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -std=c++11 -pedantic -pthread")

file(GLOB source
        "*.cpp"
        "*.h"
        )

add_executable(tp2 ${source} Parser.cpp Parser.h Productor.cpp Productor.h HeapProtegido.cpp HeapProtegido.h InterpreteConPrioridad.cpp InterpreteConPrioridad.h Comparador.cpp Comparador.h Thread.cpp Thread.h Consumidor.cpp Consumidor.h ThreadPool.cpp ThreadPool.h)

target_link_libraries(tp2 pthread)
