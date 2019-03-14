project(test1)
cmake_minimum_required(VERSION 2.8)

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

# Find SDL2
find_package(SDL2 REQUIRED)

# Add global definitions
add_definitions("-Wall")
include_directories(${SDL2_INCLUDE_DIR})

file(GLOB test1_SRC
    "*.h"
    "*.cpp"
)

add_executable(test1 ${test1_SRC})
# add_executable(test1 main.cpp Game.cpp)
install(TARGETS test1 DESTINATION bin)
target_link_libraries(test1 ${SDL2_LIBRARIES})
