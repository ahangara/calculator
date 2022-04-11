cmake_minimum_required(VERSION 3.10)
project(calculator_multi_level VERSION 1.0)

## add all cpp file need to be compiled
# set(SOURCE_FILES main/src/main.cpp)

## or finds all cpp files recursively under main/src dir
file(GLOB_RECURSE SOURCE_FILES main/src/*.cpp)

## To include external library
# find_library(MY_LIB my_lib PATH /custom_path/lib)
# target_link_libraries(${PROJECT_NAME} PUBLIC ${MY_LIB})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
add_subdirectory(adder)
add_subdirectory(divider)
add_subdirectory(printer)




# include_directories(adder/inc divider/inc printer/inc)
target_include_directories(${PROJECT_NAME} PUBLIC adder/inc divider/inc printer/inc)


target_link_directories(${PROJECT_NAME} PRIVATE adder divider printer)
target_link_libraries(${PROJECT_NAME} PRIVATE adder divider printer)


if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    set(CMAKE_BUILD_TYPE Release CACHE STRING
	    "Type of build, options are: Debug, Release" FORCE)
endif()


add_compile_options(-Wall -Wextra -pedantic -Werror -lstdc++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "-g2 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

string(TOUPPER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE_UCASE)
message(STATUS ">> C++ Compile Flags (for ${CMAKE_BUILD_TYPE}): \
  ${CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE_UCASE}}")

