project(ExampleMooreFSM)

set(FSM_DIR ${CMAKE_SOURCE_DIR}/src)
set(SOURCES
	main.c
	${FSM_DIR}/fsm.c
	${FSM_DIR}/fsm.h
)

add_executable(ExampleMooreFSM ${SOURCES})

target_compile_definitions(ExampleMooreFSM PRIVATE BUILD_MOORE)
target_include_directories(ExampleMooreFSM PUBLIC ${FSM_DIR})
