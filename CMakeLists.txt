cmake_minimum_required(VERSION 3.10)
project(SDL_Tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDL_Tetris main.cpp src/TetrisBlock.cpp src/TetrisBlock.h src/input_handling.cpp src/input.handling.h src/Board.cpp src/Board.h src/GlobalConsts.h)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
