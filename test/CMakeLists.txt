cmake_minimum_required(VERSION 3.16.0)


set(This Unit_Test)

set(Sources
	schueler_Test.cpp
	priorities_Test.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
	gtest_main
	priority_queue_lib
)

add_test(
	NAME ${This}
	COMMAND ${This}
)