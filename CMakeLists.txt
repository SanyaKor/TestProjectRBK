cmake_minimum_required(VERSION 3.23)
project(TestProjectRBK)

set(CMAKE_CXX_STANDARD 20)



file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tests.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(TestProjectRBK main.cpp)
