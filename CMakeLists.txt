cmake_minimum_required(VERSION 3.9.1)

project(GoBang_Battle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(GoBang_Battle SHARED src/board.cpp src/strategy.cpp src/robot1.cpp src/player.cpp src/game.cpp   ) 

add_executable(main main.cpp)
target_link_libraries(main GoBang_Battle)
