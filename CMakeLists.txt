cmake_minimum_required(VERSION 3.16.0)
project(p_que)

include_directories(include)

# set(SCHUELER_SRCS src/schueler.cpp )
# set(PRIORITIES_SRCS src/priorities.cpp )

# build library (sources and headers in alphabetical order)
set(P_QUE_LIB_SOURCES
    src/schueler.cpp
    src/priorities.cpp    
    )
set(P_QUE_LIB_HEADERS
    include/schueler.h
    include/priorities.h  
    )

add_library(${PROJECT_NAME}_lib ${P_QUE_LIB_SOURCES} ${P_QUE_LIB_HEADERS})

set(MAIN_SRCS src/main.cpp)
add_executable(${PROJECT_NAME}_bin ${MAIN_SRCS})

target_link_libraries(${PROJECT_NAME}_bin ${PROJECT_NAME}_lib)