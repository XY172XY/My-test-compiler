cmake_minimum_required(VERSION 3.31)
project(Pi)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

file(GLOB_RECURSE SOURCES "token/*.cpp" "lexer/*.cpp" "parser/*.cpp" "json/*.cpp" "ast/*.cpp" "token/*.h" "lexer/*.h" "parser/*.h" "json/*.h" "ast/*.h")

add_executable(token ${SOURCES} token.cpp)
add_executable(ast ${SOURCES} ast.cpp
        ast/expression_statement.cpp)

