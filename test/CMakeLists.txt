cmake_minimum_required(VERSION 3.16.0)

include_directories(${gtest_SOURCE_DIR}/include)
# include_directories(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})

set(test_sources
schueler_Test.cpp
)


add_executable(sample_tests ${test_sources})
target_link_libraries(sample_tests gtest_main)
# target_link_libraries(Partitioner ${Boost_LIBRARIES} gtest)