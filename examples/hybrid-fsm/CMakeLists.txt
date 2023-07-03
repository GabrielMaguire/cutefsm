project(ExampleHybridFSM)

set(FSM_DIR ${CMAKE_SOURCE_DIR}/src)
set(SOURCES
	main.c
	${FSM_DIR}/fsm.c
	${FSM_DIR}/fsm.h
)

add_executable(ExampleHybridFSM ${SOURCES})

target_compile_definitions(ExampleHybridFSM PRIVATE BUILD_MOORE BUILD_MEALY)
target_include_directories(ExampleHybridFSM PUBLIC ${FSM_DIR})
