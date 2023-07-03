project(ExampleMealyFSM)

set(FSM_DIR ${CMAKE_SOURCE_DIR}/src)
set(SOURCES
	main.c
	${FSM_DIR}/fsm.c
	${FSM_DIR}/fsm.h
)

add_executable(ExampleMealyFSM ${SOURCES})

target_compile_definitions(ExampleMealyFSM PRIVATE BUILD_MEALY)
target_include_directories(ExampleMealyFSM PUBLIC ${FSM_DIR})
