cmake_minimum_required(VERSION 3.22)

project(CuteFSM)

add_subdirectory(src)

add_subdirectory(examples/hybrid-fsm)
add_subdirectory(examples/mealy-fsm)
add_subdirectory(examples/moore-fsm)
