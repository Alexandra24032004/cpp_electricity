cmake_minimum_required(VERSION 3.14)
project(cpp_electricity)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_BUILD_TYPE Release)

set(SOURCES
	point.cpp
	object.cpp
	fields.cpp
	visual.cpp
	project.cpp
	parse.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)


find_package(symengine REQUIRED)
target_link_libraries(${PROJECT_NAME} symengine::symengine)
