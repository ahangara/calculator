file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_library(printer STATIC ${SOURCE_FILES})
