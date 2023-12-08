cmake_minimum_required(VERSION 3.0.0)
project(ConnectFourinator VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(ConnectFourinator main.cpp 
                src/ConnectFour/ConnectFour.h
                src/ConnectFour/ConnectFour.cpp
                src/ConnectFourBot/ConnectFourBot.h
                src/ConnectFourBot/ConnectFourBot.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
