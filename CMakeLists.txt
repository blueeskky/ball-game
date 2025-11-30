cmake_minimum_required(VERSION 3.10)
project(BallGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ball_game main.cpp)

# Platform-specific settings
if(WIN32)
    target_link_libraries(ball_game PRIVATE ws2_32)
endif()
