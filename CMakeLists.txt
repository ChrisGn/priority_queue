cmake_minimum_required(VERSION 3.16.0)
set(This priority_queue)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

enable_testing()
include_directories(include)
include_directories(test)
add_subdirectory(googletest)

set(SOURCES
    src/schueler.cpp
    src/priorities.cpp    
    )
set(HEADERS
    include/schueler.h
    include/priorities.h  
    )

add_library(${This}_lib STATIC ${SOURCES} ${HEADERS})

add_subdirectory(test)

set(MAIN_SRCS src/main.cpp)
add_executable(${This}_bin ${MAIN_SRCS})

target_link_libraries(${This}_bin ${This}_lib)